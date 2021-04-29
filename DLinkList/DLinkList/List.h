#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;//存储的数据类型

typedef struct ListNode
{
	LTDataType data;//数据域
	struct ListNode* prev;//前驱指针
	struct ListNode* next;//后驱指针
}ListNode;

//初始化链表
ListNode* ListInit();
//销毁链表
void ListDestroy(ListNode* phead);
//打印双向链表
void ListPrint(ListNode* phead);

//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头插
void ListPushFront(ListNode* phead, LTDataType x);

//尾删
void ListPopBack(ListNode* phead);
//头删
void ListPopFront(ListNode* phead);

//查找元素
ListNode* ListFind(ListNode* phead, LTDataType x);
//在指定位置插入结点
void ListInsert(ListNode* pos, LTDataType x);
//删除指定位置结点
void ListErase(ListNode* pos);

//链表判空
bool ListEmpty(ListNode* phead);
//获取链表中的元素个数
int ListSize(ListNode* phead);