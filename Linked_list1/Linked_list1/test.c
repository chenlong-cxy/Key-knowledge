#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;//定义数据类型，可根据需要进行其他类型定义
//链表结点定义
typedef struct ListNode
{
	ElementType Data;//数据域，存储数据
	struct ListNode* Next;//指针域，存储下一个结点的地址
}Node, *PNode;
//创建链表
PNode CreateList()
{
	PNode PHead, PTail;//创建头指针和尾指针
	PHead = (PNode)malloc(sizeof(Node));//创建分配一个头结点内存空间
	if (PHead == NULL)
	{
		printf("头节点内存空间开辟失败\n");//malloc函数开辟空间失败
		exit(-1);
	}
	//当只有一个结点时，该节点既是头结点，又是尾结点，于是头指针和尾指针指向一个位置
	PTail = PHead;
	PTail->Next = NULL;//尾结点的指针域为NULL
	int i = 0;
	int len = 0;//定义链表的长度
	printf("请输入待存放结点个数:>");
	scanf("%d", &len);
	for (i = 0; i < len; i++)//循环创建len个结点
	{
		PNode PNew = (PNode)malloc(sizeof(Node));//分配一个新结点
		if (PNew == NULL)
		{
			printf("新结点创建失败\n");//malloc函数开辟空间失败
			exit(-1);
		}
		printf("请输入第%d个数:>", i + 1);
		scanf("%d", &(PNew->Data));//将输入的数据存储在新结点的数据域
		PNew->Next = NULL;//将新结点的指针域置为NULL
		PTail->Next = PNew;//将新结点的地址存储在尾指针指向的结点的指针域
		PTail = PNew;//新结点变成新的尾结点，于是尾指针指向该新结点
	}
	printf("链表创建成功\n");
	return PHead;//返回头结点位置
}
//打印链表数据
void TraverseList(PNode List)
{
	PNode P = List->Next;//将头结点的指针域赋值给P，使P指向下一个结点
	printf("遍历链表的值为:>");
	if (P == NULL)
	{
		printf("链表为空\n");
	}
	while (P != NULL)//P为NULL时，结束打印
	{
		printf("%d ", P->Data);//打印P指向的结点的数据域
		P = P->Next;//将该结点的指针域赋值给P，使P指向下一个结点
	}
	printf("\n");
}
int main()
{
	PNode List = CreateList();//链表创建好后，用List接收头结点位置
	TraverseList(List);//将头结点传入，打印该链表
	return 0;
}
