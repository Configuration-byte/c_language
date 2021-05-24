#include <bits/stdint-uintn.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#if 0
struct simple_st 
{
	int i;
	char ch;
	union
	{
		int a;
		char c;
	}un;

	float f;
};

union simple_un
{
	int a;
	double d;
	struct 
	{
		int arr[10];
		float f;
	}c;
};
#endif

union 
{
	struct 
	{
		uint16_t i;
		uint16_t j;
	}x;
	uint32_t y;
}a;

int main()
{
	uint32_t i = 0x11223344;

//	printf("%x" ,(i >> 16) + (i & 0xFFFF));
	a.y = 0x11223344;

	printf("%x\n", a.x.i + a.x.j);

	return 0;
}
