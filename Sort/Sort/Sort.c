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
		gap = gap / 2;//gap折半
		//gap = gap / 3 + 1;
		int i = 0;
		//进行一趟排序
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
		//printf("gap:%d->", gap);
		//PrintArr(a, n);
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
	for (i = 0; i < n; i++)//i代表参与该趟选择排序的第一个元素的下标
	{
		int start = i;
		int min = start;//记录最小元素的下标
		while (start < n)
		{
			if (a[start] < a[min])
				min = start;//最小值的下标更新
			start++;
		}
		Swap(&a[i], &a[min]);//最小值与参与该趟选择排序的第一个元素交换位置
	}
}

//选择排序(一次选两个数)
void SelectSort2(int* a, int n)
{
	int left = 0;//记录参与该趟选择排序的第一个元素的下标
	int right = n - 1;//记录参与该趟选择排序的最后一个元素的下标
	while (left < right)
	{
		int minIndex = left;//记录最小元素的下标
		int maxIndex = left;//记录最大元素的下标
		int i = 0;
		//找出最大值及最小值的下标
		for (i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i]>a[maxIndex])
				maxIndex = i;
		}
		//将最大值和最小值放在序列开头和末尾
		Swap(&a[minIndex], &a[left]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;//防止最大值位于序列开头，被最小值交换
		}
		Swap(&a[maxIndex], &a[right]);
		left++;
		right--;
	}
}

//堆排序
//堆的向下调整算法
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
			child = 2 * parent + 1;
		}
		else//已成堆
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	printf("        ");
	PrintArr(a, n);
	//排升序，建大堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	printf("        ");
	PrintArr(a, n);
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
		int exchange = 0;//记录该趟冒泡排序是否进行过交换
		int i = 0;
		for (i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)//该趟冒泡排序没有进行过交换，已有序
			break;
	}
}

//快速排序（递归实现）
//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}
//快速排序（Hoare版本）
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)//当只有一个数据或是序列不存在时，不需要进行操作
		return;
	//三数取中
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int left = begin;//L
	int right = end;//R
	int keyi = left;//key的下标
	while (left < right)
	{
		//right先走，找小
		while (left < right&&a[right] >= a[keyi])
		{
			right--;
		}
		//left后走，找大
		while (left < right&&a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)//交换left和right的值
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;//L和R的相遇点
	Swap(&a[keyi], &a[meeti]);//交换key和相遇点的值

	QuickSort1(a, begin, meeti - 1);//key的左序列进行此操作
	QuickSort1(a, meeti + 1, end);//key的右序列进行此操作
}
//快速排序（挖坑法）
void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)//当只有一个数据或是序列不存在时，不需要进行操作
		return;

	//三数取中
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int left = begin;//L
	int right = end;//R
	int key = a[left];//在最左边形成一个坑位
	while (left < right)
	{
		//right向左，找小
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		//填坑
		a[left] = a[right];
		//left向右，找大
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		//填坑
		a[right] = a[left];
	}
	int meeti = left;//L和R的相遇点
	a[meeti] = key;//将key抛入坑位

	QuickSort2(a, begin, meeti - 1);//key的左序列进行此操作
	QuickSort2(a, meeti + 1, end);//key的右序列进行此操作
}
//快速排序（前后指针法）
void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)//当只有一个数据或是序列不存在时，不需要进行操作
		return;

	//三数取中
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	while (cur <= end)//当cur未越界时继续
	{
		if (a[cur] < a[keyi] && ++prev != cur)//cur指向的内容小于key
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;//cur越界时，prev的位置
	Swap(&a[keyi], &a[meeti]);//交换key和prev指针指向的内容

	QuickSort3(a, begin, meeti - 1);//key的左序列进行此操作
	QuickSort3(a, meeti + 1, end);//key的右序列进行此操作
}



