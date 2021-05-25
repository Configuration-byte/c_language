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

	printf("%d\n", *p);

	free(p);

}
