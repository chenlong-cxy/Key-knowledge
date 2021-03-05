//动态内存管理
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
//		printf("内存开辟失败\n");
//	}
//	else
//	{
//		printf("内存开辟成功\n");
//		//使用
//
//		//使用结束，释放内存(后面介绍)
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
//		printf("内存开辟失败\n");
//	}
//	else
//	{
//		printf("内存开辟成功\n");
//		//使用
//
//		//使用结束，释放内存(后面介绍)
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
//		printf("内存开辟失败\n");
//	}
//	else
//	{
//		printf("内存开辟成功\n");
//		//使用
//
//		//扩展容量
//		int* ptr = (int*)realloc(p, 100);
//		//将空间扩展为100个字节大小
//		if (ptr != NULL)
//		{
//			p = ptr;//开辟成功时
//			//使用
//		}
//		//使用结束，释放内存(后面介绍)
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//void free( void *memblock );
	//free(p);
	//p = NULL;