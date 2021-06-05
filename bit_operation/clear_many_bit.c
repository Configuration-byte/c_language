#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc3057ad3;
	
	printf("before clear bit15~bit23: 0x%lx\n", a);
	
	/* 0 0 0 1 1 1 1 1 -> 1 1 1 1 1 0 0 0 */
	a &= ~(0x1ff << 15);
	printf("after set bit15~bit23: 0x%lx\n", a);

	return 0;
}
