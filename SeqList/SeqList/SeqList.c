#include "SeqList.h"

//初始化顺序表
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;//起始时元素个数为0
	ps->capacity = 0;//容量为0
}

//销毁顺序表
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//打印顺序表
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查顺序表容量是否已满，若已满，则增容
void SeqCheckCapacity(SeqList* ps)
{
	//满了，需要增容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* newA = realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = newA;
		ps->capacity = newcapacity;
	}
}

//头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//检查容量
	//int i = 0;
	//for (i = ps->size; i > 0; i--)
	//{
	//	ps->a[i] = ps->a[i - 1];
	//}
	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);
}

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//检查容量
	//ps->a[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}

//指定下标位置插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqCheckCapacity(ps);//检查容量
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

//头删
void SeqListPopFront(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//int i = 0;
	//for (i = 0; i < ps->size - 1; i++)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}
	//ps->size--;
	SeqListErase(ps, 0);
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}
//指定下标位置删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);
	assert(pos >= 0 && pos < ps->size);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//查找元素，若有，返回下标，否则返回-1
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

//修改指定下标位置元素
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}