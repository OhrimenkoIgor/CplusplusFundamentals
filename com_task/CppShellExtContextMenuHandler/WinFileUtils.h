
#ifndef WINFILEUTILS_H_
#define WINFILEUTILS_H_

#include <string>
#include <cstdint>
#include <windows.h>

class WinFileUtils{
public:
	static SYSTEMTIME get_file_creation_date(std::wstring path);

	static uint64_t get_file_size(std::wstring path);

	static DWORD WINAPI count_sum(LPVOID path);

};

#endif //WINFILEUTILS_H_
