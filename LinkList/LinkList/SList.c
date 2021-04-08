#include "SList.h"

//��ӡ����
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

//����һ���½�㣬�����½���ַ
SListNode* BuySLTNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	SListNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

//β��
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

//�ڸ���λ��֮�����
void SListInsertAfter(SListNode* pos, SLTDataType x)
{

}

//�ڸ���λ��֮ǰ����
void SListInsertBefore(SListNode** pplist, SListNode* pos, SLTDataType x)
{

}

//ͷɾ
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

//βɾ
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

//ɾ������λ��֮���ֵ
void SListErasetAfter(SListNode* pos)
{

}

//ɾ������λ�õ�ֵ
void SListErasetCur(SListNode** pplist, SListNode* pos)
{

}

//ɾ������λ��֮ǰ��ֵ
void SListErasetBefore(SListNode** pplist, SListNode* pos)
{

}

//��������
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