#include "SeqList.h"

//��ʼ��˳���
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;//��ʼʱԪ�ظ���Ϊ0
	ps->capacity = 0;//����Ϊ0
}

//����˳���
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//��ӡ˳���
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

//���˳��������Ƿ���������������������
void SeqCheckCapacity(SeqList* ps)
{
	//���ˣ���Ҫ����
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

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//�������
	//int i = 0;
	//for (i = ps->size; i > 0; i--)
	//{
	//	ps->a[i] = ps->a[i - 1];
	//}
	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);
}

//β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//�������
	//ps->a[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}

//ָ���±�λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqCheckCapacity(ps);//�������
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

//ͷɾ
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

//βɾ
void SeqListPopBack(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}
//ָ���±�λ��ɾ��
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

//����Ԫ�أ����У������±꣬���򷵻�-1
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

//�޸�ָ���±�λ��Ԫ��
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}