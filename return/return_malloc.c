#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mymalloc(int num)
{
	char *p = (char *)malloc(sizeof(char) * num);
	strcpy(p, "my malloc");
	return p;
}
int main(void)
{
	char *str = NULL;

	str = mymalloc(100);

	printf("%s: %s\n", __func__, str);
	free(str);
}
