#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define init_module(mod, len, opts) syscall(__NR_init_module, mod, len, opts)

int main(int argc, char **argv)
{
	int fd = 0, ret = 0;
	struct stat st;
	void *image = NULL;
	size_t image_size = 0;
	const char *params = NULL;

	if (argc < 2) {
		puts("Usage ./prog mymodule.ko [args]");
		return EXIT_FAILURE;
	}

	if (argc < 3) {
		params = "";
	} else {
		params = argv[2];
	}

	fd = open(argv[1], O_RDONLY);
	if(fd < 0) {
		perror("opne()");
		return -1;
	}

	ret = fstat(fd, &st);
	if(ret < 0) {
		perror("fstat()");
		return -1;
	}

	image_size = st.st_size;
	image = malloc(image_size);
	if(image == NULL) {
		printf("Malloc memory falied!");
		return -1;
	}

	ret = read(fd, image, image_size);
	if(ret < 0) {
		printf("read()");
		close(fd);
		free(image);
		return -1;
	}

	close(fd);
	if(init_module(image, image_size, params) != 0) {
		perror("init_module");
		return -1;
	}

	free(image);

	return 0;
}
