
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <clocale>

#include "WinFileUtils.h"
#include "FileInfo.h"

#include "FileList.h"

void FileList::add_file(const FileInfo & file_info){
	//retreive filename prom path
	size_t found = file_info.path_.find_last_of(L"/\\");
	std::wstring key = (found != std::wstring::npos) ? file_info.path_.substr(found+1) : file_info.path_;
	//add pair to map
	files.insert(std::pair<std::wstring, FileInfo>(key,file_info));
}

//function for std::for_each
void FileList::set_time_for_file(files_map::value_type & el){
	el.second.time_ = WinFileUtils::get_file_creation_date(el.second.path_);
}

void FileList::set_date_for_each_file(){
	for_each(files.begin(), files.end(), FileList::set_time_for_file);
}

//function for std::for_each
void FileList::set_size_for_file(files_map::value_type & el){
	el.second.size_ = WinFileUtils::get_file_size(el.second.path_);
}

void FileList::set_size_for_each_file(){
	for_each(files.begin(), files.end(), FileList::set_size_for_file);
}

void FileList::set_sum_for_each_file(){
	size_t map_size = files.size();
	HANDLE * threads = new HANDLE[map_size];
	int i;
	files_map::iterator it;

	//start thread per file
	for(it = files.begin(), i = 0; it != files.end(); it++, i++){
		threads[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            WinFileUtils::count_sum,       // thread function name
			const_cast<wchar_t *>(it->second.path_.c_str()),          // argument to thread function 
            STACK_SIZE_PARAM_IS_A_RESERVATION,                      // 
            0);   // returns the thread identifier 
	}

	//wait for threads to finish
	DWORD wait_result, file_sum;
	for(it = files.begin(), i = 0; it != files.end(); it++, i++){
		 wait_result = WaitForSingleObject(threads[i], INFINITE);
		 if (wait_result == WAIT_OBJECT_0){
			 //retreive thread return value (check sum)
			 it->second.sum_ = (GetExitCodeThread(threads[i],  &file_sum)) ? it->second.sum_ = file_sum : 0;
		 }
		 CloseHandle(threads[i]);
	}

	delete [] threads;
}

std::wstring FileList::get_readable_list() const{
	std::wostringstream files_list;

	bool Ellipsis = false;

	files_map::const_iterator it;
	int i = 0;

	//iterate container and collect all information about files in one wstring
	for(it = files.begin(), i =0; it != files.end(); it++, i++){
		//process only first 10 and last 10 files
		if(i < 10 || i > files.size() - 1 - 10){
			//line per file
			files_list << std::setw(128) << std::left << it->first << std::setw(20) << it->second.get_readable_size() 
				<< it->second.get_readable_time() << "\t" << it->second.get_readable_sum() << std::endl;
		} else{
			if(!Ellipsis){
				//put elipsis in the middle
				files_list << L"..." << std::endl;
				Ellipsis = true;
			}
		}
	}

	return files_list.str();
}

//structure for thread pool work callback argument
struct FileList::CallbackParameter{
	std::wstring file_name; //filename
	HANDLE hevent;			//event to trigger
	FileInfo * p_file_info;	//pointer to file_info in map to fill
	bool done;				//set true when finished to fill all fields

	CallbackParameter(){
		done = false;
	}

};

//structure for thread pool wait callback argument
struct FileList::SumsCallbackParameter{
	CallbackParameter * arr; //pointer to file_infos for printing to file
	size_t size;			//size of container
	HANDLE hevent;			//event to set to wait
	HANDLE hmutex;			//mutex for synchronization of file write 
	unsigned int item_to_write;//current number of file_info from container to write
	std::wofstream * file;	//pointer to file output stream to write
};

