#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "a");
//	if (pf == NULL)
//	{
//		printf("�ļ���ʧ��\n");
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
//		return 1;//ʧ�ܷ���
//	}
//	//ʹ��
//	return 0;
//}


//���·��
//FILE* pf = fopen("data.txt", "r");//ͬ��
//FILE* pf = fopen("./data.txt", "r");//ͬ��
//FILE* pf = fopen("../data.txt", "r");//��һ��
//FILE* pf = fopen("../../data.txt", "r");//���ϼ�
//FILE* pf = fopen("Debug/data.txt", "r");//��һ��
//FILE* pf = fopen("Debug\\data.txt", "r");//��һ��

//����·��
//FILE* pf = fopen("D:\\code\\File_function\\File_function\\data.txt", "r");


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("D:\\code\\File_function\\File_function\\data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("��ʧ��\n");
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)//���ָ����Ч��
//	{
//		printf("%s\n", strerror(errno));//��������
//		return 1;//ʧ�ܷ���
//	}
//
//	//���ļ�����һϵ�в���
//	//...
//
//	//�ر��ļ�
//	fclose(pf);////�ر�pfָ����ļ�
//	pf = NULL;//��ʱ�ÿ�
//	return 0;
//}


//�ļ���˳���д
//1.fputc����
//int fputc(int c, FILE *stream);
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ���������ַ�����
//	char i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//2.fgetc����
//int fgetc( FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ����������ַ�����
//	int ch = 0;
//	while ((ch = fgetc(pf))!= EOF)
//	{
//		printf("%c", ch);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//3.fputs����
//int fputs( const char *string, FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ���������ַ�������
//	char arr[] = "hello world!";
//	fputs(arr, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//4.fgets����
//char *fgets( char *string, int n, FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ����������ַ�������
//	char arr[10] = { 0 };
//	fgets(arr, 6, pf);
//	printf("%s\n", arr);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//5.fprintf����
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ����и�ʽ���������
//	struct S s = { "zhangsan", "nan", 20 };
//	fprintf(pf, "%s %s %d\n", s.name, s.sex, s.age);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//6.fscanf����
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ����и�ʽ���������
//	struct S tmp = { 0 };
//	fscanf(pf, "%s %s %d", tmp.name, tmp.sex, &(tmp.age));
//	printf("%s %s %d\n", tmp.name, tmp.sex, tmp.age);
//	//��tmp�е����ݴ�ӡ���������Ƿ��ȡ�ɹ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//7.fwrite����
//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ��Զ�������ʽ�����������
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	fwrite(arr, sizeof(int), 10, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//8.fread����
//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ļ��Զ�������ʽ�����������
//	int arr[10] = { 0 };
//	fread(arr,sizeof(int),10,pf);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}//��arr�е����ݴ�ӡ���������Ƿ��ȡ�ɹ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//�ļ��������д
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
//	}
//	//���ַ����뺯����ȡ�ļ���Ϣ
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//�۲��һ�ζ�ȡ�����ַ�
//	ch = fgetc(pf);
//	printf("%c\n", ch);//�۲�ڶ��ζ�ȡ�����ַ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//1.fseek����
//int fseek( FILE *stream, long offset, int origin );
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
	//���ļ�
	FILE* pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;//�ļ���ʧ�ܣ�ʧ�ܷ���
	}
	//���ַ����뺯����ȡ�ļ���Ϣ
	int ch = fgetc(pf);
	printf("%c\n", ch);//�۲��һ�ζ�ȡ�����ַ�
	ch = fgetc(pf);
	printf("%c\n", ch);//�۲�ڶ��ζ�ȡ�����ַ�
	//�����ļ�ָ��
	//fseek(pf, 0, SEEK_SET);//�����ļ�ָ��λ��
	//ch = fgetc(pf);//��ȡ���ַ�'a'
	//printf("%c\n", ch);

	//fseek(pf, -6, SEEK_END);//�����ļ�ָ��λ��
	//ch = fgetc(pf);//��ȡ���ַ�'a'
	//printf("%c\n", ch);

	fseek(pf, -2, SEEK_CUR);//�����ļ�ָ��λ��
	ch = fgetc(pf);//��ȡ���ַ�'a'
	printf("%c\n", ch);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}