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
//	printf("%c\n", *p);//��ӡ�ַ�'h'
//	printf("%s\n", p);//��ӡ�ַ���"hello csdn."
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
////����ָ�� - ָ�����͵�ָ��
////�ַ�ָ�� - ָ���ַ���ָ��
////����ָ�� - ָ�������ָ��
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char ch = 'w';
//	char* pc = &ch;
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//	//&arr����ĵ�ַ
//	return 0;
//}
//
//
//int a = 10;//��ȥ������a����������Ϊint
//char ch = 'w';//��ȥ������ch����������Ϊchar
//int* p = NULL;//��ȥ������p����������Ϊint*
//int arr[10] = { 0 };////��ȥ������arr����������Ϊint [10]
//int* arr[10] = { 0 };////��ȥ������arr����������Ϊint* [10]
//int a = 10;
//int* p = &a;//��ȥ������(p)��*������Pָ�������(a)������->int
//char ch = 'w';
//char* pc = &ch;//��ȥ������(pc)��*������pcָ�������(ch)������->char


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p1 = arr;//������Ԫ�صĵ�ַ
//	int(*p2)[5] = &arr;//����ĵ�ַ
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//
//	printf("%p\n", p1+1);
//	printf("%p\n", p2+1);
//	//&������
//	//sizeof(������)
//	//����֮�⣬���е�����������������Ԫ�صĵ�ַ
//	return 0;
//}
//
//
//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	&arr;
//	sizeof(arr);//arr��������sizeof�ڲ�
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
//	for (i = 0; i < row; i++)//����
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//����
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");//��ӡ��һ�к󣬻���
//	}
//}
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	print(arr, 3, 5);//�����ά������������ά������Ԫ�ص�ַ������ά�����һ�еĵ�ַ
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
//	int arr[10] = { 0 };//��������
//	int *arr2[20] = { 0 };//����ָ������
//	test1(arr);
//	test2(arr2);
//}


//#include<stdio.h>
//void test(int arr[][5])
//{}
////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
////��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
////�����ŷ������㡣
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
//	test(&a);//���Դ������ͱ����ĵ�ַ
//	int* p = &a;
//	test(p);//���Դ�������һ��ָ��
//	int arr[10] = { 0 };
//	test(arr);//���Դ�������һά������
//	return 0;
//}


//#include<stdio.h>
//void test(int** p)
//{}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	test(&pa);//���Դ���һ��ָ��ĵ�ַ
//	int** paa = &pa;
//	test(paa);//���Դ������ָ��
//	int* arr[10];
//	test(arr);//���Դ���һ��ָ�������������
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