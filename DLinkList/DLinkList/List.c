#include "List.h"

//创建一个新结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

//初始化链表
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);

	phead->prev = phead;
	phead->next = phead;
	return phead;
}

//销毁链表
void ListDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	ListNode* next = cur->next;
	while (cur != phead)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(phead);
}

//打印双向链表
void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);
	ListNode* front = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = front;
	front->prev = newnode;
}

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* newtail = tail->prev;

	newtail->next = phead;
	phead->prev = newtail;
	free(tail);
}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* front = phead->next;
	ListNode* newfront = front->next;

	phead->next = newfront;
	newfront->prev = phead;
	free(front);
}

//查找元素
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在指定位置插入结点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* before = pos->prev;
	ListNode* newnode = BuyListNode(x);

	before->next = newnode;
	newnode->prev = before;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除指定位置结点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* before = pos->prev;
	ListNode* after = pos->next;

	before->next = after;
	after->prev = before;
	free(pos);
}

//链表判空
bool ListEmpty(ListNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

//获取链表中元素个数
int ListSize(ListNode* phead)
{
	assert(phead);

	int count = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		count++;
		cur = cur->next;
	}
	return count;
}