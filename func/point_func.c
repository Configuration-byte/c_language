#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

#if 0
void find_num(int (*p)[N], int num)
{

	int i;

	for(i = 0; i < N; i++) {
		printf("%4d", *(*(p + num) + i));
	}
	printf("\n");
}
#else

int *find_num(int (*p)[N], int num)
{
	if(num > M -1)
		return NULL;
	return *(p + num);
}

#endif

int main(void)
{

	int i, j;
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *res;

	printf("%s\n", __func__);


//	find_num(a, 2);
	res = find_num(a, 2);
	if(res == NULL) {
		printf("Can not find!\n");
		return -1;
	}

	for(i = 0; i < N; i++) {
		printf("%4d ", res[i]);
	}
	printf("\n");

	return 0;
}
