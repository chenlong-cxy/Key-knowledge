#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;//�洢����������

typedef struct ListNode
{
	LTDataType data;//������
	struct ListNode* prev;//ǰ��ָ��
	struct ListNode* next;//����ָ��
}ListNode;

//��ʼ������
ListNode* ListInit();
//��������
void ListDestroy(ListNode* phead);
//��ӡ˫������
void ListPrint(ListNode* phead);

//β��
void ListPushBack(ListNode* phead, LTDataType x);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//βɾ
void ListPopBack(ListNode* phead);
//ͷɾ
void ListPopFront(ListNode* phead);

//����Ԫ��
ListNode* ListFind(ListNode* phead, LTDataType x);
//��ָ��λ�ò�����
void ListInsert(ListNode* pos, LTDataType x);
//ɾ��ָ��λ�ý��
void ListErase(ListNode* pos);

//�����п�
bool ListEmpty(ListNode* phead);
//��ȡ�����е�Ԫ�ظ���
int ListSize(ListNode* phead);