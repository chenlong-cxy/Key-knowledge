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
//整型指针 - 指向整型的指针
//数组指针 - 指向数组的指针
//函数指针 - 指向函数的指针


//(*(void(*)())0)();
//调用0地址处的函数，该函数无参数，返回类型为void


//这是一个函数声明
//void (*signal(int , void(*)(int)))(int);
//声明的函数叫signal
//signal函数有两个参数：
//第一个参数的类型为int
//第二个参数的类型为一个函数指针，该函数指针指向的函数参数为int，返回类型为void
//signal函数的返回类型为一个函数指针类型
//该函数指针指向的参数为int，返回类型为void
//typedef void(*pfun_t)(int);//给void(*)(int)的函数指针类型起个别名pfun_t
//pfun_t signal(int, pfun_t);


//#include<stdio.h>
//int main()
//{
//	int* arr[10];//数组arr有10个元素，每个元素的类型是int*
//	int(*pArr[10])(int, int);
//	//数组pArr有10个元素，每个元素的类型是int(*)(int,int)
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
//}//菜单
//double Add(double x, double y)
//{
//	return x + y;
//}//加法函数
//double Sub(double x, double y)
//{
//	return x - y;
//}//减法函数
//double Mul(double x, double y)
//{
//	return x*y;
//}//乘法函数
//double Div(double x, double y)
//{
//	return x / y;
//}//除法函数
//int main()
//{
//	int input = 0;
//	double x = 0;//第一个操作数
//	double y = 0;//第二个操作数
//	double ret = 0;//运算结果
//	double(*pArr[])(double, double) = { 0, Add, Sub, Mul, Div };
//	//函数指针数组-转移表
//	int sz = sizeof(pArr) / sizeof(pArr[0]);//计算数组大小
//	do
//	{
//		menu();
//		printf("请输入:>");
//		scanf("%d", &input);
//		if (input == 0)
//			printf("退出程序\n");
//		else if (input > 0 && input < sz)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%lf %lf", &x, &y);
//			ret = pArr[input](x, y);
//			printf("ret=%lf\n", ret);
//		}
//		else
//			printf("选择错误，请重新选择！\n");
//	} while (input);//当input不为0时循环继续
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int(*p)(int, int);
//	//函数指针
//	int(*pArr[5])(int, int);
//	//函数指针数组
//	int(*(*pa)[5])(int, int) = &pArr;
//	//指向函数指针数组的指针
//	return 0;
//}


//#include<stdio.h>
//void test1()
//{
//	printf("hello\n");
//}
//void test2(void(*p)())
//{
//	p(); //指针p被用来调用其所指向的函数
//}
//int main()
//{
//	test2(test1);//将test1函数的地址传递给test2
//	return 0;
//}


//#include<stdio.h>
////void qsort(void*base,size_t num,size_t width,int(*compare)(const void*e1,const void*e2));
//int compare(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}//自定义的比较函数
//int main()
//{
//	int arr[] = { 2, 5, 1, 8, 6, 10, 9, 3, 5, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//元素个数
//	qsort(arr, sz, 4, compare);//用qsort函数将arr数组排序
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}