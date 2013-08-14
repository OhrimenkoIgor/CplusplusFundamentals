
#ifndef FILEINFO_H_
#define FILEINFO_H_

#include <cstdint>
#include <string>
#include <iostream>

#include <windows.h>

/*
	Structure with information for one file
*/
struct FileInfo{
	std::wstring path_;
	uint64_t size_;
	std::wstring time_;
	uint32_t sum_;

	FileInfo(std::wstring path = L"");

	/*
		Converts file size to readable format and returns the string 
	*/
	std::wstring get_readable_size() const;

	/*
		Converts file creation time to readable format and returns the string 
	*/
	std::wstring get_readable_time() const;

	/*
		Converts file chech sum to readable format and returns the string 
	*/
	std::wstring get_readable_sum() const;
};

#endif //FILEINFO_H_
