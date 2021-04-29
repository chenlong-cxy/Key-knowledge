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
	node->data = x;//新结点赋值
	node->prev = NULL;
	node->next = NULL;

	return node;//返回新结点
}

//初始化链表
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(-1);//申请一个头结点，头结点不存储有效数据
	//起始时只有头结点，让它的前驱和后驱都指向自己
	phead->prev = phead;
	phead->next = phead;
	return phead;//返回头结点
}

//销毁链表
void ListDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;//从头结点后一个结点开始释放空间
	ListNode* next = cur->next;//记录cur的后一个结点位置
	while (cur != phead)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(phead);//释放头结点
}

//打印双向链表
void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;//从头结点的后一个结点开始打印
	while (cur != phead)//当cur指针指向头结点时，说明链表以打印完毕
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

	ListNode* newnode = BuyListNode(x);//申请一个结点，数据域赋值为x
	ListNode* tail = phead->prev;//记录头结点的前一个结点的位置
	//建立新结点与头结点之间的双向关系
	newnode->next = phead;
	phead->prev = newnode;
	//建立新结点与tail结点之间的双向关系
	tail->next = newnode;
	newnode->prev = tail;
}

//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);//申请一个结点，数据域赋值为x
	ListNode* front = phead->next;//记录头结点的后一个结点位置
	//建立新结点与头结点之间的双向关系
	phead->next = newnode;
	newnode->prev = phead;
	//建立新结点与front结点之间的双向关系
	newnode->next = front;
	front->prev = newnode;
}

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;//记录头结点的前一个结点
	ListNode* newtail = tail->prev;//记录tail结点的前一个结点
	//建立头结点与newtail结点之间的双向关系
	newtail->next = phead;
	phead->prev = newtail;
	free(tail);//释放tail结点
}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* front = phead->next;//记录头结点的后一个结点
	ListNode* newfront = front->next;//记录front结点的后一个结点
	//建立头结点与newfront结点之间的双向关系
	phead->next = newfront;
	newfront->prev = phead;
	free(front);//释放front结点
}

//查找元素
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;//从头结点的后一个结点开始查找
	while (cur != phead)//当cur指向头结点时，说明链表已遍历完毕
	{
		if (cur->data == x)
		{
			return cur;//返回目标结点的地址
		}
		cur = cur->next;
	}
	return NULL;//没有找到目标结点
}

//在指定位置插入结点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* before = pos->prev;//记录pos指向结点的前一个结点
	ListNode* newnode = BuyListNode(x);//申请一个结点，数据域赋值为x
	//建立新结点与before结点之间的双向关系
	before->next = newnode;
	newnode->prev = before;
	//建立新结点与pos指向结点之间的双向关系
	newnode->next = pos;
	pos->prev = newnode;
}

//删除指定位置结点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* before = pos->prev;//记录pos指向结点的前一个结点
	ListNode* after = pos->next;//记录pos指向结点的后一个结点
	//建立before结点与after结点之间的双向关系
	before->next = after;
	after->prev = before;
	free(pos);//释放pos指向的结点
}

//链表判空
bool ListEmpty(ListNode* phead)
{
	assert(phead);

	return phead->next == phead;//当链表中只有头结点时为空
}

//获取链表中的元素个数
int ListSize(ListNode* phead)
{
	assert(phead);

	int count = 0;//记录元素个数
	ListNode* cur = phead->next;//从头结点的后一个结点开始遍历
	while (cur != phead)//当cur指向头结点时，遍历完毕，头结点不计入总元素个数
	{
		count++;
		cur = cur->next;
	}
	return count;//返回元素个数
}