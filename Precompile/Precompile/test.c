//#include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	//printf("%d\n", __STDC__);
//	//因为VS2013不遵循ANSI C，该符号未定义，所以进行了注释
//	return 0;
//}
//__FILE__        //进行编译的源文件
//__LINE__        //文件当前的行号
//__DATE__        //文件被编译的日期
//__TIME__        //文件被编译的时间
//__STDC__        //如果编译器遵循ANSI C，其值为1，否则未定义
//__FUNCTION__    //进行编译的函数


//#define MAX 100
//#define reg register
//#define mian main
//#define ， ,
//#define （ (
//#define ） )
//#define ture true
//#define ； ;


//#include <stdio.h>
//#define SQUARE(x) x*x//求x的平方
//#define SQUARE(x) ((x)*(x))
//int main()
//{
//	int ret = SQUARE(2+3);
//	int ret = 2+3*2+3;
//	//相当于int ret = 5*5;
//	printf("%d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//#define MAX 100
//#define SQUARE(x) ((x)*(x)*MAX)
//int main()
//{
//	int ret = SQUARE(5);
//	printf("%d\n", ret);
//	return 0;
//}


//#define FAC(x) (x)*FAC(x-1)//error
//int main()
//{
//	int ret = FAC(3);
//	return 0;
//}


//#include <stdio.h>
//#define MAX 100
//int main()
//{
//	printf("MAX = %d\n", MAX);
//	return 0;
//}


//#和##
//#include <stdio.h>
//int main()
//{
//	printf("hello world!\n");
//	printf("hello ""world!\n");
//	return 0;
//}


//#include <stdio.h>
//#define print(data,format) printf("The value of "#data" is "format"\n",data)
//int main()
//{
//	char arr[] = "hello ""world!";
//	//等价于char arr[] = "hello world!";
//	printf("helll ""world!\n");
//	//等价于printf("helll world!\n");
//	printf("%s\n", arr);
//	int a = 10;
//	print(a, "%d");
//	return 0;
//}


//#include <stdio.h>
//#define print(data,format) printf("The value of "#data" is "format"\n",data)
//int main()
//{
//	int age = 10;
//	printf("The value of age is %d\n", age);
//	double pi = 3.14;
//	printf("The value of pi is %f\n", pi);
//	int* p = &age;
//	printf("The value of p is %p\n", p);
//	print(age, "%d");
//	print(pi, "%f");
//	print(p, "%p");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	printf("The value of ""age"" is ""%d""\n", age);
//	double pi = 3.14;
//	printf("The value of ""pi"" is ""%f""\n", pi);
//	int* p = &age;
//	printf("The value of ""p"" is ""%p""\n", p);
//	return 0;
//}


//#include <stdio.h>
//#define CAT(x,y) x##y
//int main()
//{
//	int workhard = 100;
//	printf("%d\n", CAT(work, hard));
//	return 0;
//}


//带有副作用的宏参数
//#include <stdio.h>
//#define MAX(x,y) ((x)>(y)?(x):(y))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int c = MAX(a, b);
//	int c = MAX(a++, b++);
//	printf("%d\n", c);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = ((a++)>(b++)?(a++):(b++));
//	printf("%d\n", c);
//	printf("%d %d\n", a, b);
//	return 0;
//}


//#include <stdio.h>
//#define MAX(x,y) ((x)>(y)?(x):(y))
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = MAX(a, b);//7
//	int d = Max(a, b);//30
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	if (p1 == NULL)
//	{
//		printf("p1开辟失败\n");
//		return 1;
//	}
//	int* p2 = MALLOC(10, int);
//	if (p2 == NULL)
//	{
//		printf("p2开辟失败\n");
//		return 1;
//	}
//	free(p1);
//	p1 = NULL;
//	free(p2);
//	p2 = NULL;
//	return 0;
//}


//#include <stddef.h>
//#include <stdio.h>
//offsetof();
//getchar();
//#define  getchar()   getc(stdin)
//#define  putchar(c)  putc((c),  stdout) 
//#define offsetof(s,m)   (size_t)&(((s *)0)->m)


//#include <stdio.h>
//#define MAX 100
//int main()
//{
//	printf("%d\n", MAX);//正常使用
//#undef MAX
//	printf("%d\n", MAX);//报错，MAX未定义
//}


//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i< ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i< ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}

//gcc -D programe.c ARRAY_SIZE = 10


//#include <stdio.h>
//#define __TEST__ 0
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//#ifdef __TEST__
//		printf("hello world!\n");
//#endif
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//#if 0
//		printf("hello world!\n");
//#endif
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 2;
//#if a+3
//	printf("a\n");
//	printf("a\n");
//	printf("a\n");
//#elif 4-3
//	printf("b\n");
//#elif 2-2
//	printf("c\n");
//#else 3+4
//	printf("d\n");
//#endif
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//定义了PRINT才打印参与编译
//#ifdef PRINT
//	printf("参与编译\n");
//#endif
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//没有定义PRINT才打印参与编译
//#ifndef PRINT
//	printf("参与编译\n");
//#endif
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//定义了PRINT才打印参与编译
//#if defined(PRINT)
//	printf("参与编译\n");
//#endif
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//没有定义PRINT才打印参与编译
//#if !defined(PRINT)
//	printf("参与编译\n");
//#endif
//	return 0;
//}


//#include <stdio.h>
//#define MIN 10
//int main()
//{
//#if !defined(MAX)
//#ifdef MIN
//	printf("hello\n");
//#else
//	printf("world\n");
//#endif
//#endif
//	return 0;
//}


//#if 表达式
//	//...
//#endif


//#if 表达式
//	//...
//#elif 表达式
//	//...
//#elif 表达式
//	//...
//#else 表达式
//	//...
//#endif

////第一种
//#if defined(表达式)
//	//...
//#endif
////第一种的反面
//#if !defined(表达式)
//	//...
//#endif
////第二种
//#ifdef 表达式
//	//...
//#endif
////第二种的反面
//#ifndef 表达式
//	//...
//#endif


#include <stdio.h>//一般用于包含C语言提供的库函数的头文件
//直接去库目录下找，如果找不到就找不到了
#include "stdio.h"//一般用于包含自定义的头文件
//首先去当前工程目录下查找，如果找不到，再去库目录下查找
#include <hehe.h>