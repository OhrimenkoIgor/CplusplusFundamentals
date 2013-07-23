
#include <algorithm>

#include "WinFileUtils.h"
#include "FileInfo.h"

#include "FileList.h"

void FileList::add_file(const FileInfo & file_info){
	size_t found = file_info.path_.find_last_of(L"/\\");
	std::wstring key = (found != std::wstring::npos) ? file_info.path_.substr(found+1) : file_info.path_;   
	files.insert(files_map::value_type(key,file_info));
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
            0,                      // use default creation flags 
            0);   // returns the thread identifier 
	}

	DWORD wait_result, file_sum;
	for(it = files.begin(), i = 0; it != files.end(); it++, i++){
		 wait_result = WaitForSingleObject(threads[i], INFINITE);
		 if (wait_result == WAIT_OBJECT_0){
			 it->second.sum_ = (GetExitCodeThread(threads[i],  &file_sum)) ? it->second.sum_ = file_sum : 0;
		 }
	}

	delete [] threads;
}




