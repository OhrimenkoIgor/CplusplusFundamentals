
#if defined _WIN32 || defined _WIN64

#include <cwchar>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <Windows.h>

#include "FileUtils.h"
#include "WinFileUtils.h"

std::wstring WinFileUtils::systime2wstr(const SYSTEMTIME & sys_time){
	std::wostringstream ret;
	ret << sys_time.wMonth << "/" << sys_time.wDay << "/" << sys_time.wYear << "\t"
		<< std::setfill(L'0') << std::setw(2) << sys_time.wHour << ":" << std::setfill(L'0') << std::setw(2) << sys_time.wMinute;
	return ret.str();
}

std::wstring WinFileUtils::get_file_creation_date(const std::wstring & path){
	SYSTEMTIME sys_time = {0, 0, 0, 0, 0, 0, 0, 0};
	FILETIME local_time;
	WIN32_FILE_ATTRIBUTE_DATA lpFileInformation;
	BOOL res;

	res = GetFileAttributesEx(path.c_str(), GetFileExInfoStandard, (LPVOID) &lpFileInformation);
	if(!res){
		return WinFileUtils::systime2wstr(sys_time);
	}

	res = FileTimeToLocalFileTime(&lpFileInformation.ftCreationTime, &local_time);
	if(!res){
		return WinFileUtils::systime2wstr(sys_time);
	}

	FileTimeToSystemTime(&local_time, &sys_time);

	return WinFileUtils::systime2wstr(sys_time);
}

uint64_t WinFileUtils::get_file_size(const std::wstring & path){
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

DWORD WinFileUtils::count_sum(LPVOID path){	
	return FileUtils::count_sum(std::wstring((wchar_t*)path));
}

#endif //defined _WIN32 || defined _WIN64