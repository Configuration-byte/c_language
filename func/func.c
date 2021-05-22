#include <stdio.h>
#include <stdlib.h>

int print_value(int a, int b)
{
	printf("a = %d b = %d\n", a, b);
	return 0;
}

int main(void)
{
	int i = 3, j = 5;

	print_value(i, j);

	return 0;
}
