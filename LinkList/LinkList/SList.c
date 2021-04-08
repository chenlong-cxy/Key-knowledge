#include "SList.h"

//打印链表
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建一个新结点，返回新结点地址
SListNode* BuySLTNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//头插
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	SListNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//尾插
void SListPushBack(SListNode** pplist, SLTDataType x)
{
	SListNode* newnode = BuySLTNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//在给定位置之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{

}

//在给定位置之前插入
void SListInsertBefore(SListNode** pplist, SListNode* pos, SLTDataType x)
{

}

//头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SListNode* tmp = *pplist;
		*pplist = (*pplist)->next;
		free(tmp);
		tmp = NULL;
	}
}

//尾删
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* prev = *pplist;
		SListNode* tail = (*pplist)->next;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//删除给定位置之后的值
void SListErasetAfter(SListNode* pos)
{

}

//删除给定位置的值
void SListErasetCur(SListNode** pplist, SListNode* pos)
{

}

//删除给定位置之前的值
void SListErasetBefore(SListNode** pplist, SListNode* pos)
{

}

//查找数据
SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}