#include <stdio.h>

char *returnStr()
{
	static char p[] = "hello world!";
	return p;
}

int main()
{
	char *str;

	str=returnStr();
	printf("%s\n", str);

	return 0;
}
