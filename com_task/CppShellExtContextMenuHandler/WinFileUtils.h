
#ifndef WINFILEUTILS_H_
#define WINFILEUTILS_H_

#include <string>
#include <cstdint>

class WinFileUtils{
private:
	static DWORD WINAPI count_sum(LPVOID path);
public:
	static SYSTEMTIME get_file_creation_date(std::wstring path);

	static uint64_t get_file_size(std::wstring path);

	static HANDLE start_thread_for_sum(std::wstring path);
};

#endif //WINFILEUTILS_H_
