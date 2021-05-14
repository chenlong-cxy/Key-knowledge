#include <stdio.h>
#include <stdlib.h>

//��ӡ����
void PrintArr(int* a, int n);
//��������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);

//ѡ������(һ��ѡһ����)
void SelectSort1(int* a, int n);
//ѡ������(һ��ѡ������)
void SelectSort2(int* a, int n);

//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//�������򣨵ݹ�ʵ�֣�
//1.hoare
void QuickSort1(int* a, int begin, int end);
//2.�ڿӷ�
void QuickSort2(int* a, int begin, int end);
//3.ǰ��ָ�뷨
void QuickSort3(int* a, int begin, int end);

//�������򣨵ݹ�ʵ�֣�
//1.hoare
int PartSort1(int* a, int left, int right);
//2.�ڿӷ�
int PartSort2(int* a, int left, int right);
//3.ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
//����
void QuickSort(int* a, int begin, int end);
//����(С�����Ż�)
void QuickSort0(int* a, int begin, int end);

//�������򣨷ǵݹ�ʵ�֣�
void QuickSortNonR(int* a, int begin, int end);

//�鲢���򣨵ݹ�ʵ�֣�
void MergeSort(int* a, int n);
//�鲢���򣨷ǵݹ�ʵ�֣�
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);