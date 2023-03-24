//#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char* p = &ch;
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char* p = "hello csdn.";
//	printf("%c\n", *p);//打印字符'h'
//	printf("%s\n", p);//打印字符串"hello csdn."
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello csdn.";
//	char str2[] = "hello csdn.";
//	char *str3 = "hello csdn.";
//	char *str4 = "hello csdn.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}


//int arr1[10];
//char arr2[5];
//int* arr3[5];
//char* arr4[10];
//char** arr5[5];


//#include<stdio.h>
////整型指针 - 指向整型的指针
////字符指针 - 指向字符的指针
////数组指针 - 指向数组的指针
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char ch = 'w';
//	char* pc = &ch;
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//	//&arr数组的地址
//	return 0;
//}
//
//
//int a = 10;//除去变量名a，变量类型为int
//char ch = 'w';//除去变量名ch，变量类型为char
//int* p = NULL;//除去变量名p，变量类型为int*
//int arr[10] = { 0 };////除去变量名arr，变量类型为int [10]
//int* arr[10] = { 0 };////除去变量名arr，变量类型为int* [10]
//int a = 10;
//int* p = &a;//除去变量名(p)和*，便是P指向的内容(a)的类型->int
//char ch = 'w';
//char* pc = &ch;//除去变量名(pc)和*，便是pc指向的内容(ch)的类型->char


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p1 = arr;//数组首元素的地址
//	int(*p2)[5] = &arr;//数组的地址
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//
//	printf("%p\n", p1+1);
//	printf("%p\n", p2+1);
//	//&数组名
//	//sizeof(数组名)
//	//除此之外，所有的数组名都是数组首元素的地址
//	return 0;
//}
//
//
//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	&arr;
//	sizeof(arr);//arr单独放在sizeof内部
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int(*p)[10] = &arr;
//	//*p==arr
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", (*p)[i]);
//		printf("%d ", *(*p + i));
//	}
//	return 0;
//}


//#include<stdio.h>
//void print(int(*p)[5], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)//行数
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//列数
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");//打印完一行后，换行
//	}
//}
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	print(arr, 3, 5);//传入二维数组名，即二维数组首元素地址，即二维数组第一行的地址
//	return 0;
//}


//#include<stdio.h>
//void test1(int arr[])//test1-1
//{}
//void test1(int arr[10])//test1-2
//{}
//void test1(int *arr)//test1-3
//{}
//void test2(int *arr[20])//test2-1
//{}
//void test2(int **arr)//test2-2
//{}
//int main()
//{
//	int arr[10] = { 0 };//整型数组
//	int *arr2[20] = { 0 };//整型指针数组
//	test1(arr);
//	test2(arr2);
//}


//#include<stdio.h>
//void test(int arr[][5])
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int(*arr)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}


//#include<stdio.h>
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	print(p, sz);
//	return 0;
//}


//#include<stdio.h>
//void test(int* p)
//{}
//int main()
//{
//	int a = 10;
//	test(&a);//可以传入整型变量的地址
//	int* p = &a;
//	test(p);//可以传入整型一级指针
//	int arr[10] = { 0 };
//	test(arr);//可以传入整型一维数组名
//	return 0;
//}


//#include<stdio.h>
//void test(int** p)
//{}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	test(&pa);//可以传入一级指针的地址
//	int** paa = &pa;
//	test(paa);//可以传入二级指针
//	int* arr[10];
//	test(arr);//可以传入一级指针数组的数组名
//	return 0;
//}


#include <stdio.h>

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	printf("%d\n", *(arr + 1));
	printf("%d\n", *(&arr + 1));
	printf("%x\n", arr);
	printf("%x\n", &arr);
	return 0;
}