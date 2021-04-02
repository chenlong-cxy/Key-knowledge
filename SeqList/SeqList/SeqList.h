#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;//本篇博客以存放整型数据为例

typedef struct SeqList
{
	SLDataType* a;//声明了一个指向顺序表的指针，姑且称它为“顺序表指针”
	int size;//记录当前顺序表内元素个数
	int capacity;//记录当前顺序表的最大容量
}SeqList;

//初始化顺序表
void SeqListInit(SeqList* ps);
//销毁顺序表
void SeqListDestory(SeqList* ps);

//打印顺序表
void SeqListPrint(SeqList* ps);

//头插
void SeqListPushFront(SeqList* ps, SLDataType x);
//尾插
void SeqListPushBack(SeqList* ps, SLDataType x);
//指定下标位置插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x);

//头删
void SeqListPopFront(SeqList* ps);
//尾删
void SeqListPopBack(SeqList* ps);
//指定下标位置删除
void SeqListErase(SeqList* ps, int pos);

//查找元素，返回下标
int SeqListFind(SeqList* ps, SLDataType x);

//修改指定下标位置元素
void SeqListModify(SeqList* ps, int pos, SLDataType x);