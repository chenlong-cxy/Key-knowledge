//#include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	//printf("%d\n", __STDC__);
//	//��ΪVS2013����ѭANSI C���÷���δ���壬���Խ�����ע��
//	return 0;
//}
//__FILE__        //���б����Դ�ļ�
//__LINE__        //�ļ���ǰ���к�
//__DATE__        //�ļ������������
//__TIME__        //�ļ��������ʱ��
//__STDC__        //�����������ѭANSI C����ֵΪ1������δ����
//__FUNCTION__    //���б���ĺ���


//#define MAX 100
//#define reg register
//#define mian main
//#define �� ,
//#define �� (
//#define �� )
//#define ture true
//#define �� ;


//#include <stdio.h>
//#define SQUARE(x) x*x//��x��ƽ��
//#define SQUARE(x) ((x)*(x))
//int main()
//{
//	int ret = SQUARE(2+3);
//	int ret = 2+3*2+3;
//	//�൱��int ret = 5*5;
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


//#��##
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
//	//�ȼ���char arr[] = "hello world!";
//	printf("helll ""world!\n");
//	//�ȼ���printf("helll world!\n");
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