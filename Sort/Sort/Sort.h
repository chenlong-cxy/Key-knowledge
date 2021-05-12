#include <stdio.h>

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

//2.挖坑法

//3.前后指针法

void QuickSort(int* a, int begin, int end);