#ifndef LINUXFILELIST_H_
#define LINUXFILELIST_H_

#if defined __linux__

#include "FileList.h"

class LinuxFileList: public FileList {
public:
	virtual void fill_files_info_and_file();
protected:
	static void* fill_file_info_callback(void* Parameter);
	static void* wait_for_sums_thread(void* Parameter);

	struct CallbackParameter;
	struct SumsCallbackParameter;
};

#endif //__linux__
#endif //LINUXFILELIST_H_
