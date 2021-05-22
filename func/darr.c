#include <stdio.h>
#include <stdlib.h>

/* int a[M][N] = {........}
 *
 * int *p = *a;
 * int (*q)[N] = a;
 *
 * a[i][j]	*(a+i)+j	a[i]+j	p[i]	*p
 * q[i][j]	*q		q	p+3	q+2
 *
 * int		int *		intt *	int	int
 * int		int *		int (*)[N]	int *	int (*)[N]
 *
 */

#define M 3
#define N 4

int print_arr(int *p, int n)
{
	int i;

	printf("%s\n", __func__);
	for(i = 0; i < n; i++) {
		printf("%4d ", p[i]);
	}
	printf("\n");
}

//int print_arr1(int (*p)[N], int m, int n)
int print_arr1(int p[][N], int m, int n)
{

	int i, j;

	printf("%s\n", __func__);
	for(i = 0 ; i < m; i++) {
		for(j = 0; j < n; j++)
			//printf("%4d", *((*p + i) +j));
			printf("%4d", p[i][j]);
		printf("\n");
	}	
}

float average_score(int *p, int n)
{
	int sum = 0;
	int i;

	for(i = 0; i < n; i++) {
		sum += p[i];
	}

	return sum/n;
}

void find_num(int (*p)[N], int num)
{

	int i;

	for(i = 0; i < N; i++) {
		printf("%4d", *(*(p + num) + i));
	}
	printf("\n");
}

int main(void)
{

	int i, j;
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	float aver;

	printf("%s\n", __func__);

//	print_arr(&a[0][0], M*N);// *a	a[0] *(a+0)
//	print_arr1(a, M, N);
	aver = average_score(*a, M*N);
	printf("aver = %f\n", aver);

	find_num(a, 2);

}
