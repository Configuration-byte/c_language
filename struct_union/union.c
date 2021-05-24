#include <stdio.h>
#include <stdlib.h>

union test_un {
	int i;
	float f;
	double d;
	char ch;
};

int main(void)
{

	union test_un a;
	union test_un *p = &a;
	union test_un arr[3];

	a.f = 345.678;

	printf("%ld\n", sizeof(a));
	printf("%f\n", a.f);
//	printf("%d\n", a.i);

	return 0;
}
