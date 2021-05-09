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
	int child = 2 * root + 1;//�������ӽϴ�
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])//�Һ��Ӵ��ڣ����ұ����Ӵ�
		{
			child++;//���Һ��ӵĽϴ�ֵ
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = 2 * root + 1;//����
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