#include <stdio.h>
#include <stdlib.h>

#define M 3

int main(void)
{
	int  i = 0;
	int arr[M] = {1,3,3};


	printf("sizeof arr: %ld\n", sizeof(arr));
	printf("arr = %p\n", arr);

/*
	for(i = 0; i < M; i++)
		scanf("%d", &arr[i]);
*/
	for(i = 0; i < M; i++)
		printf("%p --> %d\n", &arr[i], arr[i]);


	return 0;
}
