#include "Sort.h"

void TestInertSort()
{
	int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	PrintArr(a, sz);
	printf("\n");
}
void TestShellSort()
{
	/*int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };*/
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int sz = sizeof(a) / sizeof(a[0]);
	ShellSort(a, sz);
	PrintArr(a, sz);
	printf("\n");
}
void TestSelectSort1()
{
	int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int sz = sizeof(a) / sizeof(a[0]);
	SelectSort1(a, sz);
	PrintArr(a, sz);
	printf("\n");
}
void TestSelectSort2()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	SelectSort2(a, sz);
	PrintArr(a, sz);
	printf("\n");
}
void TestHeapSort()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	HeapSort(a, sz);
	printf("HeapSort:");
	PrintArr(a, sz);
	printf("\n");
}
void TestBubbleSort()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, sz);
	printf("BubbleSort:");
	PrintArr(a, sz);
	printf("\n");
}
void TestQuickSort()
{
	int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, sz - 1);
	printf("QuickSort:");
	PrintArr(a, sz);
	printf("\n");
}
int main()
{
	TestInertSort();
	TestShellSort();
	TestSelectSort1();
	TestSelectSort2();
	TestHeapSort();
	TestBubbleSort();
	TestQuickSort();
	return 0;
}

////����������
//#include <stdio.h>
////��������
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
////�ѵ����µ�������ѣ�
//void AdjustDown(int* a, int n, int parent)
//{
//	//child��¼���Һ�����ֵ�ϴ�ĺ��ӵ��±�
//	int child = 2 * parent + 1;//��Ĭ�������ӵ�ֵ�ϴ�
//	while (child < n)
//	{
//		if (child + 1 < n&&a[child + 1] > a[child])//�Һ��Ӵ��ڲ����Һ��ӱ����ӻ���
//		{
//			child++;//�ϴ�ĺ��Ӹ�Ϊ�Һ���
//		}
//		if (a[child] > a[parent])//���Һ����нϴ��ӵ�ֵ�ȸ���㻹��
//		{
//			//���������ϴ���ӽ�㽻��
//			Swap(&a[child], &a[parent]);
//			//�������½��е���
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else//�ѳɶ�
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	//�����
//	int i;
//	for (i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	//������
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 23, 43, 56, 87, 12, 34, 54, 87, 23, 83 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}