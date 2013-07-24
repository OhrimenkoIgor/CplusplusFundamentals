
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "WinFileUtils.h"
#include "FileInfo.h"

#include "FileList.h"

void FileList::add_file(const FileInfo & file_info){
	size_t found = file_info.path_.find_last_of(L"/\\");
	std::wstring key = (found != std::wstring::npos) ? file_info.path_.substr(found+1) : file_info.path_;   
	files.insert(std::pair<std::wstring, FileInfo>(key,file_info));
}

void FileList::set_time_for_file(files_map::value_type & el){
	el.second.time_ = WinFileUtils::get_file_creation_date(el.second.path_);
}

void FileList::set_date_for_each_file(){
	for_each(files.begin(), files.end(), FileList::set_time_for_file);
}

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

	//start threads
	for(it = files.begin(), i = 0; it != files.end(); it++, i++){
		threads[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            WinFileUtils::count_sum,       // thread function name
			const_cast<wchar_t *>(it->second.path_.c_str()),          // argument to thread function 
            STACK_SIZE_PARAM_IS_A_RESERVATION,                      // 
            0);   // returns the thread identifier 
	}

	DWORD wait_result, file_sum;
	for(it = files.begin(), i = 0; it != files.end(); it++, i++){
		 wait_result = WaitForSingleObject(threads[i], INFINITE);
		 if (wait_result == WAIT_OBJECT_0){
			 it->second.sum_ = (GetExitCodeThread(threads[i],  &file_sum)) ? it->second.sum_ = file_sum : 0;
		 }
		 CloseHandle(threads[i]);
	}

	delete [] threads;
}

inline void save_to_file(const std::wstring & path, const std::wostringstream & str){
	std::wofstream file(path + L"com_task.txt");
	file << str.str();
	file.close();
}

std::wstring FileList::get_readable_list() const{
	std::wostringstream files_list;

	files_map::const_iterator it;
	int i = 0;
	for(it = files.begin(), i =0; it != files.end(); it++, i++){
		if(i < 10 || i > files.size() - 10){
			files_list << std::setw(128) << std::left << it->first << std::setw(20) << it->second.get_readable_size() 
				<< it->second.get_readable_time() << "\t" << it->second.get_readable_sum() << std::endl;
		}
	}

	size_t found = files.begin()->second.path_.find_last_of(L"/\\");
	save_to_file(files.begin()->second.path_.substr(0, found+1) ,files_list);

	return files_list.str();
}

struct FileList::CallbackParameter{
	std::wstring file_name;
	HANDLE hevent;
	FileInfo * p_file_info;
	bool done;
	HANDLE write_file_event;
	std::wofstream * file; 

	CallbackParameter(){
		write_file_event = 0;
	}
	~CallbackParameter(){
		if(write_file_event){
			CloseHandle(write_file_event);
		}
	}
};

struct FileList::SumsCallbackParameter{
	CallbackParameter * arr;
	size_t size;
	HANDLE hevent;
	unsigned int item_to_write;
};

VOID CALLBACK FileList::fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work){
	CallbackParameter * param = reinterpret_cast<CallbackParameter *> (Parameter);

	SYSTEMTIME sys_time = {0, 0, 0, 0, 0, 0, 0, 0};
	FILETIME local_time;
	WIN32_FILE_ATTRIBUTE_DATA lpFileInformation;
	BOOL res;

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

	param->p_file_info->sum_ = WinFileUtils::count_sum(const_cast<wchar_t *>(param->p_file_info->path_.c_str()));

	param->done = true;

	SetEvent(param->hevent);

	return;
}

VOID CALLBACK FileList::write_file_info_callback( PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult){
	CallbackParameter * param = reinterpret_cast<CallbackParameter *> (Parameter);

	(*param->file) << std::setw(128) << std::left << param->file_name << std::setw(20) << param->p_file_info->get_readable_size() 
				<< param->p_file_info->get_readable_time() << "\t" << param->p_file_info->get_readable_sum() << std::endl;

}

