

#ifndef WINFILELIST_H_
#define WINFILELIST_H_

#if defined _WIN32 || defined _WIN64

#include <Windows.h>

#include "FileList.h"

class WinFileList : public FileList {
public:
	virtual void fill_files_info_and_file();
protected:
	static VOID CALLBACK fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work);
	static VOID CALLBACK wait_for_sums_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);

	struct CallbackParameter;
	struct SumsCallbackParameter;
};

#endif //defined _WIN32 || defined _WIN64

#endif //WINFILELIST_H_
