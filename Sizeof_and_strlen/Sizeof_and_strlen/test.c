//#include<stdio.h>
//int main()
//{
//	//一维数组
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16 - 整个数组的大小
//	printf("%d\n", sizeof(a + 0));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(*a));//4 - 首元素的大小
//	printf("%d\n", sizeof(a + 1));//4/8 - 第二个元素的地址
//	printf("%d\n", sizeof(a[1]));//4 - 第二个元素的大小
//	printf("%d\n", sizeof(&a));//4/8 - 整个数组的地址
//	printf("%d\n", sizeof(*&a));//16 - 整个数组的大小
//	printf("%d\n", sizeof(&a + 1));//4/8 - 地址
//	printf("%d\n", sizeof(&a[0]));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(&a[0] + 1));//4/8 - 第二个元素的地址
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	//字符数组
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	printf("%d\n", sizeof(arr));//6 - 整个数组的大小
//	printf("%d\n", sizeof(arr + 0));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(*arr));//1 - 首元素的大小
//	printf("%d\n", sizeof(arr[1]));//1 - 第二个元素的大小
//	printf("%d\n", sizeof(&arr));//4/8 - 数组的地址
//	printf("%d\n", sizeof(&arr + 1));//4/8 - 数组后面空间的地址
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 第二个元素的地址
//
//	printf("%d\n", strlen(arr));//随机值
//	printf("%d\n", strlen(arr + 0));//随机值
//	printf("%d\n", strlen(*arr));//error
//	printf("%d\n", strlen(arr[1]));//error
//	printf("%d\n", strlen(&arr));//随机值
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//随机值
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7 - 整个数组的大小
//	printf("%d\n", sizeof(arr + 0));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(*arr));//1 - 首元素的大小
//	printf("%d\n", sizeof(arr[1]));//1 - 第二个元素的大小
//	printf("%d\n", sizeof(&arr));//4/8 - 数组的地址
//	printf("%d\n", sizeof(&arr + 1));//4/8 - 数组后面空间的地址
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 第二个元素的地址
//
//	printf("%d\n", strlen(arr));//6 - 字符串的长度
//	printf("%d\n", strlen(arr + 0));//6 - 字符串长度
//	printf("%d\n", strlen(*arr));//error
//	printf("%d\n", strlen(arr[1]));//error
//	printf("%d\n", strlen(&arr));//6 - 字符串长度
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//5 - 字符串长度-1
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(p + 1));//4/8 - 第二个元素的地址
//	printf("%d\n", sizeof(*p));//1 - 首元素的大小
//	printf("%d\n", sizeof(p[0]));//1 - 首元素的大小
//	printf("%d\n", sizeof(&p));//4/8 - 指针的地址
//	printf("%d\n", sizeof(&p + 1));//4/8 - 指针的地址+1
//	printf("%d\n", sizeof(&p[0] + 1));//4/8 - 第二个元素的地址
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	printf("%d\n", strlen(*p));//error
//	printf("%d\n", strlen(p[0]));//error
//	printf("%d\n", strlen(&p));//随机值
//	printf("%d\n", strlen(&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//5 - &p[0]->&(*(p+0))->p
//	return 0;
//}


#include<stdio.h>
int main()
{
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4/8
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4/8 - 第二行的地址
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16 - a[3]明确了类型就可以计算大小
	return 0;
}