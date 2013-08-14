
#ifndef WINFILEUTILS_H_
#define WINFILEUTILS_H_

#if defined _WIN32 || defined _WIN64

#include <string>
#include <cstdint>
#include <windows.h>

/*
	Utils, that that are used to retreive information about file is Windows 
*/
class WinFileUtils{

	

public:

	static std::wstring systime2wstr(const SYSTEMTIME & sys_time);

	/*
		File creation date
		std::wstring path - path to file
	*/
	static std::wstring get_file_creation_date(const std::wstring & path);

	/*
		File size
		std::wstring path - path to file
	*/
	static uint64_t get_file_size(const std::wstring & path);

	/*
		File check sum
		LPVOID path - path to file, should be wchar_t *
	*/
	static DWORD count_sum(LPVOID path);

};

#endif //defined _WIN32 || defined _WIN64

#endif //WINFILEUTILS_H_
