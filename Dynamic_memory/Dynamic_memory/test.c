//��̬�ڴ����
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	return 0;
//}
//void *malloc( size_t size );
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("�ڴ濪��ʧ��\n");
//	}
//	else
//	{
//		printf("�ڴ濪�ٳɹ�\n");
//		//ʹ��
//
//		//ʹ�ý������ͷ��ڴ�(�������)
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//void *calloc( size_t num, size_t size );
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)calloc(10 , sizeof(int));
//	if (p == NULL)
//	{
//		printf("�ڴ濪��ʧ��\n");
//	}
//	else
//	{
//		printf("�ڴ濪�ٳɹ�\n");
//		//ʹ��
//
//		//ʹ�ý������ͷ��ڴ�(�������)
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//void *realloc( void *memblock, size_t size );
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("�ڴ濪��ʧ��\n");
//	}
//	else
//	{
//		printf("�ڴ濪�ٳɹ�\n");
//		//ʹ��
//
//		//��չ����
//		int* ptr = (int*)realloc(p, 100);
//		//���ռ���չΪ100���ֽڴ�С
//		if (ptr != NULL)
//		{
//			p = ptr;//���ٳɹ�ʱ
//			//ʹ��
//		}
//		//ʹ�ý������ͷ��ڴ�(�������)
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//void free( void *memblock );
	//free(p);
	//p = NULL;