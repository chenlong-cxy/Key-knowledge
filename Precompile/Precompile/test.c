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


#include <stdio.h>
int main()
{
	int age = 10;
	printf("The value of ""age"" is ""%d""\n", age);
	double pi = 3.14;
	printf("The value of ""pi"" is ""%f""\n", pi);
	int* p = &age;
	printf("The value of ""p"" is ""%p""\n", p);
	return 0;
}