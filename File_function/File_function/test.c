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
	//���ļ����������ַ�������
	char arr[10] = { 0 };
	fgets(arr, 6, pf);
	printf("%s\n", arr);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}