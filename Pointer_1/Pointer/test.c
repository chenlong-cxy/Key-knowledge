//#include<stdio.h>
//int main()
//{
//	int a = 10;//���ڴ��п���һ��ռ�
//	int* p = &a;//��a�ĵ�ַȡ�����ŵ�ָ�����p��
//	return 0;
//}


//#include<stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	//p�õ���ַ�󣬵�ַָ��Ŀռ��Ѿ��ͷ��ˣ��������ʱ���p����Ҳָ�롣
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int* p;//�ֲ�ָ�����P��δ��ʼ����Ĭ��Ϊ���ֵ
//	*p = 10;
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i < 11; i++)
//	{
//		*p++ = i;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p1 = &a;//��ȷ֪�����ĳһ��ַ
//	int* p2 = NULL;//��֪�������һ��ַʱ��Ϊ��ָ��
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*(p + i) = i;
//	}
//	return 0;
//}


//int my_strlen(char* p)
//{
//	char* pc = p;
//	while (*p != '\0')
//		p++;
//	return p - pc;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = &arr[0];
//	for (p = &arr[0]; p <= &arr[4]; p++)
//	{
//		*p = 0;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = &arr[4];
//	for (p = &arr[4]; p >= &arr[0]; p--)
//	{
//		*p = 0;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	int** p2 = &p1;
//	return 0;
//}