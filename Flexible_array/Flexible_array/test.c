//#include <stdio.h>
//struct S
//{
//	int n;
//	int arr[];//���������Ա
//};
//struct S
//{
//	int n;
//	int arr[0];//���������Ա
//};
//struct Er
//{
//	int arr[];
//};//error


//#include <stdio.h>
//struct S
//{
//	int n;
//	int arr[];//���������Ա
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	//���Ϊ4
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	int n;
//	int arr[];//���������Ա
//};
//int main()
//{
//	//����
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	char ch;
//	int arr[];//���������Ա
//};
//int main()
//{
//	//���ٶ�̬�ڴ�ռ�
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	ps->ch = 'A';
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//		//�������������±�Ϊi��Ԫ�ظ�ֵΪi
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	//���������ٵĶ�̬�ڴ�ռ�Ĵ�С
//	struct S* ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int));
//	if (ptr != NULL)//���ٳɹ�
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		//�������������±�Ϊi��Ԫ�ظ�ֵΪi
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("%c\n", ps->ch);
//	//�ͷſ��ٵĶ�̬�ڴ�ռ�
//	free(ps);
//	ps = NULL;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
struct S
{
	char ch;
	int* arr;
};
int main()
{
	//���ٶ�̬�ڴ�ռ�
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = (int*)malloc(5 * sizeof(int));
	ps->ch = 'A';
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
		//�������������±�Ϊi��Ԫ�ظ�ֵΪi
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//���������ٵĶ�̬�ڴ�ռ�Ĵ�С
	int* ptr = (int*)realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)//���ٳɹ�
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
		//�������������±�Ϊi��Ԫ�ظ�ֵΪi
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("%c\n", ps->ch);
	//�ͷſ��ٵĶ�̬�ڴ�ռ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}