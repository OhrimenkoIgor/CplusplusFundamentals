#if defined __linux__

#include <iostream>

#include <fstream>
#include <iomanip>
#include <vector>

#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>

#include "FileUtils.h"
#include "LinuxFileUtils.h"
#include "LinuxFileList.h"
#include "LinuxThreadPool.h"

//structure for thread pool work callback argument
struct LinuxFileList::CallbackParameter {
	std::wstring file_name; //filename
	pthread_cond_t* hevent; //event to trigger
	FileInfo * p_file_info; //pointer to file_info in map to fill
	bool done; //set true when finished to fill all fields

	CallbackParameter() {
		done = false;
	}

};

//structure for thread pool wait callback argument
struct LinuxFileList::SumsCallbackParameter {
	LinuxFileList::CallbackParameter * arr; //pointer to file_infos for printing to file
	size_t size; //size of container
	pthread_cond_t* hevent; //event to set to wait
	pthread_mutex_t* hmutex; //mutex for synchronization of file write
	unsigned int item_to_write; //current number of file_info from container to write
	std::wofstream * file; //pointer to file output stream to write
};

void* LinuxFileList::fill_file_info_callback(void* Parameter) {
	CallbackParameter * param = reinterpret_cast<CallbackParameter *>(Parameter);

	struct stat attrib;
	struct tm modtime;

	//retreive size and creation date
	int s = stat(FileUtils::wstr2str(param->p_file_info->path_).c_str(),
			&attrib);
	if (s == -1) {
		perror("stat");
		exit (EXIT_FAILURE);
	}
	localtime_r(&(attrib.st_mtim.tv_sec), &modtime);
	param->p_file_info->time_ = LinuxFileUtils::tm2wstr(modtime);
	param->p_file_info->size_ = attrib.st_size;

	//count check sum
	param->p_file_info->sum_ = FileUtils::count_sum(param->p_file_info->path_);

	//done
	param->done = true;

	//trigger event to call file write callback
	s = pthread_cond_signal(param->hevent);
	if (s != 0) {
		errno = s;
		perror("pthread_cond_signal");
		exit (EXIT_FAILURE);
	}

	return NULL;
}

void* LinuxFileList::wait_for_sums_thread(void* Parameter) {
	int s;
	SumsCallbackParameter * param =
			reinterpret_cast<SumsCallbackParameter *>(Parameter);

	while (param->item_to_write < param->size) {

		s = pthread_mutex_lock(param->hmutex);
		if (s != 0) {
			errno = s;
			perror("pthread_mutex_lock");
			exit (EXIT_FAILURE);
		}

		//
		if (!param->arr[param->item_to_write].done) {
			s = pthread_cond_wait(param->hevent, param->hmutex);
			if (s != 0) {
				errno = s;
				perror("pthread_cond_wait");
				exit (EXIT_FAILURE);
			}
		}

		//write info about all files, that are processed by the moment, but info is not written
		//stop on non-processed file
		while (param->item_to_write < param->size
				&& param->arr[param->item_to_write].done) {
			//capture mutex

			//one formatted wstring per file info structure
			(*param->file) << std::setw(128) << std::left
					<< param->arr[param->item_to_write].file_name
					<< std::setw(20)
					<< param->arr[param->item_to_write].p_file_info->get_readable_size()
					<< param->arr[param->item_to_write].p_file_info->get_readable_time()
					<< "\t"
					<< param->arr[param->item_to_write].p_file_info->get_readable_sum()
					<< std::endl;
			param->item_to_write++;

		}

		s = pthread_mutex_unlock(param->hmutex);
		if (s != 0) {
			errno = s;
			perror("pthread_mutex_unlock");
			exit (EXIT_FAILURE);
		}

	}

	return NULL;
}

void LinuxFileList::fill_files_info_and_file() {

	int s;

	//mutex for conditional variable
	pthread_mutex_t hMutex;
	s = pthread_mutex_init(&hMutex, NULL);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_init");
		exit (EXIT_FAILURE);
	}

	//event to trigger wait thread
	pthread_cond_t hEvent;
	s = pthread_cond_init(&hEvent, NULL);
	if (s != 0) {
		errno = s;
		perror("pthread_cond_init");
		exit (EXIT_FAILURE);
	}

	LinuxThreadPool threadPool(2);

	//create file to write information
	size_t found = files.begin()->second.path_.find_last_of(L"/\\");
	std::wstring directory = files.begin()->second.path_.substr(0, found + 1);
	std::wofstream file(FileUtils::wstr2str(directory + L"com_task_3.txt"),
			std::wofstream::out | std::wofstream::trunc);
	if (!file.is_open()) {
		perror("file.is_open()");
		exit (EXIT_FAILURE);
		return;
	}

	int i = 0;
	files_map::iterator it;

	//init work callback arguments
	CallbackParameter * params = new CallbackParameter[files.size()]();

	//init wait callback argument
	SumsCallbackParameter sums_par = { params, files.size(), &hEvent, &hMutex,
			0, &file };

	pthread_t wait_sums;
	s = pthread_create(&wait_sums, NULL, LinuxFileList::wait_for_sums_thread,
			reinterpret_cast<void*>(&sums_par));
	if (s != 0) {
		errno = s;
		perror("pthread_create");
		exit (EXIT_FAILURE);
	}

	//iterate the container
	for (it = files.begin(), i = 0; it != files.end(); it++, i++) {

		//init work callback argument
		params[i].file_name = it->first;
		params[i].hevent = &hEvent;
		params[i].p_file_info = &it->second;

		threadPool.add(LinuxFileList::fill_file_info_callback, &params[i]);

}

	threadPool.startProcessTasks();

	//wait all work callbacks (fill file_info structures)
	threadPool.waitAllTasks();

	//trigger event to call file write callback
	s = pthread_cond_signal(&hEvent);
	if (s != 0) {
		errno = s;
		perror("pthread_cond_signal");
		exit (EXIT_FAILURE);
	}

	//wait all wait callbacks (dump all info to file)
	s = pthread_join(wait_sums, NULL);
	if (s != 0) {
		errno = s;
		perror("pthread_join");
		exit (EXIT_FAILURE);
	}

	//write all remaining, if conditional signal was lost
	LinuxFileList::wait_for_sums_thread(&sums_par);

	//clean up
	delete[] params;
	s = pthread_cond_destroy(&hEvent);
	if (s != 0) {
		errno = s;
		perror("pthread_cond_destroy");
		exit (EXIT_FAILURE);
	}

	s = pthread_mutex_destroy(&hMutex);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_destroy");
		exit (EXIT_FAILURE);
	}

	file.close();
	return;
}

#endif //__linux__
