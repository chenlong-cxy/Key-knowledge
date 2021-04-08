#include "SList.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 0);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPushFront(&plist, 0);
	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

void TestSList2()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 0);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
}

void TestSList3()
{
	SListNode* plist = NULL;
	//SListPushBack(&plist, 0);
	//SListPushBack(&plist, 1);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPrint(plist);

	SListNode* pos = SListFind(plist, 5);
	if (pos == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了\n");
	}
}

void TestSList4()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 0);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 3);
	SListInsertAfter(pos, 30);

	SListPrint(plist);

	SListInsertBefore(&plist, pos, 9);
	SListPrint(plist);

	pos = SListFind(plist, 0);
	SListInsertBefore(&plist, pos, 8);
	SListInsertBefore(&plist, pos, 7);
	SListErasetAfter(pos);
	SListErasetCur(&plist, pos);
	SListPrint(plist);
	pos = SListFind(plist, 8);
	SListModify(pos, 100);
	SListPrint(plist);
}
int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	TestSList4();
	return 0;
}