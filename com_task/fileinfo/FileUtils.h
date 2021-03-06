

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>
#include <cstdint>

/*
	Utils, that that are used to retreive information about file
*/
class FileUtils{

public:

	static std::wstring str2wstr(const std::string & str);
	static std::string wstr2str(const std::wstring & str);

	static uint32_t count_sum(const std::wstring & path);

};


#endif //FILEUTILS_H_

