#include <stdio.h>
#include <stdlib.h>

#if 0
void func(int **p, int num)
{
	*p = malloc(sizeof(int) * num);
	if(*p == NULL)
		exit(1);
	return ;
}
#endif

void *func(int *p, int num)
{
	p = malloc(sizeof(int) * num);
	if(p == NULL)
		exit(1);
	return p;
}


int main(void)
{

	int num;
	int *p = NULL;

//	func(&p, num);
	p = func(p, num);

	free(p);

	return 0;
}
