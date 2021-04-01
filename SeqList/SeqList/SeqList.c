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
	ps = NULL;
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
		int newA = realloc(ps->a, newcapacity*sizeof(SLDataType));
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
	assert(ps);
	SeqCheckCapacity(ps);
}

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x);
//指定下标位置插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x);