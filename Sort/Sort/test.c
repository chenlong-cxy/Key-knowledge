#include "Sort.h"

void TestInertSort()
{
	int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	printf("InsertSort:");
	PrintArr(a, sz);
	printf("\n");
}
void TestShellSort()
{
	/*int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };*/
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int sz = sizeof(a) / sizeof(a[0]);
	ShellSort(a, sz);
	printf("ShellSort:");
	PrintArr(a, sz);
	printf("\n");
}
void TestSelectSort1()
{
	int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int sz = sizeof(a) / sizeof(a[0]);
	SelectSort1(a, sz);
	printf("SelectSort1:");
	PrintArr(a, sz);
	printf("\n");
}
void TestSelectSort2()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	SelectSort2(a, sz);
	printf("SelectSort2:");
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
void TestQuickSort1()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 6, 1, 2, 5, 9, 3, 4, 7, 10, 8 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort1(a, 0, sz - 1);
	printf("QuickSort1:");
	PrintArr(a, sz);
	printf("\n");
}
void TestQuickSort2()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 6, 1, 2, 5, 9, 3, 4, 7, 10, 8 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort2(a, 0, sz - 1);
	printf("QuickSort2:");
	PrintArr(a, sz);
	printf("\n");
}
void TestQuickSort3()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 6, 1, 2, 5, 9, 3, 4, 7, 10, 8 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort3(a, 0, sz - 1);
	printf("QuickSort3:");
	PrintArr(a, sz);
	printf("\n");
}
void TestQuickSort()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 6, 1, 2, 5, 9, 3, 4, 7, 10, 8 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, sz - 1);
	printf("QuickSort:");
	PrintArr(a, sz);
	printf("\n");
}
void TestMergeSort()
{
	//int a[] = { 23, 43, 56, 98, 12, 34, 54, 87, 23, 83 };
	int a[] = { 6, 1, 2, 5, 9, 3, 4, 7, 10, 8 };
	//int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	int sz = sizeof(a) / sizeof(a[0]);
	MergeSort(a, sz);
	printf("MergeSort:");
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
	TestQuickSort1();
	TestQuickSort2();
	TestQuickSort3();
	TestQuickSort();
	printf("三数取中未测试！\n");
	TestMergeSort();
	return 0;
}