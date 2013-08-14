#if defined __linux__

#include <fstream>
#include <iomanip>

#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>

#include "FileUtils.h"
#include "LinuxFileUtils.h"
#include "LinuxFileList.h"

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
	int s = stat(LinuxFileUtils::wstr2str(param->p_file_info->path_).c_str(),
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

void* LinuxFileList::wait_for_sums_callback(void* Parameter) {
	int s;
	SumsCallbackParameter * param =
			reinterpret_cast<SumsCallbackParameter *>(Parameter);

	//write info about all files, that are processed by the moment, but info is not written
	//stop on non-processed file
	while (param->item_to_write < param->size
			&& param->arr[param->item_to_write].done) {
		//capture mutex
		s = pthread_cond_wait(param->hevent, param->hmutex);
		if (s != 0) {
			errno = s;
			perror("pthread_cond_wait");
			exit (EXIT_FAILURE);
		}
		//one formatted wstring per file info structure
		(*param->file) << std::setw(128) << std::left
				<< param->arr[param->item_to_write].file_name << std::setw(20)
				<< param->arr[param->item_to_write].p_file_info->get_readable_size()
				<< param->arr[param->item_to_write].p_file_info->get_readable_time()
				<< "\t"
				<< param->arr[param->item_to_write].p_file_info->get_readable_sum()
				<< std::endl;
		param->item_to_write++;
		s = pthread_mutex_unlock(param->hmutex);
		if (s != 0) {
			errno = s;
			perror("pthread_mutex_unlock");
			exit (EXIT_FAILURE);
		}
	}
	return NULL;
}

void WinFileList::fill_files_info_and_file() {
	BOOL bRet = FALSE;
	PTP_WORK work = NULL;
	PTP_POOL pool = NULL;
	PTP_WORK_CALLBACK workcallback = WinFileList::fill_file_info_callback;
	PTP_WAIT wait = NULL, wait_sums = NULL;
	PTP_WAIT_CALLBACK wait_sums_callback = WinFileList::wait_for_sums_callback;
	TP_CALLBACK_ENVIRON CallBackEnviron;
	PTP_CLEANUP_GROUP cleanupgroup = NULL;
	HANDLE hEvent, hMutex;

	InitializeThreadpoolEnvironment(&CallBackEnviron);

	//mutex for wait callback for synchronyze file write
	hMutex = CreateMutex(NULL, FALSE, NULL);
	if (NULL == hMutex) {
		return;
	}

	//event to trigger wait callback
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (NULL == hEvent) {
		CloseHandle(hMutex);
		return;
	}

	pool = CreateThreadpool(NULL);
	if (NULL == pool) {
		CloseHandle(hEvent);
		CloseHandle(hMutex);
		return;
	}

	SetThreadpoolThreadMaximum(pool, 2);
	bRet = SetThreadpoolThreadMinimum(pool, 1);
	if (FALSE == bRet) {
		CloseHandle(hEvent);
		CloseHandle(hMutex);
		CloseThreadpool(pool);
		return;
	}

	//group to wait all work tasks
	cleanupgroup = CreateThreadpoolCleanupGroup();
	if (NULL == cleanupgroup) {
		CloseHandle(hEvent);
		CloseHandle(hMutex);
		CloseThreadpool(pool);
		return;
	}

	SetThreadpoolCallbackPool(&CallBackEnviron, pool);
	SetThreadpoolCallbackCleanupGroup(&CallBackEnviron, cleanupgroup, NULL);

	//create file to write information
	size_t found = files.begin()->second.path_.find_last_of(L"/\\");
	std::wstring directory = files.begin()->second.path_.substr(0, found + 1);
	std::wofstream file(directory + L"com_task_2.txt",
			std::wofstream::out | std::wofstream::trunc);
	if (!file.is_open()) {
		CloseHandle(hEvent);
		CloseHandle(hMutex);
		CloseThreadpool(pool);
		return;
	}

	int i = 0;
	files_map::iterator it;

	//init work callback arguments
	CallbackParameter * params = new CallbackParameter[files.size()]();

	//init wait callback argument
	SumsCallbackParameter sums_par = { params, files.size(), hEvent, hMutex, 0,
			&file };
	wait_sums = CreateThreadpoolWait(wait_sums_callback, &sums_par, NULL);
	SetThreadpoolWait(wait_sums, hEvent, NULL);

	//iterate the container
	for (it = files.begin(), i = 0; it != files.end(); it++, i++) {

		//init work callback argument
		params[i].file_name = it->first;
		params[i].hevent = hEvent;
		params[i].p_file_info = &it->second;

		work = CreateThreadpoolWork(workcallback, &params[i], &CallBackEnviron);
		if (NULL == work) {
			delete[] params;
			CloseHandle(hEvent);
			CloseHandle(hMutex);
			CloseThreadpool(pool);
			file.close();
			return;
		}

		//submit task to thread pull
		SubmitThreadpoolWork(work);
	}

	//wait all work callbacks (fill file_info structures)
	CloseThreadpoolCleanupGroupMembers(cleanupgroup, FALSE, NULL);

	//wait all wait callbacks (dump all info to file)
	WaitForThreadpoolWaitCallbacks(wait_sums, FALSE);
	SetThreadpoolWait(wait_sums, NULL, NULL);
	WaitForThreadpoolWaitCallbacks(wait_sums, FALSE);
	CloseThreadpoolWait(wait_sums);

	//clean up
	delete[] params;
	CloseHandle(hEvent);
	CloseHandle(hMutex);
	// Clean up the cleanup group.
	CloseThreadpoolCleanupGroup(cleanupgroup);
	CloseThreadpool(pool);
	file.close();
	return;
}

#endif //__linux__
