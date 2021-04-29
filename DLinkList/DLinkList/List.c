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
	node->data = x;//�½�㸳ֵ
	node->prev = NULL;
	node->next = NULL;

	return node;//�����½��
}

//��ʼ������
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(-1);//����һ��ͷ��㣬ͷ��㲻�洢��Ч����
	//��ʼʱֻ��ͷ��㣬������ǰ���ͺ�����ָ���Լ�
	phead->prev = phead;
	phead->next = phead;
	return phead;//����ͷ���
}

//��������
void ListDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;//��ͷ����һ����㿪ʼ�ͷſռ�
	ListNode* next = cur->next;//��¼cur�ĺ�һ�����λ��
	while (cur != phead)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(phead);//�ͷ�ͷ���
}

//��ӡ˫������
void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;//��ͷ���ĺ�һ����㿪ʼ��ӡ
	while (cur != phead)//��curָ��ָ��ͷ���ʱ��˵�������Դ�ӡ���
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

	ListNode* newnode = BuyListNode(x);//����һ����㣬������ֵΪx
	ListNode* tail = phead->prev;//��¼ͷ����ǰһ������λ��
	//�����½����ͷ���֮���˫���ϵ
	newnode->next = phead;
	phead->prev = newnode;
	//�����½����tail���֮���˫���ϵ
	tail->next = newnode;
	newnode->prev = tail;
}

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);//����һ����㣬������ֵΪx
	ListNode* front = phead->next;//��¼ͷ���ĺ�һ�����λ��
	//�����½����ͷ���֮���˫���ϵ
	phead->next = newnode;
	newnode->prev = phead;
	//�����½����front���֮���˫���ϵ
	newnode->next = front;
	front->prev = newnode;
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;//��¼ͷ����ǰһ�����
	ListNode* newtail = tail->prev;//��¼tail����ǰһ�����
	//����ͷ�����newtail���֮���˫���ϵ
	newtail->next = phead;
	phead->prev = newtail;
	free(tail);//�ͷ�tail���
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* front = phead->next;//��¼ͷ���ĺ�һ�����
	ListNode* newfront = front->next;//��¼front���ĺ�һ�����
	//����ͷ�����newfront���֮���˫���ϵ
	phead->next = newfront;
	newfront->prev = phead;
	free(front);//�ͷ�front���
}

//����Ԫ��
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;//��ͷ���ĺ�һ����㿪ʼ����
	while (cur != phead)//��curָ��ͷ���ʱ��˵�������ѱ������
	{
		if (cur->data == x)
		{
			return cur;//����Ŀ����ĵ�ַ
		}
		cur = cur->next;
	}
	return NULL;//û���ҵ�Ŀ����
}

//��ָ��λ�ò�����
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* before = pos->prev;//��¼posָ�����ǰһ�����
	ListNode* newnode = BuyListNode(x);//����һ����㣬������ֵΪx
	//�����½����before���֮���˫���ϵ
	before->next = newnode;
	newnode->prev = before;
	//�����½����posָ����֮���˫���ϵ
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��ָ��λ�ý��
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* before = pos->prev;//��¼posָ�����ǰһ�����
	ListNode* after = pos->next;//��¼posָ����ĺ�һ�����
	//����before�����after���֮���˫���ϵ
	before->next = after;
	after->prev = before;
	free(pos);//�ͷ�posָ��Ľ��
}

//�����п�
bool ListEmpty(ListNode* phead)
{
	assert(phead);

	return phead->next == phead;//��������ֻ��ͷ���ʱΪ��
}

//��ȡ�����е�Ԫ�ظ���
int ListSize(ListNode* phead)
{
	assert(phead);

	int count = 0;//��¼Ԫ�ظ���
	ListNode* cur = phead->next;//��ͷ���ĺ�һ����㿪ʼ����
	while (cur != phead)//��curָ��ͷ���ʱ��������ϣ�ͷ��㲻������Ԫ�ظ���
	{
		count++;
		cur = cur->next;
	}
	return count;//����Ԫ�ظ���
}