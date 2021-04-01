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
int main()
{
	//SeqListTest1();//≤Â»Î≤‚ ‘
	SeqListTest2();//…æ≥˝≤‚ ‘

	return 0;
}