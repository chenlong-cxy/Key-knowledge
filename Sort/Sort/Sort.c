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
		gap = gap / 2;//gap�۰�
		//gap = gap / 3 + 1;
		int i = 0;
		//����һ������
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
	for (i = 0; i < n; i++)//i����������ѡ������ĵ�һ��Ԫ�ص��±�
	{
		int start = i;
		int min = start;//��¼��СԪ�ص��±�
		while (start < n)
		{
			if (a[start] < a[min])
				min = start;//��Сֵ���±����
			start++;
		}
		Swap(&a[i], &a[min]);//��Сֵ��������ѡ������ĵ�һ��Ԫ�ؽ���λ��
	}
}

//ѡ������(һ��ѡ������)
void SelectSort2(int* a, int n)
{
	int left = 0;//��¼�������ѡ������ĵ�һ��Ԫ�ص��±�
	int right = n - 1;//��¼�������ѡ����������һ��Ԫ�ص��±�
	while (left < right)
	{
		int minIndex = left;//��¼��СԪ�ص��±�
		int maxIndex = left;//��¼���Ԫ�ص��±�
		int i = 0;
		//�ҳ����ֵ����Сֵ���±�
		for (i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
				minIndex = i;
			if (a[i]>a[maxIndex])
				maxIndex = i;
		}
		//�����ֵ����Сֵ�������п�ͷ��ĩβ
		Swap(&a[minIndex], &a[left]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;//��ֹ���ֵλ�����п�ͷ������Сֵ����
		}
		Swap(&a[maxIndex], &a[right]);
		left++;
		right--;
	}
}

//������
//�ѵ����µ����㷨
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
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
		{
			break;
		}
	}
}
//������
void HeapSort(int* a, int n)
{
	printf("        ");
	PrintArr(a, n);
	//�����򣬽����
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
		int exchange = 0;//��¼����ð�������Ƿ���й�����
		int i = 0;
		for (i = 0; i < end; i++)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)//����ð������û�н��й�������������
			break;
	}
}

//�������򣨵ݹ�ʵ�֣�
//����ȡ��
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
//��������Hoare�汾��
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)//��ֻ��һ�����ݻ������в�����ʱ������Ҫ���в���
		return;
	//����ȡ��
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int left = begin;//L
	int right = end;//R
	int keyi = left;//key���±�
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
		if (left < right)//����left��right��ֵ
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;//L��R��������
	Swap(&a[keyi], &a[meeti]);//����key���������ֵ

	QuickSort1(a, begin, meeti - 1);//key�������н��д˲���
	QuickSort1(a, meeti + 1, end);//key�������н��д˲���
}
//���������ڿӷ���
void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)//��ֻ��һ�����ݻ������в�����ʱ������Ҫ���в���
		return;

	//����ȡ��
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int left = begin;//L
	int right = end;//R
	int key = a[left];//��������γ�һ����λ
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
	int meeti = left;//L��R��������
	a[meeti] = key;//��key�����λ

	QuickSort2(a, begin, meeti - 1);//key�������н��д˲���
	QuickSort2(a, meeti + 1, end);//key�������н��д˲���
}
//��������ǰ��ָ�뷨��
void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)//��ֻ��һ�����ݻ������в�����ʱ������Ҫ���в���
		return;

	//����ȡ��
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midIndex]);

	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	while (cur <= end)//��curδԽ��ʱ����
	{
		if (a[cur] < a[keyi] && ++prev != cur)//curָ�������С��key
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;//curԽ��ʱ��prev��λ��
	Swap(&a[keyi], &a[meeti]);//����key��prevָ��ָ�������

	QuickSort3(a, begin, meeti - 1);//key�������н��д˲���
	QuickSort3(a, meeti + 1, end);//key�������н��д˲���
}



