#include "SeqList.h"

//初始化顺序表
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;//刚开始时顺序表为空，顺序表指针为NULL
	ps->size = 0;//起始时元素个数为0
	ps->capacity = 0;//容量为0
}

//销毁顺序表
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);//释放顺序表指针指向的空间
	ps->a = NULL;//及时置空
	ps->size = 0;//元素个数置0
	ps->capacity = 0;//容量置0
}

//打印顺序表
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	//循环打印顺序表指针指向的数据
	printf("顺序表内容为:>");
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查顺序表容量是否已满，若已满，则增容
void SeqCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)//满了，需要增容
	{
		//判断顺序表容量是否为0，若为0，则先开辟用于存放4个元素的空间大小，若不为0，则扩容为原来容量的两倍
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* newA = realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = newA;//开辟成功，将顺序表指针更新
		ps->capacity = newcapacity;//容量更新
	}
}

//头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//检查容量
	//int i = 0;
	//for (i = ps->size; i > 0; i--)//将数据从后往前依次向后挪
	//{
	//	ps->a[i] = ps->a[i - 1];
	//}
	//ps->a[0] = x;
	//ps->size++;//顺序表元素个数加一

	SeqListInsert(ps, 0, x);//在下标为0的位置插入数据
}

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//检查容量
	//ps->a[ps->size] = x;
	//ps->size++;//顺序表元素个数加一

	SeqListInsert(ps, ps->size, x);//在下标为ps->size的位置插入数据
}

//指定下标位置插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);//检查输入下标的合法性
	SeqCheckCapacity(ps);//检查容量
	int i = 0;
	for (i = ps->size; i > pos; i--)//从pos下标位置开始，其后的数据从后往前依次向后挪
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;//顺序表元素个数加一
}

//头删
void SeqListPopFront(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//保证顺序表不为空
	//int i = 0;
	//for (i = 0; i < ps->size - 1; i++)//将数据从前往后依次向前覆盖
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}
	//ps->size--;//顺序表元素个数减一

	SeqListErase(ps, 0);//删除下标为0的位置的数据
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//保证顺序表不为空
	//ps->size--;//顺序表元素个数减一

	SeqListErase(ps, ps->size - 1);//删除下标为ps->size - 1的位置的数据
}

//指定下标位置删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);//保证顺序表不为空
	assert(pos >= 0 && pos < ps->size);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)//从pos下标位置开始，其后的数据从前往后依次向前覆盖
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;//顺序表元素个数减一
}

//查找元素，若有，返回下标，否则返回-1
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)//遍历顺序表进行查找
	{
		if (ps->a[i] == x)
			return i;//找到该数据，返回下标
	}
	return -1;//未找到，返回-1
}

//修改指定下标位置元素
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//检查输入下标的合法性
	ps->a[pos] = x;//修改数据
}