
#ifndef FILELIST_H_
#define FILELIST_H_

#include <map>
#include <string>
#include <Windows.h>

struct FileInfo;

/*
	Container for processing file pathes, retreiving and storing information about files
*/
class FileList{
public:
	typedef std::map<std::wstring, FileInfo> files_map;

	/*
		Adds file infor structure to container
	*/
	void add_file(const FileInfo & file_info);

	/*
		Procceses each file in container and fills creation date field
	*/
	void set_date_for_each_file();

	/*
		Procceses each file in container and fills file size field
	*/
	void set_size_for_each_file();

	/*
		Procceses each file in container and fills check sum field.
		A thread is created for every file
	*/
	void set_sum_for_each_file();

	/*
		Returns info about all files (one line pper file) in a wstring object
	*/
	std::wstring get_readable_list() const;

	/*
		Procceses each file in container and fills date, size and sum fields.
		Creates a thread pull with one task per file (two threads)
	*/
	void fill_files_info_and_file();

protected:

	/*
		std::map<std::wstring, FileInfo>
		filename is a key
	*/
	files_map files;

	static void set_time_for_file(files_map::value_type & el);
	static void set_size_for_file(files_map::value_type & el);
	static VOID CALLBACK fill_file_info_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WORK Work);
	static VOID CALLBACK wait_for_sums_callback(PTP_CALLBACK_INSTANCE Instance, PVOID Parameter, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);

	struct CallbackParameter;
	struct SumsCallbackParameter;

};

#endif //FILELIST_H_
