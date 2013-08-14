
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

std::wstring FileList::get_readable_list() const{
	std::wostringstream files_list;

	bool Ellipsis = false;

	files_map::const_iterator it;
	unsigned int i = 0;

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


/*
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
*/