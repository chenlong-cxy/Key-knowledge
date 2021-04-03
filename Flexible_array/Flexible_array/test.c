//#include <stdio.h>
//struct S
//{
//	int n;
//	int arr[];//柔性数组成员
//};
//struct S
//{
//	int n;
//	int arr[0];//柔性数组成员
//};
//struct Er
//{
//	int arr[];
//};//error


//#include <stdio.h>
//struct S
//{
//	int n;
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	//结果为4
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	int n;
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	//开辟
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	char ch;
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	//开辟动态内存空间
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	ps->ch = 'A';
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		//将柔性数组中下标为i的元素赋值为i
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	//调整所开辟的动态内存空间的大小
//	struct S* ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int));
//	if (ptr != NULL)//开辟成功
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		//将柔性数组中下标为i的元素赋值为i
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("%c\n", ps->ch);
//	//释放开辟的动态内存空间
//	free(ps);
//	ps = NULL;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
struct S
{
	char ch;
	int* arr;
};
int main()
{
	//开辟动态内存空间
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = (int*)malloc(5 * sizeof(int));
	ps->ch = 'A';
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
		//将柔性数组中下标为i的元素赋值为i
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//调整所开辟的动态内存空间的大小
	int* ptr = (int*)realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)//开辟成功
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
		//将柔性数组中下标为i的元素赋值为i
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("%c\n", ps->ch);
	//释放开辟的动态内存空间
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}