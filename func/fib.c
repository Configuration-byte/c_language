#include <stdio.h>
#include <stdlib.h>

// 1,1,2,3,5,8,13,21,34
// n = (n -1) + (n-2)
// n-1 = (n - 1 -1) + (n -1 -2)
// n-2 = (n - 2 -1) + (n -2 -2)

int fib(int n)
{
	if(n < 1)
		return -1;

	if(n ==1 || n ==2)
		return 1;

	return fib(n-1) + fib(n-2);
}

int main()
{
	int n;
	int res;

	scanf("%d", &n);

	res = fib(n);

	printf("fib[%d] = %d\n", n, res);
}
