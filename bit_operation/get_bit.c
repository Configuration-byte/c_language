#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc3057ad3;
	unsigned int temp = 0;
	
	printf("before get bit3~bit8: 0x%x\n", a);
	
	/* 0 0 0 1 1 1 1 1 1 -> 1 1 1 1 1 1 0 0 0 */
	temp = a & (0x3f << 3);
	temp >>= 3;

	printf("after get bit3~bit8: 0x%x\n", temp);

	return 0;
}
