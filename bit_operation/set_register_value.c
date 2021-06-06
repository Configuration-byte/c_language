#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0x305bad3;

	printf("before set bit7~bit17 as 937: 0x%x\n", a);

	a &= ~(0x7ff << 7);
	a |= (937 << 7);

	printf("after set bit7~bit17 as 937: 0x%x\n", a);

	return 0;
}
