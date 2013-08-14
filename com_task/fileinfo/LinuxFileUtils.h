
#ifndef LINUXFILEUTILS_H_
#define LINUXFILEUTILS_H_

#if defined __linux__

#include <string>
#include <ctime>
/*
	Utils, that that are used to retreive information about file in Linux
*/
class LinuxFileUtils{	

public:
	static std::string wstr2str(const std::wstring & str);
	static std::wstring tm2wstr(const tm & time);
};

#endif //__linux__

#endif //LINUXFILEUTILS_H_
