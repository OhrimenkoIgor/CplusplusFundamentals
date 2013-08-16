
#include <fstream>
#include <stdlib.h>

#include "FileUtils.h"
#include "LinuxFileUtils.h"

std::wstring FileUtils::str2wstr(const std::string & str){
	wchar_t* path_buffer = new wchar_t[str.length() + 1]();
	//size_t mbstowcs (wchar_t* dest, const char* src, size_t max);
	std::mbstowcs(path_buffer, str.c_str(), str.length() + 1); //TODO check
	std::wstring ret(path_buffer);
	delete [] path_buffer;
	return ret;
}

std::string FileUtils::wstr2str(const std::wstring & str){
	char* path_buffer = new char[str.length() * 2 + 1]();
	std::wcstombs(path_buffer, str.c_str(), str.length() * 2 + 1); //TODO check
	std::string ret(path_buffer);
	delete [] path_buffer;
	return ret;
}

uint32_t FileUtils::count_sum(const std::wstring & path){
	uint32_t sum = 0;
	const int size_dword = sizeof(uint32_t);
	uint32_t  w;
	char * buf = (char *) &w;

#ifdef __linux__
	std::ifstream file(FileUtils::wstr2str(path), std::ios_base::binary | std::ios_base::in);
#elif defined _WIN32 || defined _WIN64
	std::ifstream file(path, std::ios_base::binary | std::ios_base::in);
#else
#error "unknown platform"
#endif

	if (!file) 
		return 0;
	std::streamsize nread;
	while(file.read(buf, size_dword)){
		sum ^= w;
	}
	nread = file.gcount();
	for(std::streamsize i = nread; i < size_dword; i++){
		buf[i] = 0;
	}
	sum ^= w;
	file.close();
	return sum;
}


