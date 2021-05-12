#include "Sort.h"

//��ӡ����
void PrintArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;//��¼�������е����һ��Ԫ�ص��±�
		int tmp = a[end + 1];//�������Ԫ��
		while (end >= 0)
		{
			if (tmp < a[end])//��������Ƚ�
			{
				a[end + 1] = a[end];
				end--;
			}
			else//�ҵ�Ӧ�����λ��
			{
				break;
			}
		}
		a[end + 1] = tmp;
		//����ִ�е���λ�����������:
		//1.������Ԫ���ҵ�Ӧ����λ�ã�break����ѭ�����ˣ���
		//2.������Ԫ�رȵ�ǰ���������е�����Ԫ�ض�С��whileѭ�������󵽴ˣ���
	}
}

//ϣ������
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

//��������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������(һ��ѡһ����)
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

//ѡ������(һ��ѡ������)
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

//������
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//�������ӽϴ�
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])//�Һ��Ӵ��ڣ����ұ����Ӵ�
		{
			child++;//���Һ��ӵĽϴ�ֵ
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;//����
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//�����򣬽����
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

//ð������
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

//�������򣨵ݹ�ʵ�֣�
//1.hoare
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//right���ߣ���С
		while (left < right&&a[right] >= a[keyi])
		{
			right--;
		}
		//left���ߣ��Ҵ�
		while (left < right&&a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;
	Swap(&a[keyi], &a[meeti]);

	QuickSort1(a, begin, meeti - 1);
	QuickSort1(a, meeti + 1, end);
}
//2.�ڿӷ�
void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin;
	int right = end;
	int key = a[left];
	while (left < right)
	{
		//right������С
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		//���
		a[left] = a[right];
		//left���ң��Ҵ�
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		//���
		a[right] = a[left];
	}
	int meeti = left;
	a[meeti] = key;

	QuickSort2(a, begin, meeti - 1);
	QuickSort2(a, meeti + 1, end);
}
//3.ǰ��ָ�뷨
void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]);

	QuickSort3(a, begin, meeti - 1);
	QuickSort3(a, meeti + 1, end);
}



//�������򣨵ݹ�ʵ�֣�
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
//1.hoare
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	while (left < right)
	{
		//right�ߣ���С
		while (left < right&&a[right] >= a[keyi])
		{
			right--;
		}
		//left���ߣ��Ҵ�
		while (left < right&&a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}
//2.�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key = a[left];
	while (left < right)
	{
		//right������С
		while (left < right&&a[right] >= key)
		{
			right--;
		}
		//���
		a[left] = a[right];
		//left���ң��Ҵ�
		while (left < right&&a[left] <= key)
		{
			left++;
		}
		//���
		a[right] = a[left];
	}
	int meeti = left;
	a[meeti] = key;
	return meeti;
}
//3.ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}
//����
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