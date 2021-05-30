#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

sqlist *sqlist_create()
{
	sqlist *me;
	
	me = malloc(sizeof(*me));
	if(me == NULL) {
		return NULL;
	}

	me->last = -1;

	return me;
}

void sqlist_create_1(sqlist **ptr)
{
	*ptr = malloc(sizeof(**ptr));	
	if(*ptr == NULL)
		return ;

	(*ptr)->last = -1;

	return ;
}

int sqlist_insert(sqlist *me, int i, datatype *data)
{
	int j;

	if(me->last == DATASIZE - 1)
		return -1;	
	
	if(i < 0 || i > me->last+1)
		return -2;

	j = me->last;
	for(j = me->last; i <= j; j--) {
		me->data[j+1] = me->data[j]; 
	}

	me->data[i] = *data;
	me->last++;

	return 0;
}

#if 0
int sqlist_delete(sqlist *, int i)
{

}

int sqlist_find(sqlist *, datatype *)
{

}

int sqlist_empty(sqlist *)
{

}

int sqlist_setempty(sqlist *)
{

}

int sqlist_getnum(sqlist *)
{

}
#endif
void sqlist_display(sqlist *me)
{
	int i;
	if(me->last == -1)
		return ;	

	for(i = 0; i<= me->last; i++)
		printf("%d ", me->data[i]);
	printf("\n");
	return ;
}

int sqlist_destory(sqlist *me)
{

	free(me);
	return 0;
}

//int sqlist_union(sqlist *, sqlist *)
//{
//
//}