VOID CALLBACK FileList::fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work){
	CallbackParameter * param = reinterpret_cast<CallbackParameter *> (Parameter);

	SYSTEMTIME sys_time = {0, 0, 0, 0, 0, 0, 0, 0};
	FILETIME local_time;
	WIN32_FILE_ATTRIBUTE_DATA lpFileInformation;
	BOOL res;

	//retreive size and creation date
	res = GetFileAttributesEx(param->p_file_info->path_.c_str(), GetFileExInfoStandard, (LPVOID) &lpFileInformation);
	if(res){
		param->p_file_info->size_ = lpFileInformation.nFileSizeLow | (uint64_t(lpFileInformation.nFileSizeHigh) << 32);
		res = FileTimeToLocalFileTime(&lpFileInformation.ftCreationTime, &local_time);
		if (res){
			res = FileTimeToLocalFileTime(&lpFileInformation.ftCreationTime, &local_time);
			if(res){
				res = FileTimeToSystemTime(&local_time, &sys_time);
				if (res){
					param->p_file_info->time_ = sys_time;
				}
			}
		}
	}

	//count check sum
	param->p_file_info->sum_ = WinFileUtils::count_sum(const_cast<wchar_t *>(param->p_file_info->path_.c_str()));

	//done
	param->done = true;

	//trigger event to call file write callback
	SetEvent(param->hevent);

	return;
}

VOID CALLBACK FileList::wait_for_sums_callback( PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult){
	SumsCallbackParameter * param = reinterpret_cast<SumsCallbackParameter *> (Parameter);

	//write info about all files, that are processed by the moment, but info is not written
	//stop on non-processed file
	while(param->item_to_write < param->size && param->arr[param->item_to_write].done){
		//capture mutex
		if (WAIT_OBJECT_0 == WaitForSingleObject(param->hmutex, INFINITE)){
			//one formatted wstring per file info structure
			(*param->file) << std::setw(128) << std::left << param->arr[param->item_to_write].file_name 
				<< std::setw(20) <<  param->arr[param->item_to_write].p_file_info->get_readable_size() 
				<<  param->arr[param->item_to_write].p_file_info->get_readable_time() 
				<< "\t" <<  param->arr[param->item_to_write].p_file_info->get_readable_sum() << std::endl;
			param->item_to_write++;
			ReleaseMutex(param->hmutex);
		}
	}
	
	//reset wait object if processed file is not last one
	if(param->item_to_write < param->size){
		SetThreadpoolWait(Wait, param->hevent, NULL);
	}
}

void FileList::fill_files_info_and_file(){
	BOOL bRet = FALSE;
	PTP_WORK work = NULL;
	PTP_POOL pool = NULL;
	PTP_WORK_CALLBACK workcallback = FileList::fill_file_info_callback;
	PTP_WAIT wait = NULL, wait_sums = NULL;
	PTP_WAIT_CALLBACK wait_sums_callback = FileList::wait_for_sums_callback;
	TP_CALLBACK_ENVIRON CallBackEnviron;
	PTP_CLEANUP_GROUP cleanupgroup = NULL;
	HANDLE hEvent, hMutex;

	InitializeThreadpoolEnvironment(&CallBackEnviron);

	//mutex for wait callback for synchronyze file write
	hMutex = CreateMutex( NULL, FALSE, NULL); 
	if(NULL == hMutex){
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
	std::wstring directory = files.begin()->second.path_.substr(0, found+1);
	std::wofstream file(directory + L"com_task_2.txt", std::wofstream::out | std::wofstream::trunc);
	if(!file.is_open()){
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
	SumsCallbackParameter sums_par = {params, files.size(), hEvent, hMutex, 0, &file};
	wait_sums = CreateThreadpoolWait(wait_sums_callback, &sums_par, NULL);
	SetThreadpoolWait(wait_sums, hEvent, NULL);

	//iterate the container
	for(it = files.begin(), i =0; it != files.end(); it++, i++){

		//init work callback argument
		params[i].file_name = it->first;
		params[i].hevent = hEvent;
		params[i].p_file_info = &it->second;

		work = CreateThreadpoolWork(workcallback, &params[i], &CallBackEnviron);
		if (NULL == work) {
			delete [] params;
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
	CloseThreadpoolCleanupGroupMembers(cleanupgroup, FALSE,	NULL);

	//wait all wait callbacks (dump all info to file)
	WaitForThreadpoolWaitCallbacks(wait_sums, FALSE);
    SetThreadpoolWait(wait_sums, NULL, NULL);
	WaitForThreadpoolWaitCallbacks(wait_sums, FALSE);
    CloseThreadpoolWait(wait_sums);

	//clean up
	delete [] params;
	CloseHandle(hEvent);
	CloseHandle(hMutex);
	// Clean up the cleanup group.
	CloseThreadpoolCleanupGroup(cleanupgroup);
	CloseThreadpool(pool);
	file.close();
	return;
}


