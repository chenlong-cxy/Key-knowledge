

//结构体的对齐规则：
//1. 第一个成员在与结构体变量偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数
//倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

//对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//VS中默认的值为8
//Linux中的默认值为4

//#include <stdio.h>
//struct S1
//{
//	double d;//8/8->8
//	char c;//1/8->1
//	int i;//4/8->4
//};
//struct S2
//{
//	double d;//8/8->8
//	struct S1 s1;//16/8->8(较小值)
//	int i;//4/8->4
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));//16
//	printf("%d\n", sizeof(struct S2));//32
//	return 0;
//}


//#include <stdio.h>
//struct S1
//{
//	char a;
//	char b;
//	int c;
//};
//struct S2
//{
//	char a;
//	int c;
//	char b;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}


#include <stdio.h>
#pragma pack(4)//设置默认对齐数为4
struct S1
{
	char a;//1/4->1
	int b;//4/4->4
	char c;//1/4->1
};//12
#pragma pack()//取消设置的默认对齐数，还原为默认

#pragma pack(1)//设置默认对齐数为1
struct S2
{
	char a;//1/1->1
	int b;//4/1->1
	char c;//1/1->1
};//6
#pragma pack()//取消设置的默认对齐数，还原为默认

int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	return 0;
}