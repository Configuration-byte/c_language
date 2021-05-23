#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 32

#if 0
struct simple_st {
	int i;
	float f;
	char ch;
};
#endif

struct simple_st {
	int i;
	float f;
	char ch;
}__attribute__((packed));

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

// addr % sizeof(type)
int main()
{

	struct simple_st a;
	struct simple_st *p = &a;

	printf("sieof(struct) = %ld \n", sizeof(a));

	return 0;
}
