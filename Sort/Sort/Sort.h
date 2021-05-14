#include <stdio.h>
#include <stdlib.h>

//打印数组
void PrintArr(int* a, int n);
//插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);

//选择排序(一次选一个数)
void SelectSort1(int* a, int n);
//选择排序(一次选两个数)
void SelectSort2(int* a, int n);

//堆排序
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序（递归实现）
//1.hoare
void QuickSort1(int* a, int begin, int end);
//2.挖坑法
void QuickSort2(int* a, int begin, int end);
//3.前后指针法
void QuickSort3(int* a, int begin, int end);

//快速排序（递归实现）
//1.hoare
int PartSort1(int* a, int left, int right);
//2.挖坑法
int PartSort2(int* a, int left, int right);
//3.前后指针法
int PartSort3(int* a, int left, int right);
//主体
void QuickSort(int* a, int begin, int end);
//主体(小区间优化)
void QuickSort0(int* a, int begin, int end);

//快速排序（非递归实现）
void QuickSortNonR(int* a, int begin, int end);

//归并排序（递归实现）
void MergeSort(int* a, int n);
//归并排序（非递归实现）
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);