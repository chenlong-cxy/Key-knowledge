#include "Sort.h"

//打印数组
void PrintArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;//记录有序序列的最后一个元素的下标
		int tmp = a[end + 1];//待插入的元素
		while (end >= 0)
		{
			if (tmp < a[end])//还需继续比较
			{
				a[end + 1] = a[end];
				end--;
			}
			else//找到应插入的位置
			{
				break;
			}
		}
		a[end + 1] = tmp;
		//代码执行到此位置有两种情况:
		//1.待插入元素找到应插入位置（break跳出循环到此）。
		//2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）。
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		//gap = gap / 3 + 1;
		int i = 0;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		printf("gap:%d->", gap);
		PrintArr(a, n);
	}
}

//交换函数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序(一次选一个数)
void SelectSort1(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int start = i;
		int min = start;
		while (start < n)
		{
			if (a[start] < a[min])
				min = start;
			start++;
		}
		Swap(&a[i], &a[min]);
	}
}

//选择排序(一次选两个数)
void SelectSort2(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = left;
		int i = 0;
		for (i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i]>a[maxIndex])
				maxIndex = i;
		}
		Swap(&a[minIndex], &a[left]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[maxIndex], &a[right]);
		left++;
		right--;
	}
}

//堆排序
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//假设左孩子较大
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])//右孩子存在，并且比左孩子大
		{
			child++;//左右孩子的较大值
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;//左孩子
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//排升序，建大堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//冒泡排序
//void BubbleSort(int* a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int exchange = 0;
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}

void BubbleSort(int* a, int n)
{
	int end = 0;
	for (end = n - 1; end >= 0; end--)
	{
		int exchange = 0;
		int i = 0;
		for (i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

//快速排序（递归实现）
//1.hoare

//2.挖坑法

//3.前后指针法

void QuickSort(int* a, int begin, int end)
{
	if (end - begin < 2)
		return;

	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//right走，找小
		while (left < right&&a[right] >= a[keyi])
		{
			right--;
		}
		//left先走，找大
		while (left < right&&a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	int meeti = left;
	Swap(&a[keyi], &a[meeti]);
	QuickSort(a, begin, meeti - 1);
	QuickSort(a, meeti + 1, end);
}