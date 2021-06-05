#include <stdio.h>

int func_a()
{
	int a = 10;
	return a; //允许
}

int *func_b()
{
	int a = 10;
	return &a; //无意义，不应该这样做
}

int main(void)
{
	int a = 0;

	/* true */
	a = func_a();
	
	printf("%s: a = %d\n", __func__, a);

	return 0; 
}
