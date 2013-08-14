
#include <fstream>
#include <stdlib.h>

#include "FileUtils.h"
#include "LinuxFileUtils.h"

uint32_t FileUtils::count_sum(const std::wstring & path){
	uint32_t sum = 0;
	const int size_dword = sizeof(uint32_t);
	uint32_t  w;
	char * buf = (char *) &w;

#ifdef __linux__
	std::ifstream file(LinuxFileUtils::wstr2str(path), std::ios_base::binary | std::ios_base::in);
#elif defined _WIN32 || defined _WIN64
	std::ifstream file(path, std::ios_base::binary | std::ios_base::in);
#else
#error "unknown platform"
#endif

	if (!file) 
		return 0;
	std::streamsize nread;
	while(file.read(buf, size_dword)){
		sum ^= w;
	}
	nread = file.gcount();
	for(std::streamsize i = nread; i < size_dword; i++){
		buf[i] = 0;
	}
	sum ^= w;
	file.close();
	return sum;
}

