#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int remove_directory(const char *path)
{
	DIR *d = NULL;
	struct dirent *p = NULL;
	struct stat statbuf;
	size_t path_len = 0, len = 0;
	int ret = -1, flag = -1;
	char *buf = NULL;

	path_len = strlen(path);

	d = opendir(path);
	if(d) {
		ret = 0;
		while(!ret && (p=readdir(d))) {
			flag = -1;

			/* Skip the names "." and ".." as we don't want to recurse on them. */
			if(!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
				continue;

			len = path_len + strlen(p->d_name) + 2; 
			buf = malloc(len);

			if(buf) {
				snprintf(buf, len, "%s/%s", path, p->d_name);
				if(!stat(buf, &statbuf)) {
					if(S_ISDIR(statbuf.st_mode))
						flag = remove_directory(buf);
					else
						flag = unlink(buf);
				}
				free(buf);
			}
			ret = flag;
		}
		closedir(d);
	}

	if(!ret)
		ret = rmdir(path);

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;

	if(argc != 2) {
		printf("Usage: %s <folder path> \n", argv[0]);
		return -1;
	}

	ret = remove_directory(argv[1]);
	if(ret < 0) {
		printf("delete folder failed\n");
		return -1;
	}

	return 0;
}
