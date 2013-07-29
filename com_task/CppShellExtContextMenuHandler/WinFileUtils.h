
#ifndef WINFILEUTILS_H_
#define WINFILEUTILS_H_

#include <string>
#include <cstdint>
#include <windows.h>

/*
	Utils, that that are used to retreive information about file is Windows 
*/
class WinFileUtils{
public:

	/*
		File creation date
		std::wstring path - path to file
	*/
	static SYSTEMTIME get_file_creation_date(std::wstring path);

	/*
		File size
		std::wstring path - path to file
	*/
	static uint64_t get_file_size(std::wstring path);

	/*
		File check sum
		LPVOID path - path to file, should be wchar_t *
	*/
	static DWORD WINAPI count_sum(LPVOID path);

};

#endif //WINFILEUTILS_H_
