#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 32

struct simple_st {
	int i;
	float f;
	char ch;
};

struct birthday_st {
	int year;
	int month;
	int day;
};

struct student_st {
	int id;
	char name[NAME_SIZE];
	struct birthday_st birth;
	int math;
	int chinese;
};

#if 0
struct student_st {
	int id;
	char name[NAME_SIZE];
	struct birthday_st {
		int year;
		int month;
		int day;
	}birth;
	int math;
	int chinese;
};
#endif

int main()
{

	struct student_st stu = {10011, "Aleen", {2010, 11, 11}, 98, 97};
//	struct student_st stu = {.math = 98, .chinese = 97};
	struct student_st *p = &stu;
//	struct student_st arr[2] = {{}, {}};
	
	printf("%d %s %d\n", stu.id, stu.name, stu.birth.year);

#if 0
	struct simple_st a = {123, 456.789, 'a'};

	a.i = 112233;

	printf("%d %f %c\n", a.i, a.f, a.ch);
#endif

	return 0;
}
