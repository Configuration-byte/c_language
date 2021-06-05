#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc305bad3;
	
	printf("before clear bit15: 0x%lx\n", a);
	
	a &= ~(1 << 15);
	printf("after cler bit15: 0x%lx\n", a);

	return 0;
}
