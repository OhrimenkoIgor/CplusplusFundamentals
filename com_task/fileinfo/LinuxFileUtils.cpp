
#if defined __linux__

#include <sstream>
#include <iomanip>
#include <stdlib.h>

#include "LinuxFileUtils.h"

std::string LinuxFileUtils::wstr2str(const std::wstring & str){
	char* path_buffer = new char[1024]();
	std::wcstombs(path_buffer, str.c_str(), 1024); //TODO check
	return std::string(path_buffer);
}

std::wstring LinuxFileUtils::tm2wstr(const tm & time){
	std::wostringstream ret;
	ret << time.tm_mon << "/" << time.tm_mday << "/" << time.tm_year << "\t"
		<< std::setfill(L'0') << std::setw(2) << time.tm_hour << ":" << std::setfill(L'0') << std::setw(2) << time.tm_min;
	return ret.str();
}

#endif //__linux__
