#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned int a = 0xc305bad3;
    
	printf("before a = 0x%x\n", a);
#if 0
	a &= (~(0x7ff << 7));
	a |= (937 << 7);

	a &= (~(0x1f << 21));
	a |= (17 << 21);
#endif

	a &= (~(0x7ff << 7)) &(~(0x1f << 21));
    	a |=(937 << 7) | (17 << 21);
    
	printf("after a = 0x%x\n", a);

	return 0;
}
