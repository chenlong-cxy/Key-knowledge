#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
//在给定位置之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//在给定位置之前插入
void SListInsertBefore(SListNode** pplist, SListNode* pos, SLTDataType x);

//头删
void SListPopFront(SListNode** pplist);
//尾删
void SListPopBack(SListNode** pplist);
//删除给定位置之后的值
void SListErasetAfter(SListNode* pos);
//删除给定位置的值
void SListErasetCur(SListNode** pplist, SListNode* pos);
//删除给定位置之前的值
void SListErasetBefore(SListNode** pplist, SListNode* pos);

//查找数据
SListNode* SListFind(SListNode* plist, SLTDataType x);