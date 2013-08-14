
#include <fstream>

#include "FileUtils.h"

uint32_t FileUtils::count_sum(const std::wstring & path){
	uint32_t sum = 0;
	const int size_dword = sizeof(uint32_t);
	uint32_t  w;
	char * buf = (char *) &w;
	std::ifstream file(path, std::ios_base::binary | std::ios_base::in);
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

