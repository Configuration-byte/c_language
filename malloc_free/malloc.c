#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	p = malloc(sizeof(int));
	if(p ==NULL) {
		printf("malloc() error\n");
		exit(1);
	}

	*p = 10;

	printf("%p --> %d\n", p, *p);

	free(p);

#if 0
	p = NULL;

	*p = 123;
	printf("%p --> %d\n", p, *p);
#endif

	return 0;
}
