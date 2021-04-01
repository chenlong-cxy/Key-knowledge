#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SeqList;

//��ʼ��˳���
void SeqListInit(SeqList* ps);
//����˳���
void SeqListDestory(SeqList* ps);

//��ӡ˳���
void SeqListPrint(SeqList* ps);

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x);
//β��
void SeqListPushBack(SeqList* ps, SLDataType x);
//ָ���±�λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

//ͷɾ
void SeqListPopFront(SeqList* ps);
//βɾ
void SeqListPopBack(SeqList* ps);
//ָ���±�λ��ɾ��
void SeqListErase(SeqList* ps, int pos);

//����Ԫ�أ������±�
int SeqListFind(SeqList* ps, SLDataType x);

//�޸�ָ���±�λ��Ԫ��
void SeqListModify(SeqList* ps, int pos, SLDataType x);