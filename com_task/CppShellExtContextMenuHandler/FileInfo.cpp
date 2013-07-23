

#include <sstream>
#include <iomanip>
#include "FileInfo.h"

FileInfo::FileInfo(std::wstring path): path_(path), size_(0), sum_(0){
	SYSTEMTIME temp = {0,0,0,0,0,0,0,0};
	time_ = temp;
}

std::wstring FileInfo::get_readable_size() const{
	int i = 0;
	long double size = size_;
	std::wostringstream ret;
    const wchar_t* units[5] = {L"B", L"kB", L"MB", L"GB", L"TB"};
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    ret << std::setiosflags(std::ios::fixed) << std::setprecision(2) << size << L" " << units[i];

	return ret.str();
}

std::wstring FileInfo::get_readable_time() const{
	std::wostringstream ret;

	ret << time_.wMonth << "/" << time_.wDay << "/" << time_.wYear << "\t"
		<<  time_.wHour << ":" << time_.wMinute;

	return ret.str();
}

std::wstring FileInfo::get_readable_sum() const{
	std::wostringstream ret;

	ret << L"0x" << std::uppercase << std::hex << sum_;

	return ret.str();
}