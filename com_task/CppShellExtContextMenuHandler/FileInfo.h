
#ifndef FILEINFO_H_
#define FILEINFO_H_

#include <cstdint>
#include <string>
#include <iostream>

#include <windows.h>

struct FileInfo{
	std::wstring path_;
	uint64_t size_;
	SYSTEMTIME time_;
	DWORD sum_;

	FileInfo(std::wstring path = L"");
	std::wstring get_readable_size() const;
	std::wstring get_readable_time() const;
	std::wstring get_readable_sum() const;
};

#endif //FILEINFO_H_
