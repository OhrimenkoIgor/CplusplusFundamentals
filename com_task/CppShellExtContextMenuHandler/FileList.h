
#ifndef FILELIST_H_
#define FILELIST_H_

#include <map>
#include <string>

struct FileInfo;

class FileList{
public:
	typedef std::map<std::wstring, FileInfo> files_map;
	void add_file(const FileInfo & file_info);
	void set_date_for_each_file();
	void set_size_for_each_file();
	void set_sum_for_each_file();

	std::wstring get_readable_list() const;

protected:
	files_map files;
	static void set_time_for_file(files_map::value_type & el);
	static void set_size_for_file(files_map::value_type & el);
};

#endif //FILELIST_H_
