#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc3057ad3;
	
	printf("before set bit3: 0x%lx\n", a);
	
	/* 0 0 0 1 1 1 1 1 -> 1 1 1 1 1 0 0 0 */
	a |= (0x1f << 3);
	printf("after set bit3: 0x%lx\n", a);

	return 0;
}
