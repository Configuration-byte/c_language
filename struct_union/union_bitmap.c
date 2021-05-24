#include <stdio.h>
#include <stdlib.h>

union 
{
	struct 
	{
		char a:1;
		char b:2;
		char c:1;
	}x;
	char y;
}w;

int main(void)
{
	w.y = 1;


	printf("%ld\n", sizeof(w));

	printf("%d\n", w.x.a);

	return 0;
}
