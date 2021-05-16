#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//交换函数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//gap折半
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
	}
}

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

//前后指针法（单趟排序）
int PartSort3(int* a, int left, int right)
{
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

//优化后的快速排序
void QuickSort(int* a, int begin, int end)
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

//将file1文件和file2文件中的数据归并到mfile文件中
void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");//打开file1文件
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");//打开file2文件
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");//打开mfile文件
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);//读取file1文件中的数据
	int ret2 = fscanf(fout2, "%d\n", &num2);//读取file2文件中的数据
	while (ret1 != EOF && ret2 != EOF)
	{
		//将读取到的较小值写入到mfile文件中，继续从file1和file2中读取数据进行比较
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
	//将file1文件中未读取完的数据写入文件mfile中
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	//将file2文件中未读取完的数据写入文件mfile中
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);//关闭file1文件
	fclose(fout2);//关闭file2文件
	fclose(fin);//关闭mfile文件
}
//将文件中的数据进行排序
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");//打开文件
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	// 分割成一段一段数据，内存排序后写到小文件中
	int n = 10;//一次读取10个数据进行内排序
	int a[10];//读取数据放到数组中，准备进行内排序
	int i = 0;
	int num = 0;
	char subfile[20];//文件名字符串
	int filei = 1;//储存第filei组内排序后的数据的文件的文件名

	memset(a, 0, sizeof(int)*n);//将数组a的空间置0
	while (fscanf(fout, "%d\n", &num) != EOF)//从文件中读取数据
	{
		if (i < n - 1)//读取前9个数据
		{
			a[i++] = num;
		}
		else//读取第10个数据
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);//将这10个数据进行快速排序
			sprintf(subfile, "%d", filei++);//将储存第filei组内排序后的数据的文件的文件名命名为filei
			FILE* fin = fopen(subfile, "w");//创建一个以字符串subfile[20]为名字的文件并打开
			if (fin == NULL)
			{
				printf("打开文件失败\n");
				exit(-1);
			}
			//将内排序排好的数据写入到subfile文件中
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}
			fclose(fin);//关闭subfile文件

			i = 0;
			memset(a, 0, sizeof(int)*n);//将a数组内存置0，准备再次读取10个数据进行内排序
		}
	}

	// 利用互相归并到文件，实现整体有序
	char mfile[100] = "12";//归并后文件的文件名
	char file1[100] = "1";//待归并的第一个文件的文件名
	char file2[100] = "2";//待归并的第二个文件的文件名
	for (int i = 2; i <= n; ++i)
	{
		//将file1文件和file2文件中的数据归并到mfile文件中
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);//下一次待归并的第一个文件就是上一次归并好的文件
		sprintf(file2, "%d", i + 1);//上一次待归并的第二个文件的文件名加一，就是下一次待归并的第二个文件的文件名
		sprintf(mfile, "%s%d", mfile, i + 1);//下一次归并后文件的文件名
	}

	fclose(fout);//关闭文件
}

int main()
{
	MergeSortFile("Sort.txt");//将Sort.txt文件中的数据进行排序
	return 0;
}