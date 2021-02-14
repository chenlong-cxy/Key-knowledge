//#include<stdio.h>
//int main()
//{
//	int a = 10;//在内存中开辟一块空间
//	int* p = &a;//将a的地址取出，放到指针变量p中
//	return 0;
//}


//#include<stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	//p得到地址后，地址指向的空间已经释放了，所以这个时候的p就是也指针。
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int* p;//局部指针变量P，未初始化，默认为随机值
//	*p = 10;
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i < 11; i++)
//	{
//		*p++ = i;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p1 = &a;//明确知道存放某一地址
//	int* p2 = NULL;//不知道存放哪一地址时置为空指针
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*(p + i) = i;
//	}
//	return 0;
//}


//int my_strlen(char* p)
//{
//	char* pc = p;
//	while (*p != '\0')
//		p++;
//	return p - pc;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = &arr[0];
//	for (p = &arr[0]; p <= &arr[4]; p++)
//	{
//		*p = 0;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int* p = &arr[4];
//	for (p = &arr[4]; p >= &arr[0]; p--)
//	{
//		*p = 0;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	int** p2 = &p1;
//	return 0;
//}