VOID CALLBACK FileList::wait_for_sums_callback( PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult){
	SumsCallbackParameter * param = reinterpret_cast<SumsCallbackParameter *> (Parameter);

	while(param->arr[param->item_to_write].done && param->item_to_write < param->size){
		SetEvent(param->arr[param->item_to_write].write_file_event);
		param->item_to_write++;
	}
	
	if(param->item_to_write != param->size){
		SetThreadpoolWait(Wait, param->hevent, NULL);
	}
}

void FileList::fill_files_info_and_file(){
	BOOL bRet = FALSE;
	PTP_WORK work = NULL;
	PTP_POOL pool = NULL;
	PTP_WORK_CALLBACK workcallback = FileList::fill_file_info_callback;
	PTP_WAIT wait = NULL, wait_sums = NULL;
    PTP_WAIT_CALLBACK waitcallback = FileList::write_file_info_callback;
	PTP_WAIT_CALLBACK wait_sums_callback = FileList::wait_for_sums_callback;
	TP_CALLBACK_ENVIRON CallBackEnviron;
	PTP_CLEANUP_GROUP cleanupgroup = NULL;
	HANDLE hEvent;

	InitializeThreadpoolEnvironment(&CallBackEnviron);

	pool = CreateThreadpool(NULL);
	if (NULL == pool) {
		return;
	}
	
	SetThreadpoolThreadMaximum(pool, 2);
	bRet = SetThreadpoolThreadMinimum(pool, 1);
	if (FALSE == bRet) {
		CloseThreadpool(pool);
		return;
	}

	cleanupgroup = CreateThreadpoolCleanupGroup();
	if (NULL == cleanupgroup) {
		CloseThreadpool(pool);
		return;
	}

	SetThreadpoolCallbackPool(&CallBackEnviron, pool);
	SetThreadpoolCallbackCleanupGroup(&CallBackEnviron, cleanupgroup, NULL);

	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (NULL == hEvent) {
        // Error Handling
        return;
    }

	size_t found = files.begin()->second.path_.find_last_of(L"/\\");
	std::wofstream file(files.begin()->second.path_.substr(0, found+1) + L"com_task_2.txt");

	int i = 0;
	files_map::iterator it;
	CallbackParameter * params = new CallbackParameter[files.size()];
	SumsCallbackParameter sums_par = {params, files.size(), hEvent, 0};
	wait_sums = CreateThreadpoolWait(wait_sums_callback, &sums_par, NULL);
	SetThreadpoolWait(wait_sums, hEvent, NULL);

	for(it = files.begin(), i =0; it != files.end(); it++, i++){

		params[i].file_name = it->first;
		params[i].hevent = hEvent;
		params[i].p_file_info = &it->second;
		params[i].done = false;
		params[i].write_file_event = CreateEvent(NULL, FALSE, FALSE, NULL);
		params[i].file = &file;

		work = CreateThreadpoolWork(workcallback, &params[i], &CallBackEnviron);
		//wait = CreateThreadpoolWait(waitcallback, &params[i], &CallBackEnviron);
		if (NULL == work || NULL == wait) {
			delete [] params;
			CloseHandle(hEvent);
			CloseThreadpool(pool);
			file.close();
			return;
		}
		SubmitThreadpoolWork(work);
		//SetThreadpoolWait(wait,  &params[i].write_file_event, NULL);
	}

	CloseThreadpoolCleanupGroupMembers(cleanupgroup, FALSE,	NULL);

    SetThreadpoolWait(wait_sums, NULL, NULL);
    CloseThreadpoolWait(wait_sums);

	delete [] params;
	CloseHandle(hEvent);
	// Clean up the cleanup group.
	CloseThreadpoolCleanupGroup(cleanupgroup);
	CloseThreadpool(pool);
	file.close();
	return;
}