//快速排序（递归实现）
//Hoare版本（单趟排序）
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;//key的下标
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
		if (left < right)
		{
			Swap(&a[left], &a[right]);//交换left和right的值
		}
	}
	int meeti = left;//L和R的相遇点
	Swap(&a[keyi], &a[meeti]);//交换key和相遇点的值
	return meeti;//返回相遇点，即key的当前位置
}
//挖坑法（单趟排序）
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key = a[left];//在最左边形成一个坑位
	while (left < right)
	{
		//right向左，找小
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		//填坑
		a[left] = a[right];
		//left向右，找大
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		//填坑
		a[right] = a[left];
	}
	int meeti = left;//L和R的相遇点
	a[meeti] = key;//将key抛入坑位
	return meeti;//返回key的当前位置
}
//前后指针法（单趟排序）
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)//当cur未越界时继续
	{
		if (a[cur] < a[keyi] && ++prev != cur)//cur指向的内容小于key
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;//cur越界时，prev的位置
	Swap(&a[keyi], &a[meeti]);//交换key和prev指针指向的内容
	return meeti;//返回key的当前位置
}
//主体
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

//优化后的快速排序
void QuickSort0(int* a, int begin, int end)
{
	if (begin >= end)//当只有一个数据或是序列不存在时，不需要进行操作
		return;

	if (end - begin + 1 > 20)//可自行调整
	{
		//可调用快速排序的单趟排序三种中的任意一种
		//int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		int keyi = PartSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);//key的左序列进行此操作
		QuickSort(a, keyi + 1, end);//key的右序列进行此操作
	}
	else
	{
		//HeapSort(a, end - begin + 1);
		ShellSort(a, end - begin + 1);//当序列长度小于等于20时，使用希尔排序
	}
}

#include "stack.h"
//快速排序（非递归实现）
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;//创建栈
	StackInit(&st);//初始化栈
	StackPush(&st, begin);//待排序列的L
	StackPush(&st, end);//待排序列的R
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);//读取R
		StackPop(&st);//出栈
		int left = StackTop(&st);//读取L
		StackPop(&st);//出栈
		//该处调用的是Hoare版本的单趟排序
		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)//该序列的左序列还需要排序
		{
			StackPush(&st, left);//左序列的L入栈
			StackPush(&st, keyi - 1);//左序列的R入栈
		}
		if (keyi + 1 < right)// 该序列的右序列还需要排序
		{
			StackPush(&st, keyi + 1);//右序列的L入栈
			StackPush(&st, right);//右序列的R入栈
		}
	}
	StackDestroy(&st);//销毁栈
}

//归并排序（子函数）
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)//归并结束条件：当只有一个数据或是序列不存在时，不需要再分解
	{
		return;
	}
	int mid = left + (right - left) / 2;//中间下标
	_MergeSort(a, left, mid, tmp);//对左序列进行归并
	_MergeSort(a, mid + 1, right, tmp);//对右序列进行归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	//将两段子区间进行归并，归并结果放在tmp中
	int i = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//将较小的数据优先放入tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//当遍历完其中一个区间，将另一个区间剩余的数据直接放到tmp的后面
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//归并完后，拷贝回原数组
	int j = 0;
	for (j = left; j <= right; j++)
		a[j] = tmp[j];
}
//归并排序（主体函数）
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//申请一个与原数组大小相同的空间
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);//归并排序
	free(tmp);//释放空间
}


//归并排序（子函数）
void _MergeSortNonR(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int j = begin1;
	//将两段子区间进行归并，归并结果放在tmp中
	int i = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//将较小的数据优先放入tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//当遍历完其中一个区间，将另一个区间剩余的数据直接放到tmp的后面
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//归并完后，拷贝回原数组
	for (; j <= end2; j++)
		a[j] = tmp[j];
}
//归并排序（主体函数）
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//申请一个与待排序列大小相同的空间，用于辅助合并序列
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;//需合并的子序列中元素的个数
	while (gap < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)//最后一组的第二个小区间不存在或是第一个小区间不够gap个，此时不需要对该小组进行合并
				break;
			if (end2 >= n)//最后一组的第二个小区间不够gap个，则第二个小区间的后界变为数组的后界
				end2 = n - 1;
			_MergeSortNonR(a, tmp, begin1, end1, begin2, end2);//合并两个有序序列
		}
		gap = 2 * gap;//下一趟需合并的子序列中元素的个数翻倍
	}
	free(tmp);//释放空间
}

//计数排序
void CountSort(int* a, int n)
{
	int min = a[0];//记录数组中的最小值
	int max = a[0];//记录数组中的最大值
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;//min和max之间的自然数个数（包括min和max本身）
	int* count = (int*)calloc(range, sizeof(int));//开辟可储存range个整型的内存空间，并将内存空间置0
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//统计相同元素出现次数（相对映射）
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	//根据统计结果将序列回收到原来的序列中
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);//释放空间
}