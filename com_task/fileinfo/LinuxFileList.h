
#ifndef LINUXFILELIST_H_
#define LINUXFILELIST_H_

#include "FileList.h"

#if defined __linux__

class LinuxFileList : public FileList {
public:
	virtual void fill_files_info_and_file();
protected:
	static VOID CALLBACK fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work);
	static VOID CALLBACK wait_for_sums_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);

	struct CallbackParameter;
	struct SumsCallbackParameter;
};

#endif //__linux__

#endif //LINUXFILELIST_H_