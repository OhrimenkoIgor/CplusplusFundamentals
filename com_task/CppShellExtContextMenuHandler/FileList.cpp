
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
	HANDLE mutex;
	FileInfo * p_file_info;
};

VOID CALLBACK FileList::fill_file_info_and_file_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work){
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

	return;
}

void FileList::fill_files_info_and_file(){
	BOOL bRet = FALSE;
	PTP_WORK work = NULL;
	PTP_TIMER timer = NULL;
	PTP_POOL pool = NULL;
	PTP_WORK_CALLBACK workcallback = FileList::fill_file_info_and_file_callback;
	//PTP_TIMER_CALLBACK timercallback = MyTimerCallback;
	TP_CALLBACK_ENVIRON CallBackEnviron;
	PTP_CLEANUP_GROUP cleanupgroup = NULL;
	HANDLE ghMutex;

	InitializeThreadpoolEnvironment(&CallBackEnviron);

	//
	// Create a custom, dedicated thread pool.
	//
	pool = CreateThreadpool(NULL);
	if (NULL == pool) {
		return;
	}

	//
	// The thread pool is made persistent simply by setting
	// both the minimum and maximum threads to 1.
	//
	SetThreadpoolThreadMaximum(pool, 2);

	bRet = SetThreadpoolThreadMinimum(pool, 1);

	if (FALSE == bRet) {
		CloseThreadpool(pool);
		return;
	}

	//
	// Create a cleanup group for this thread pool.
	//
	cleanupgroup = CreateThreadpoolCleanupGroup();

	if (NULL == cleanupgroup) {
		CloseThreadpool(pool);
		return;
	}

	//
	// Associate the callback environment with our thread pool.
	//
	SetThreadpoolCallbackPool(&CallBackEnviron, pool);

	//
	// Associate the cleanup group with our thread pool.
	// Objects created with the same callback environment
	// as the cleanup group become members of the cleanup group.
	//
	SetThreadpoolCallbackCleanupGroup(&CallBackEnviron,
		cleanupgroup,
		NULL);

	ghMutex = CreateMutex( 
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	int i = 0;
	files_map::iterator it;
	CallbackParameter * params = new CallbackParameter[files.size()];
	for(it = files.begin(), i =0; it != files.end(); it++, i++){

		params[i].mutex = ghMutex;
		params[i].p_file_info = &it->second;

		work = CreateThreadpoolWork(workcallback, &params[i], &CallBackEnviron);
		if (NULL == work) {
			CloseThreadpoolCleanupGroup(cleanupgroup);
			delete [] params;
			CloseHandle(ghMutex);
			return;
		}

		SubmitThreadpoolWork(work);
	}

	//
	// Wait for all callbacks to finish.
	// CloseThreadpoolCleanupGroupMembers also releases objects
	// that are members of the cleanup group, so it is not necessary 
	// to call close functions on individual objects 
	// after calling CloseThreadpoolCleanupGroupMembers.
	//
	CloseThreadpoolCleanupGroupMembers(cleanupgroup,
		FALSE,
		NULL);


	delete [] params;
	CloseHandle(ghMutex);
	// Clean up the cleanup group.
	CloseThreadpoolCleanupGroup(cleanupgroup);
	CloseThreadpool(pool);
	return;
}


