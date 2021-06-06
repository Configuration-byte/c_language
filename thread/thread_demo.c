#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

char buf[100] = {0};

void *func(void *arg)
{
	int ret = 0;

	while(1) {
		memset(buf, 0, sizeof(buf));
		printf("before read.\n");
		ret = read(0, buf, 5);
		if(ret < 0) {
			perror("open()");
		}
		printf("读出键盘的内容是：[%s].\n", buf);
	}
}

int main(void)
{
	int fd = -1;
	int ret = -1;

	pthread_t th = -1;
	/* 创建线程 */
	ret = pthread_create(&th, NULL, func, NULL);
	if(ret !=0) {
		perror("pthread_create error.\n");
		return -1;
	}
	//因为主线程是while(1)死循环，所以可以在这里pthread_create分离子线程
	//主任务
	fd = open("/dev/input/mouse0", O_RDONLY);
	if(fd < 0) {
		perror("open error.\n");
		return -1;
	}
	while(1) {
	/* 读鼠标 */
		memset(buf, 0, sizeof(buf));
		ret = read(fd, buf, 50);
		if(ret > 0) {
			printf("鼠标读出的内容是：[%s].\n", buf);
		}
	}
	return 0;
}
