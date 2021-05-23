#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 32

struct student_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void stu_set(struct student_st *p, struct student_st *src)
{
	*p = *src;
#if 0
	p->id = 10011;
	strncpy(p->name, "Alan", NAMESIZE);
	p->math = 98;
	p->chinese = 97;
#endif
}

void stu_show(struct student_st *p)
{
	printf("%d %s %d %d\n", p->id, p->name, p->math, p->chinese);
}

void stu_changename(struct student_st *p, const char *newname)
{
	strncpy(p->name, newname, NAMESIZE);
}

void menu(void)
{
	printf("1 set\n2 change name\n3 show\n\n");
	printf("Plese enter the num, q for quit");
}

int main()
{
	struct student_st stu, tmp;
	char newname[NAMESIZE];
	int choice, ret;
	
	do{
		menu();

		ret = scanf("%d", &choice);
		if(ret != 1) {
			break;
		}
		switch(choice) {
			case 1:
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
