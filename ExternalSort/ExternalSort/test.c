#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//gap�۰�
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
	}
}

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

//ǰ��ָ�뷨����������
int PartSort3(int* a, int left, int right)
{
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

//�Ż���Ŀ�������
void QuickSort(int* a, int begin, int end)
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

//��file1�ļ���file2�ļ��е����ݹ鲢��mfile�ļ���
void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");//��file1�ļ�
	if (fout1 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");//��file2�ļ�
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");//��mfile�ļ�
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);//��ȡfile1�ļ��е�����
	int ret2 = fscanf(fout2, "%d\n", &num2);//��ȡfile2�ļ��е�����
	while (ret1 != EOF && ret2 != EOF)
	{
		//����ȡ���Ľ�Сֵд�뵽mfile�ļ��У�������file1��file2�ж�ȡ���ݽ��бȽ�
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	//��file1�ļ���δ��ȡ�������д���ļ�mfile��
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	//��file2�ļ���δ��ȡ�������д���ļ�mfile��
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);//�ر�file1�ļ�
	fclose(fout2);//�ر�file2�ļ�
	fclose(fin);//�ر�mfile�ļ�
}
//���ļ��е����ݽ�������
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");//���ļ�
	if (fout == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	// �ָ��һ��һ�����ݣ��ڴ������д��С�ļ���
	int n = 10;//һ�ζ�ȡ10�����ݽ���������
	int a[10];//��ȡ���ݷŵ������У�׼������������
	int i = 0;
	int num = 0;
	char subfile[20];//�ļ����ַ���
	int filei = 1;//�����filei�������������ݵ��ļ����ļ���

	memset(a, 0, sizeof(int)*n);//������a�Ŀռ���0
	while (fscanf(fout, "%d\n", &num) != EOF)//���ļ��ж�ȡ����
	{
		if (i < n - 1)//��ȡǰ9������
		{
			a[i++] = num;
		}
		else//��ȡ��10������
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);//����10�����ݽ��п�������
			sprintf(subfile, "%d", filei++);//�������filei�������������ݵ��ļ����ļ�������Ϊfilei
			FILE* fin = fopen(subfile, "w");//����һ�����ַ���subfile[20]Ϊ���ֵ��ļ�����
			if (fin == NULL)
			{
				printf("���ļ�ʧ��\n");
				exit(-1);
			}
			//���������źõ�����д�뵽subfile�ļ���
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}
			fclose(fin);//�ر�subfile�ļ�

			i = 0;
			memset(a, 0, sizeof(int)*n);//��a�����ڴ���0��׼���ٴζ�ȡ10�����ݽ���������
		}
	}

	// ���û���鲢���ļ���ʵ����������
	char mfile[100] = "12";//�鲢���ļ����ļ���
	char file1[100] = "1";//���鲢�ĵ�һ���ļ����ļ���
	char file2[100] = "2";//���鲢�ĵڶ����ļ����ļ���
	for (int i = 2; i <= n; ++i)
	{
		//��file1�ļ���file2�ļ��е����ݹ鲢��mfile�ļ���
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);//��һ�δ��鲢�ĵ�һ���ļ�������һ�ι鲢�õ��ļ�
		sprintf(file2, "%d", i + 1);//��һ�δ��鲢�ĵڶ����ļ����ļ�����һ��������һ�δ��鲢�ĵڶ����ļ����ļ���
		sprintf(mfile, "%s%d", mfile, i + 1);//��һ�ι鲢���ļ����ļ���
	}

	fclose(fout);//�ر��ļ�
}

int main()
{
	MergeSortFile("Sort.txt");//��Sort.txt�ļ��е����ݽ�������
	return 0;
}