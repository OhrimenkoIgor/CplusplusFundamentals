
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include "main.h"

int listdir(const std::string & dir, std::vector<std::string> &files) {
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if (dirp->d_type == DT_REG) {
			files.push_back(dir + "/" + dirp->d_name);
		}
	}
	closedir(dp);
	return 0;
}

