
#include "FileInfo.h"

FileInfo::FileInfo(std::wstring path): path_(path), size_(0), sum_(0){
	SYSTEMTIME temp = {0,0,0,0,0,0,0,0};
	time_ = temp;
}

