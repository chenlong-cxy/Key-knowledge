//#include<stdio.h>
//int main()
//{
//	//һά����
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16 - ��������Ĵ�С
//	printf("%d\n", sizeof(a + 0));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*a));//4 - ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(a + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(a[1]));//4 - �ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&a));//4/8 - ��������ĵ�ַ
//	printf("%d\n", sizeof(*&a));//16 - ��������Ĵ�С
//	printf("%d\n", sizeof(&a + 1));//4/8 - ��ַ
//	printf("%d\n", sizeof(&a[0]));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(&a[0] + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	//�ַ�����
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	printf("%d\n", sizeof(arr));//6 - ��������Ĵ�С
//	printf("%d\n", sizeof(arr + 0));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*arr));//1 - ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(arr[1]));//1 - �ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr));//4/8 - ����ĵ�ַ
//	printf("%d\n", sizeof(&arr + 1));//4/8 - �������ռ�ĵ�ַ
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//
//	printf("%d\n", strlen(arr));//���ֵ
//	printf("%d\n", strlen(arr + 0));//���ֵ
//	printf("%d\n", strlen(*arr));//error
//	printf("%d\n", strlen(arr[1]));//error
//	printf("%d\n", strlen(&arr));//���ֵ
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//���ֵ
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7 - ��������Ĵ�С
//	printf("%d\n", sizeof(arr + 0));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*arr));//1 - ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(arr[1]));//1 - �ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr));//4/8 - ����ĵ�ַ
//	printf("%d\n", sizeof(&arr + 1));//4/8 - �������ռ�ĵ�ַ
//	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//
//	printf("%d\n", strlen(arr));//6 - �ַ����ĳ���
//	printf("%d\n", strlen(arr + 0));//6 - �ַ�������
//	printf("%d\n", strlen(*arr));//error
//	printf("%d\n", strlen(arr[1]));//error
//	printf("%d\n", strlen(&arr));//6 - �ַ�������
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//5 - �ַ�������-1
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(p + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*p));//1 - ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(p[0]));//1 - ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(&p));//4/8 - ָ��ĵ�ַ
//	printf("%d\n", sizeof(&p + 1));//4/8 - ָ��ĵ�ַ+1
//	printf("%d\n", sizeof(&p[0] + 1));//4/8 - �ڶ���Ԫ�صĵ�ַ
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	printf("%d\n", strlen(*p));//error
//	printf("%d\n", strlen(p[0]));//error
//	printf("%d\n", strlen(&p));//���ֵ
//	printf("%d\n", strlen(&p + 1));//���ֵ
//	printf("%d\n", strlen(&p[0] + 1));//5 - &p[0]->&(*(p+0))->p
//	return 0;
//}


#include<stdio.h>
int main()
{
	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4/8
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4/8 - �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16 - a[3]��ȷ�����;Ϳ��Լ����С
	return 0;
}