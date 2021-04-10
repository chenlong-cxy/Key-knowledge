#include "SeqList.h"
void SeqListTest1()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 9);
	SeqListInsert(&s, 2, 9);
	SeqListInsert(&s, 2, 9);
	SeqListPrint(&s);

	SeqListDestory(&s);
}
void SeqListTest2()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListErase(&s, 2);
	SeqListPrint(&s);

	int ret = SeqListFind(&s, 2);
	printf("%d\n", ret);
	SeqListModify(&s, 2, 9);
	SeqListPrint(&s);
}

void SeqListTest3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
}
void SeqListTest4()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	printf("��3��Ԫ��ɾ����");
	SeqListErase(&s, 2);
	SeqListPrint(&s);
}
void SeqListTest5()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	int pos = SeqListFind(&s, 2);
	printf("ֵΪ2��Ԫ�ص�λ��Ϊ%d\n", pos + 1);
}
int main()
{
	//SeqListTest1();//�������
	//SeqListTest2();//ɾ������
	SeqListTest3();
	SeqListTest4();
	SeqListTest5();
	return 0;
}