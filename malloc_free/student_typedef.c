#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAMEMAX 1024

typedef struct student_st {
	int id;
	char *name;
	int math;
	int chinese;
}STU;

void stu_set(STU *p, STU *src)
{
	p->id = src->id;
	p->name = malloc(strlen(src->name) + 1);
	if(p->name == NULL) {
		exit(1);
	}
	strcpy(p->name, src->name);

	p->math = src->math;
	p->chinese = src->chinese;
#if 0
	p->id = 10011;
	strncpy(p->name, "Alan", NAMESIZE);
	p->math = 98;
	p->chinese = 97;
#endif
}

void stu_show(STU *p)
{
	printf("%d %s %d %d\n", p->id, p->name, p->math, p->chinese);
}

void stu_changename(STU *p, const char *newname)
{
	free(p->name);
	p->name = malloc(strlen(newname) + 1);
	strcpy(p->name, newname);
}

void menu(void)
{
	printf("1 set\n2 change name\n3 show\n\n");
	printf("Plese enter the num, q for quit");
}

int main()
{
	STU stu, tmp;
	char newname[NAMEMAX];
	int choice, ret;
	
	do{
		menu();

		ret = scanf("%d", &choice);
		if(ret != 1) {
			break;
		}
		switch(choice) {
			case 1:
				tmp.name = malloc(NAMEMAX);
				printf("Please input data\n");
				scanf("%d%s%d%d", &tmp.id, tmp.name, &tmp.math, &tmp.chinese);


				stu_set(&stu, &tmp);
				break;
			case 2:
				printf("Please input new name");
				scanf("%s", newname);

				stu_changename(&stu, newname);
				break;

			case 3:
				stu_show(&stu);
				break;

			default:
				return -1;

		}
		sleep(1);
	}while(1);

	return 0;
}
