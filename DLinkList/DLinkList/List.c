#include "List.h"

//����һ���½��
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

//��ʼ������
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);

	phead->prev = phead;
	phead->next = phead;
	return phead;
}

//��������
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

//��ӡ˫������
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

//β��
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

//ͷ��
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

//βɾ
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

//ͷɾ
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

//����Ԫ��
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

//��ָ��λ�ò�����
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

//ɾ��ָ��λ�ý��
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* before = pos->prev;
	ListNode* after = pos->next;

	before->next = after;
	after->prev = before;
	free(pos);
}

//�����п�
bool ListEmpty(ListNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

//��ȡ������Ԫ�ظ���
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