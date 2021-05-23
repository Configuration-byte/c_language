#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define delete_module(name, flags) syscall(__NR_delete_module, name, flags)

int main(int argc, char **argv)
{
	if(argc != 2) {
		printf("Usage: %s mymodule", argv[0]);
		return -1;
	}

	if(delete_module(argv[1], O_NONBLOCK | O_TRUNC) != 0) {
		perror("delete_module");
		return -1;
	}

	return 0;
}

