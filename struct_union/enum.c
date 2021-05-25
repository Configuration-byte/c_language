#include <stdio.h>
#include <stdlib.h>

enum day
{
	MON = 1,
	TUS,
	THR,
	WES,
	FRI,
	SAT,
	SUN
};

enum
{
	STATE_RUNNING = 1,
	STATE_CANCELED,
	STATE_OVER
};

struct job_st
{
	int id;
	int state;
};

int main(void)
{	
#if 0
	enum day a = MON;

	printf("%d\n", a);
#endif

	struct job_st job1;

	switch(job1.state)
	{
		case STATE_RUNNING:
			printf("TASK_RUNNINGA");
			break;
		case STATE_CANCELED:
			printf("TASK_CANCELED");
			break;
		case STATE_OVER:
			printf("TASK_OVER");
			break;
		default:
			abort();
	}

	return 0;
}
