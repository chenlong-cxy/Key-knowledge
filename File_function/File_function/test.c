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
//	//对文件进行输入字符串操作
//	char arr[10] = { 0 };
//	fgets(arr, 6, pf);
//	printf("%s\n", arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//5.fprintf函数
//int fprintf( FILE *stream, const char *format [, argument ]...);

//int printf( const char *format [, argument]... );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//struct S
//{
//	char name[20];
//	char sex[5];
//	int age;
//};
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//文件打开失败，失败返回
//	}
//	//对文件进行格式化输出操作
//	struct S s = { "zhangsan", "nan", 20 };
//	fprintf(pf, "%s %s %d\n", s.name, s.sex, s.age);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//6.fscanf函数
//int fscanf( FILE *stream, const char *format [, argument ]... );

//int scanf( const char *format [,argument]... );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//struct S
//{
//	char name[20];
//	char sex[5];
//	int age;
//};
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//文件打开失败，失败返回
//	}
//	//对文件进行格式化输入操作
//	struct S tmp = { 0 };
//	fscanf(pf, "%s %s %d", tmp.name, tmp.sex, &(tmp.age));
//	printf("%s %s %d\n", tmp.name, tmp.sex, tmp.age);
//	//将tmp中的内容打印出来，看是否读取成功
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//7.fwrite函数
//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
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
//	//对文件以二进制形式进行输出操作
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	fwrite(arr, sizeof(int), 10, pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//8.fread函数
//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
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
//	//对文件以二进制形式进行输入操作
//	int arr[10] = { 0 };
//	fread(arr,sizeof(int),10,pf);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}//将arr中的内容打印出来，看是否读取成功
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//文件的随机读写
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
//	//用字符输入函数读取文件信息
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//观察第一次读取到的字符
//	ch = fgetc(pf);
//	printf("%c\n", ch);//观察第二次读取到的字符
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//1.fseek函数
//int fseek( FILE *stream, long offset, int origin );
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
	//用字符输入函数读取文件信息
	int ch = fgetc(pf);
	printf("%c\n", ch);//观察第一次读取到的字符
	ch = fgetc(pf);
	printf("%c\n", ch);//观察第二次读取到的字符
	//操作文件指针
	//fseek(pf, 0, SEEK_SET);//调整文件指针位置
	//ch = fgetc(pf);//读取到字符'a'
	//printf("%c\n", ch);

	//fseek(pf, -6, SEEK_END);//调整文件指针位置
	//ch = fgetc(pf);//读取到字符'a'
	//printf("%c\n", ch);

	fseek(pf, -2, SEEK_CUR);//调整文件指针位置
	ch = fgetc(pf);//读取到字符'a'
	printf("%c\n", ch);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}