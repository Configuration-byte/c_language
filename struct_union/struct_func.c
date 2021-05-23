#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 32

struct simple_st {
	int i;
	float f;
	char ch;
};

#if 0
struct simple_st {
	int i;
	float f;
	char ch;
}__attribute__((packed));
#endif

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

void func_1(struct simple_st b)
{
	printf("%ld\n", sizeof(b));
}

void func_2(struct simple_st *b)
{
	printf("%ld\n", sizeof(b));
}

// addr % sizeof(type)
int main()
{

	struct simple_st a;
	struct simple_st *p = &a;

	printf("sieof(struct) = %ld \n", sizeof(a));

	func_1(a);
	func_2(p);

	return 0;
}
