#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[3][4] = { 0 };
//	int(*p)[3][4] = &arr;
//	return 0;
//}


//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int(*p)(int, int) = &Add;
//	//int ret = (*p)(a, b);
//	int ret = p(a, b);
//	printf("%d\n", ret);
//	return 0;
//}
//����ָ�� - ָ�����͵�ָ��
//����ָ�� - ָ�������ָ��
//����ָ�� - ָ������ָ��


//(*(void(*)())0)();
//����0��ַ���ĺ������ú����޲�������������Ϊvoid


//����һ����������
//void (*signal(int , void(*)(int)))(int);
//�����ĺ�����signal
//signal����������������
//��һ������������Ϊint
//�ڶ�������������Ϊһ������ָ�룬�ú���ָ��ָ��ĺ�������Ϊint����������Ϊvoid
//signal�����ķ�������Ϊһ������ָ������
//�ú���ָ��ָ��Ĳ���Ϊint����������Ϊvoid
//typedef void(*pfun_t)(int);//��void(*)(int)�ĺ���ָ�������������pfun_t
//pfun_t signal(int, pfun_t);


//#include<stdio.h>
//int main()
//{
//	int* arr[10];//����arr��10��Ԫ�أ�ÿ��Ԫ�ص�������int*
//	int(*pArr[10])(int, int);
//	//����pArr��10��Ԫ�أ�ÿ��Ԫ�ص�������int(*)(int,int)
//	return 0;
//}


//#include<stdio.h>
//void menu()
//{
//	printf("|-----------------------|\n");
//	printf("|     1.Add   2.Sub     |\n");
//	printf("|     3.Mul   4.Div     |\n");
//	printf("|        0.exit         |\n");
//	printf("|-----------------------|\n");
//}//�˵�
//double Add(double x, double y)
//{
//	return x + y;
//}//�ӷ�����
//double Sub(double x, double y)
//{
//	return x - y;
//}//��������
//double Mul(double x, double y)
//{
//	return x*y;
//}//�˷�����
//double Div(double x, double y)
//{
//	return x / y;
//}//��������
//int main()
//{
//	int input = 0;
//	double x = 0;//��һ��������
//	double y = 0;//�ڶ���������
//	double ret = 0;//������
//	double(*pArr[])(double, double) = { 0, Add, Sub, Mul, Div };
//	//����ָ������-ת�Ʊ�
//	int sz = sizeof(pArr) / sizeof(pArr[0]);//���������С
//	do
//	{
//		menu();
//		printf("������:>");
//		scanf("%d", &input);
//		if (input == 0)
//			printf("�˳�����\n");
//		else if (input > 0 && input < sz)
//		{
//			printf("����������������:>");
//			scanf("%lf %lf", &x, &y);
//			ret = pArr[input](x, y);
//			printf("ret=%lf\n", ret);
//		}
//		else
//			printf("ѡ�����������ѡ��\n");
//	} while (input);//��input��Ϊ0ʱѭ������
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int(*p)(int, int);
//	//����ָ��
//	int(*pArr[5])(int, int);
//	//����ָ������
//	int(*(*pa)[5])(int, int) = &pArr;
//	//ָ����ָ�������ָ��
//	return 0;
//}


//#include<stdio.h>
//void test1()
//{
//	printf("hello\n");
//}
//void test2(void(*p)())
//{
//	p(); //ָ��p��������������ָ��ĺ���
//}
//int main()
//{
//	test2(test1);//��test1�����ĵ�ַ���ݸ�test2
//	return 0;
//}


//#include<stdio.h>
////void qsort(void*base,size_t num,size_t width,int(*compare)(const void*e1,const void*e2));
//int compare(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}//�Զ���ıȽϺ���
//int main()
//{
//	int arr[] = { 2, 5, 1, 8, 6, 10, 9, 3, 5, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
//	qsort(arr, sz, 4, compare);//��qsort������arr��������
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}