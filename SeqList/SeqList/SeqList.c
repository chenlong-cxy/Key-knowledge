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
	ps = NULL;
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

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps);
}

//β��
void SeqListPushBack(SeqList* ps, SLDataType x);
//ָ���±�λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDataType x);