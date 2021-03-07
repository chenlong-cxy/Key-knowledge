//#include <stdio.h>
//struct A
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}


#include <stdio.h>
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	s.a = 10;//00000000 00000000 00000000 00001010
	s.b = 12;//00000000 00000000 00000000 00001100
	s.c = 3;//00000000 00000000 00000000 00000011
	s.d = 4;//00000000 00000000 00000000 00000100
	return 0;
}