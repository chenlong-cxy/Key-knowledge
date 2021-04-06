#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//打印链表
void SListPrint(SListNode* plist);

//头插
void SListPushFront(SListNode** pplist, SLTDataType x);
//尾插
void SListPushBack(SListNode** pplist, SLTDataType x);
//中间插入


//头删
void SListPopFront(SListNode** pplist);
//尾删
void SListPopBack(SListNode** pplist);
//中间删除