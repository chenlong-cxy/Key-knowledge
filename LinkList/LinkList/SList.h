#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//��ӡ����
void SListPrint(SListNode* plist);

//ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x);
//β��
void SListPushBack(SListNode** pplist, SLTDataType x);
//�м����


//ͷɾ
void SListPopFront(SListNode** pplist);
//βɾ
void SListPopBack(SListNode** pplist);
//�м�ɾ��