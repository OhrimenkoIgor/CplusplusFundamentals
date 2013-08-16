
#include "FileListCreator.h"

#include "WinFileList.h"
#include "LinuxFileList.h"
 
FileList * FileListCreator::getFileList(){
#ifdef __linux__ 
	return new LinuxFileList();
#elif defined _WIN32 || defined _WIN64
	return new WinFileList();
#else
#error "unknown platform"
#endif

}
