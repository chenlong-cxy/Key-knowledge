#include "SeqList.h"

//��ʼ��˳���
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;//�տ�ʼʱ˳���Ϊ�գ�˳���ָ��ΪNULL
	ps->size = 0;//��ʼʱԪ�ظ���Ϊ0
	ps->capacity = 0;//����Ϊ0
}

//����˳���
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);//�ͷ�˳���ָ��ָ��Ŀռ�
	ps->a = NULL;//��ʱ�ÿ�
	ps->size = 0;//Ԫ�ظ�����0
	ps->capacity = 0;//������0
}

//��ӡ˳���
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	//ѭ����ӡ˳���ָ��ָ�������
	printf("˳�������Ϊ:>");
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//���˳��������Ƿ���������������������
void SeqCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)//���ˣ���Ҫ����
	{
		//�ж�˳��������Ƿ�Ϊ0����Ϊ0�����ȿ������ڴ��4��Ԫ�صĿռ��С������Ϊ0��������Ϊԭ������������
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* newA = realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = newA;//���ٳɹ�����˳���ָ�����
		ps->capacity = newcapacity;//��������
	}
}

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//�������
	//int i = 0;
	//for (i = ps->size; i > 0; i--)//�����ݴӺ���ǰ�������Ų
	//{
	//	ps->a[i] = ps->a[i - 1];
	//}
	//ps->a[0] = x;
	//ps->size++;//˳���Ԫ�ظ�����һ

	SeqListInsert(ps, 0, x);//���±�Ϊ0��λ�ò�������
}

//β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	//assert(ps);
	//SeqCheckCapacity(ps);//�������
	//ps->a[ps->size] = x;
	//ps->size++;//˳���Ԫ�ظ�����һ

	SeqListInsert(ps, ps->size, x);//���±�Ϊps->size��λ�ò�������
}

//ָ���±�λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);//��������±�ĺϷ���
	SeqCheckCapacity(ps);//�������
	int i = 0;
	for (i = ps->size; i > pos; i--)//��pos�±�λ�ÿ�ʼ���������ݴӺ���ǰ�������Ų
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;//˳���Ԫ�ظ�����һ
}

//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//��֤˳���Ϊ��
	//int i = 0;
	//for (i = 0; i < ps->size - 1; i++)//�����ݴ�ǰ����������ǰ����
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}
	//ps->size--;//˳���Ԫ�ظ�����һ

	SeqListErase(ps, 0);//ɾ���±�Ϊ0��λ�õ�����
}

//βɾ
void SeqListPopBack(SeqList* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//��֤˳���Ϊ��
	//ps->size--;//˳���Ԫ�ظ�����һ

	SeqListErase(ps, ps->size - 1);//ɾ���±�Ϊps->size - 1��λ�õ�����
}

//ָ���±�λ��ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);//��֤˳���Ϊ��
	assert(pos >= 0 && pos < ps->size);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)//��pos�±�λ�ÿ�ʼ���������ݴ�ǰ����������ǰ����
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;//˳���Ԫ�ظ�����һ
}

//����Ԫ�أ����У������±꣬���򷵻�-1
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)//����˳�����в���
	{
		if (ps->a[i] == x)
			return i;//�ҵ������ݣ������±�
	}
	return -1;//δ�ҵ�������-1
}

//�޸�ָ���±�λ��Ԫ��
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//��������±�ĺϷ���
	ps->a[pos] = x;//�޸�����
}