#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr = NULL;
	int num = 0;
	int i = 0;

	printf("请输入待录入整数的个数\n");
	scanf("%d", &num);

	ptr = (int *)malloc(num * sizeof(int));
	if(ptr == NULL) {
		printf("Malloc memory failed!\n");
		return -1;
	}

	printf("请输入录入整数的数值\n");

	for(i = 0; i < num; i++) {
		printf("请输%d个整数\n", i);
		scanf("%d", &ptr[i]);
	}

	printf("输入的整数: \n");

	for(i = 0; i < num; i++) {
		printf("%d\n", ptr[i]);
	}

	return 0;
}
