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
int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
	return 0;
}