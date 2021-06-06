#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *arg)
{
	int ret = -1;

	printf("new thread dead\n");
	ret = pthread_detach(pthread_self());
	if(ret < 0) {
		perror("pthread_detach()");
		return NULL;
	}

	return NULL;
}

int main(void)
{
	pthread_t tid;
	int ret = -1;

	if(pthread_create(&tid, NULL, thread_run, "thread1 run...") != 0 ) {
		printf("create thread");
	}
	sleep(1);

	if(pthread_join(tid, NULL) == 0 ) {
		printf("pthread wait success,ret:%d\n",(int )ret);
	} else {
		printf("pthread wait failed\n");
		return -1;
	}

	return 0;
}
