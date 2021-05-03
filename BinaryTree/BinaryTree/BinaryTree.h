#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

//�������
//ǰ�����
void BinaryPrevOrder(BTNode* root);
//�������
void BinaryInOrder(BTNode* root);
//�������
void BinaryPostOrder(BTNode* root);
//�������
//�������
void BinaryLevelOrder(BTNode* root);

//���ĸ���
int BinaryTreeSize(BTNode* root);
//Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root);
//��k����ĸ���
int BinaryTreeKLevelSize(BTNode* root, int k);

//����ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//����������
int BinaryTreeMaxDepth(BTNode* root);

//����������
void BinaryTreeDestroy(BTNode* root);
//void BinaryTreeDestroy(BTNode** root);
//void BinaryTreeDestroy(BTNode*& root);//ȡ����

//�ж϶������Ƿ�����ȫ������
bool IsCompleteTree(BTNode* root);
//�ж϶������Ƿ��ǵ�ֵ������
bool IsUnivalTree(BTNode* root);