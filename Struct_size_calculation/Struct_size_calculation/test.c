

//�ṹ��Ķ������
//1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������
//�������ṹ��������С��������������������Ƕ�׽ṹ��Ķ�����������������

//������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵ�ֵΪ8
//Linux�е�Ĭ��ֵΪ4

//#include <stdio.h>
//struct S1
//{
//	double d;//8/8->8
//	char c;//1/8->1
//	int i;//4/8->4
//};
//struct S2
//{
//	double d;//8/8->8
//	struct S1 s1;//16/8->8(��Сֵ)
//	int i;//4/8->4
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));//16
//	printf("%d\n", sizeof(struct S2));//32
//	return 0;
//}


//#include <stdio.h>
//struct S1
//{
//	char a;
//	char b;
//	int c;
//};
//struct S2
//{
//	char a;
//	int c;
//	char b;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}


#include <stdio.h>
#pragma pack(4)//����Ĭ�϶�����Ϊ4
struct S1
{
	char a;//1/4->1
	int b;//4/4->4
	char c;//1/4->1
};//12
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��

#pragma pack(1)//����Ĭ�϶�����Ϊ1
struct S2
{
	char a;//1/1->1
	int b;//4/1->1
	char c;//1/1->1
};//6
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��

int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	return 0;
}