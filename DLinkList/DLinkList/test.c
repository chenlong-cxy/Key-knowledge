#include "List.h"

void Test()
{
	ListNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushFront(plist, 9);
	ListPushFront(plist, 8);
	ListPushFront(plist, 7);
	ListPushFront(plist, 6);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 8);
	ListInsert(pos, 10);
	ListPrint(plist);

	ListErase(pos);
	ListPrint(plist);
	printf("%d\n", ListSize(plist));

	ListDestroy(plist);
}
int main()
{
	Test();
	return 0;
}