//�������򣨵ݹ�ʵ�֣�
//Hoare�汾����������
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;//key���±�
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
			Swap(&a[left], &a[right]);//����left��right��ֵ
		}
	}
	int meeti = left;//L��R��������
	Swap(&a[keyi], &a[meeti]);//����key���������ֵ
	return meeti;//���������㣬��key�ĵ�ǰλ��
}
//�ڿӷ�����������
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int key = a[left];//��������γ�һ����λ
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
	int meeti = left;//L��R��������
	a[meeti] = key;//��key�����λ
	return meeti;//����key�ĵ�ǰλ��
}
//ǰ��ָ�뷨����������
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)//��curδԽ��ʱ����
	{
		if (a[cur] < a[keyi] && ++prev != cur)//curָ�������С��key
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;//curԽ��ʱ��prev��λ��
	Swap(&a[keyi], &a[meeti]);//����key��prevָ��ָ�������
	return meeti;//����key�ĵ�ǰλ��
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

//�Ż���Ŀ�������
void QuickSort0(int* a, int begin, int end)
{
	if (begin >= end)//��ֻ��һ�����ݻ������в�����ʱ������Ҫ���в���
		return;

	if (end - begin + 1 > 20)//�����е���
	{
		//�ɵ��ÿ�������ĵ������������е�����һ��
		//int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		int keyi = PartSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);//key�������н��д˲���
		QuickSort(a, keyi + 1, end);//key�������н��д˲���
	}
	else
	{
		//HeapSort(a, end - begin + 1);
		ShellSort(a, end - begin + 1);//�����г���С�ڵ���20ʱ��ʹ��ϣ������
	}
}

#include "stack.h"
//�������򣨷ǵݹ�ʵ�֣�
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;//����ջ
	StackInit(&st);//��ʼ��ջ
	StackPush(&st, begin);//�������е�L
	StackPush(&st, end);//�������е�R
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);//��ȡR
		StackPop(&st);//��ջ
		int left = StackTop(&st);//��ȡL
		StackPop(&st);//��ջ
		//�ô����õ���Hoare�汾�ĵ�������
		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)//�����е������л���Ҫ����
		{
			StackPush(&st, left);//�����е�L��ջ
			StackPush(&st, keyi - 1);//�����е�R��ջ
		}
		if (keyi + 1 < right)// �����е������л���Ҫ����
		{
			StackPush(&st, keyi + 1);//�����е�L��ջ
			StackPush(&st, right);//�����е�R��ջ
		}
	}
	StackDestroy(&st);//����ջ
}

//�鲢�����Ӻ�����
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)//�鲢������������ֻ��һ�����ݻ������в�����ʱ������Ҫ�ٷֽ�
	{
		return;
	}
	int mid = left + (right - left) / 2;//�м��±�
	_MergeSort(a, left, mid, tmp);//�������н��й鲢
	_MergeSort(a, mid + 1, right, tmp);//�������н��й鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	//��������������й鲢���鲢�������tmp��
	int i = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//����С���������ȷ���tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//������������һ�����䣬����һ������ʣ�������ֱ�ӷŵ�tmp�ĺ���
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//�鲢��󣬿�����ԭ����
	int j = 0;
	for (j = left; j <= right; j++)
		a[j] = tmp[j];
}
//�鲢�������庯����
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//����һ����ԭ�����С��ͬ�Ŀռ�
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);//�鲢����
	free(tmp);//�ͷſռ�
}


//�鲢�����Ӻ�����
void _MergeSortNonR(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int j = begin1;
	//��������������й鲢���鲢�������tmp��
	int i = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//����С���������ȷ���tmp
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	//������������һ�����䣬����һ������ʣ�������ֱ�ӷŵ�tmp�ĺ���
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	//�鲢��󣬿�����ԭ����
	for (; j <= end2; j++)
		a[j] = tmp[j];
}
//�鲢�������庯����
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//����һ����������д�С��ͬ�Ŀռ䣬���ڸ����ϲ�����
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;//��ϲ�����������Ԫ�صĸ���
	while (gap < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)//���һ��ĵڶ���С���䲻���ڻ��ǵ�һ��С���䲻��gap������ʱ����Ҫ�Ը�С����кϲ�
				break;
			if (end2 >= n)//���һ��ĵڶ���С���䲻��gap������ڶ���С����ĺ���Ϊ����ĺ��
				end2 = n - 1;
			_MergeSortNonR(a, tmp, begin1, end1, begin2, end2);//�ϲ�������������
		}
		gap = 2 * gap;//��һ����ϲ�����������Ԫ�صĸ�������
	}
	free(tmp);//�ͷſռ�
}

//��������
void CountSort(int* a, int n)
{
	int min = a[0];//��¼�����е���Сֵ
	int max = a[0];//��¼�����е����ֵ
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;//min��max֮�����Ȼ������������min��max����
	int* count = (int*)calloc(range, sizeof(int));//���ٿɴ���range�����͵��ڴ�ռ䣬�����ڴ�ռ���0
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//ͳ����ͬԪ�س��ִ��������ӳ�䣩
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int i = 0;
	//����ͳ�ƽ�������л��յ�ԭ����������
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);//�ͷſռ�
}