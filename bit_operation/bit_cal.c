#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc305bad3;
	unsigned int temp = 0;

	printf("before get bit7~17 and add 17 a = 0x%x\n", a);
	temp = a & (0x7ff << 7);
	a &= (~(0x7ff << 7));

	temp >>= 7;
	temp += 17;
	temp <<= 7;

	a |= temp;
	printf("after get bit7~17 and add 17 a = 0x%x\n", a);

	return 0;
}
