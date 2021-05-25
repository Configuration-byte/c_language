#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p;
	int num = 5;
	int i;

	p = malloc(sizeof(int) * num);
	if(p == NULL) {
		printf("malloc err");
		exit(1);
	}

	for(i = 0; i < num; i++)
		scanf("%d", &p[i]);

	for(i = 0; i < num; i++)
		printf("%d ", p[i]);
	printf("\n");

	free(p);

	return 0;
}
