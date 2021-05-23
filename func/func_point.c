#include <stdio.h>
#include <stdlib.h>

int func_add(int a, int b)
{
	return a + b;
}

int func_sub(int a, int b)
{
	return a - b;
}
int main(void)
{
	int a = 3, b = 5;
	int ret = 0;
	int i = 0;
//	int (*p)(int, int);
	
	int (*funcp[2])(int, int);

	funcp[0] = func_add;
	funcp[1] = func_sub;

	for(i = 0; i < 2; i++) {
		ret = funcp[i](a, b);
		printf("ret = %d\n", ret);
	}

#if 0
	p = func_add;

	ret = func_add(a, b);

	ret = p(a, b);

	printf("a + b = %d\n", ret);
#endif
	return 0;

}
