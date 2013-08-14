
#include "FileListFactory.h"

#include "WinFileList.h"
#include "LinuxFileList.h"
 
FileList * FileListFactory::getFileList(){
#ifdef __linux__ 
	return new LinuxFileList();
#elif defined _WIN32 || defined _WIN64
	return new WinFileList();
#else
#error "unknown platform"
#endif

}
