
#ifndef FILELIST_H_
#define FILELIST_H_

#include <map>
#include <string>
#include <Windows.h>

struct FileInfo;

class FileList{
public:
	typedef std::map<std::wstring, FileInfo> files_map;
	void add_file(const FileInfo & file_info);
	void set_date_for_each_file();
	void set_size_for_each_file();
	void set_sum_for_each_file();

	std::wstring get_readable_list() const;

	void fill_files_info_and_file();

protected:
	files_map files;
	static void set_time_for_file(files_map::value_type & el);
	static void set_size_for_file(files_map::value_type & el);
	static VOID CALLBACK fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work);
	static VOID CALLBACK write_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);
	static VOID CALLBACK wait_for_sums_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);

	struct CallbackParameter;
	struct SumsCallbackParameter;

};

#endif //FILELIST_H_
