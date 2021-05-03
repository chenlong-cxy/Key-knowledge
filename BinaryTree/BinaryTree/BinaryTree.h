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

//深度优先
//前序遍历
void BinaryPrevOrder(BTNode* root);
//中序遍历
void BinaryInOrder(BTNode* root);
//后序遍历
void BinaryPostOrder(BTNode* root);
//广度优先
//层序遍历
void BinaryLevelOrder(BTNode* root);

//结点的个数
int BinaryTreeSize(BTNode* root);
//叶子结点的个数
int BinaryTreeLeafSize(BTNode* root);
//第k层结点的个数
int BinaryTreeKLevelSize(BTNode* root, int k);

//查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//树的最大深度
int BinaryTreeMaxDepth(BTNode* root);

//二叉树销毁
void BinaryTreeDestroy(BTNode* root);
//void BinaryTreeDestroy(BTNode** root);
//void BinaryTreeDestroy(BTNode*& root);//取别名

//判断二叉树是否是完全二叉树
bool IsCompleteTree(BTNode* root);
//判断二叉树是否是单值二叉树
bool IsUnivalTree(BTNode* root);