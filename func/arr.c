#include <stdio.h>
#include <stdlib.h>

/* int a[N] = {1, 2, 3, 4, 5, 6};
 * int *p = a;
 *
 * a	*a	a[0]	&a[3]	p[i]	p	*p	p+1
 *
 * int * int 	int	int *	int	int *	int	int *
 * 
 */


void print_arr(int *arry, int n)
//void print_arr(int arry[], int n)
{
	int i;
	printf("%s:%ld\n", __func__, sizeof(arry));

	for(i = 0; i < n; i++)
		printf("%d ", arry[i]);
	printf("\n");
}

int func(int *p, int n)
{
	int i = 0;
	int m, j, tmp;	

	m = (n-1)/2;

	for(i = 0; i <= m; i++) {
		j = n -1 -i;
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;	
	}
}

int main(void)
{
	int i;
	int a[] = {2, 3, 4, 5 ,6};

	printf("%s:%ld\n", __func__, sizeof(a));

	for(i = 0; i < sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");


	print_arr(a, sizeof(a)/sizeof(*a));

	func(a, sizeof(a)/sizeof(*a));

	for(i = 0; i < sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
