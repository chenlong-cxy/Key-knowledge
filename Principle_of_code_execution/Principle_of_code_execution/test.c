#include <stdio.h>//��printf��δ����
extern int Add(int, int);//��Add��δ���壬����ʱÿ��Դ�ļ���������
int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d\n", c);
	return 0;
}