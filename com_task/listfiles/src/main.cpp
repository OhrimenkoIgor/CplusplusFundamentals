
#include <iostream>
#include <sstream>

#include <errno.h>
#include <stdio.h>

#include <FileUtils.h>
#include <FileList.h>
#include <FileListCreator.h>

#include "main.h"

using namespace std;

int main(int argc, char *argv[]) {


	if(argc > 2){
		cerr << "Usage: " << argv[0] << " [dirname]" << endl;
		exit(EXIT_FAILURE);
	}
	string dir = (argc == 2) ? argv[1] : ".";

	vector<string> files = vector<string>();
	int s = listdir(dir, files);
	if (s != 0){
		perror((string("Error opening ") + dir).c_str());
		exit(EXIT_FAILURE);
	}

	FileList * fl = FileListCreator::getFileList();
	for (unsigned int i = 0; i < files.size(); i++) {
		fl->add_file(FileInfo(FileUtils::str2wstr(files[i])));
	}

	fl->fill_files_info_and_file();

	wcout << fl->get_readable_list() << endl;

	return 0;
}
