
#include <fstream>
#include <Windows.h>

#include "WinFileUtils.h"

SYSTEMTIME WinFileUtils::get_file_creation_date(std::wstring path){
	SYSTEMTIME sys_time = {0, 0, 0, 0, 0, 0, 0, 0};
	FILETIME local_time;
	WIN32_FILE_ATTRIBUTE_DATA lpFileInformation;
	BOOL res;

	res = GetFileAttributesEx(path.c_str(), GetFileExInfoStandard, (LPVOID) &lpFileInformation);
	if(!res){
		return sys_time;
	}

	res = FileTimeToLocalFileTime(&lpFileInformation.ftCreationTime, &local_time);
	if(!res){
		return sys_time;
	}

	FileTimeToSystemTime(&local_time, &sys_time);
	return sys_time;
}

uint64_t WinFileUtils::get_file_size(std::wstring path){
	uint64_t size = 0;
	WIN32_FILE_ATTRIBUTE_DATA lpFileInformation;
	BOOL res;

	res = GetFileAttributesEx(path.c_str(), GetFileExInfoStandard, (LPVOID) &lpFileInformation);
	if(!res){
		return size;
	}

	size = lpFileInformation.nFileSizeLow | (uint64_t(lpFileInformation.nFileSizeHigh) << 32);
	return size;
}

DWORD WINAPI WinFileUtils::count_sum(LPVOID path){
	DWORD sum = 0;
	const int size_dword = sizeof(DWORD);
	DWORD w;
	char * buf = (char *) &w;
	std::ifstream file((wchar_t*)path, std::ios_base::binary | std::ios_base::in);
	int nread;
	while((nread = file.readsome(buf, size_dword)) == size_dword && file){
		sum ^= w;
	}
	for(int i = nread; i < size_dword; i++){
		buf[i] = 0;
	}
	sum ^= w;
	file.close();
	return sum;
}

HANDLE WinFileUtils::start_thread_for_sum(std::wstring path){

	return CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            WinFileUtils::count_sum,       // thread function name
			path.c_str(),          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier 
}
