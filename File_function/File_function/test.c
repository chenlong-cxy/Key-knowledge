#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "a");
//	if (pf == NULL)
//	{
//		printf("文件打开失败\n");
//		return 1;
//	}
//	fputc('a', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	FILE* pf = fopen("data.bin", "wb");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//失败返回
//	}
//	//使用
//	return 0;
//}


//相对路径
//FILE* pf = fopen("data.txt", "r");//同级
//FILE* pf = fopen("./data.txt", "r");//同级
//FILE* pf = fopen("../data.txt", "r");//上一级
//FILE* pf = fopen("../../data.txt", "r");//上上级
//FILE* pf = fopen("Debug/data.txt", "r");//下一级
//FILE* pf = fopen("Debug\\data.txt", "r");//下一级

//绝对路径
//FILE* pf = fopen("D:\\code\\File_function\\File_function\\data.txt", "r");


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("D:\\code\\File_function\\File_function\\data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("打开失败\n");
//		return 1;
//	}
//	char ch = fputc('b', pf);
//	printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)//检测指针有效性
//	{
//		printf("%s\n", strerror(errno));//错误提醒
//		return 1;//失败返回
//	}
//
//	//对文件进行一系列操作
//	//...
//
//	//关闭文件
//	fclose(pf);////关闭pf指向的文件
//	pf = NULL;//及时置空
//	return 0;
//}


//文件的顺序读写
//1.fputc函数
//int fputc(int c, FILE *stream);
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//文件打开失败，失败返回
//	}
//	//对文件进行输出字符操作
//	char i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//2.fgetc函数
//int fgetc( FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//文件打开失败，失败返回
//	}
//	//对文件进行输入字符操作
//	int ch = 0;
//	while ((ch = fgetc(pf))!= EOF)
//	{
//		printf("%c", ch);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//3.fputs函数
//int fputs( const char *string, FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//文件打开失败，失败返回
//	}
//	//对文件进行输出字符串操作
//	char arr[] = "hello world!";
//	fputs(arr, pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//4.fgets函数
//char *fgets( char *string, int n, FILE *stream );
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
	//打开文件
	FILE* pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;//文件打开失败，失败返回
	}
	//对文件进行输入字符串操作
	char arr[10] = { 0 };
	fgets(arr, 6, pf);
	printf("%s\n", arr);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}