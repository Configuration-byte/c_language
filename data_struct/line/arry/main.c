#include <stdlib.h>
#include <stdio.h>

#include "sqlist.h"

int main()
{
	sqlist *list = NULL;
	datatype arr[] = {12, 23, 34, 45, 56};
	int i, ret;

	list = sqlist_create();
	if(list == NULL) {
		fprintf(stderr, "sqlist_create() failed\n");
		exit(1);
	} 

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
		if(ret = (sqlist_insert(list, 0, &arr[i])) != 0) 
		{	
			if(ret == -1)
				fprintf(stderr, "%s", "The arr is full\n");
			else if(ret == -2)
				fprintf(stderr, "%s", "position err\n");

			else
				fprintf(stderr, "%s", "Error!\n");
			return -1;
		}

	}


	sqlist_display(list);

	ret = sqlist_delete(list, 1);
	if(ret < 0) {
		printf("delte data failed\n");
		sqlist_destory(list);
		return -1;
	}

	sqlist_display(list);

	sqlist_destory(list);

	return 0;
}
