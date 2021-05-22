#include <stdio.h>
#include <stdlib.h>

#if 0
int print_value(int a, int b)
{
	printf("a = %d b = %d\n", a, b);
	return 0;
}
#endif

void swap(int *p1, int *p2)
{
	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main(void)
{
	int i = 3, j = 5;

	swap(&i, &j);

	printf("i = %d j = %d\n", i, j);

	return 0;
}
