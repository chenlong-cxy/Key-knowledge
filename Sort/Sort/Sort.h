#include <stdio.h>

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

//2.�ڿӷ�

//3.ǰ��ָ�뷨

void QuickSort(int* a, int begin, int end);