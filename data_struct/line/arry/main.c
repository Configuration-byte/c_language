#include <stdlib.h>
#include <stdio.h>

#include "sqlist.h"

int main()
{
	sqlist *list = NULL;
	datatype arr[] = {12, 23, 34, 45, 56};
	int i, err;

	list = sqlist_create();
	if(list == NULL) {
		fprintf(stderr, "sqlist_create() failed\n");
		exit(1);
	} 

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
		if(err = (sqlist_insert(list, 0, &arr[i])) != 0) 
		{	
			if(err == -1)
				fprintf(stderr, "%s", "The arr is full\n");
			else if(err == -2)
				fprintf(stderr, "%s", "position err\n");

			else
				fprintf(stderr, "%s", "Error!\n");
			return -1;
		}

	}


	sqlist_display(list);

	sqlist_destory(list);


}
