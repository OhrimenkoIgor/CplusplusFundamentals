
#ifndef FILEINFO_H_
#define FILEINFO_H_

#include <cstdint>
#include <string>

#include <windows.h>

struct FileInfo{
	std::wstring path_;
	uint64_t size_;
	SYSTEMTIME time_;
	DWORD sum_;

	FileInfo(std::wstring path = L"");
};

#endif //FILEINFO_H_
