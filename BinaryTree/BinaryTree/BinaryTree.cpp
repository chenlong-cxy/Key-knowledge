#include "BinaryTree.h"
#include "queue.h"

//�������
//ǰ�����
void BinaryPrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryPrevOrder(root->left);
	BinaryPrevOrder(root->right);
}

//�������
void BinaryInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryInOrder(root->left);
	printf("%c ", root->data);
	BinaryInOrder(root->right);
}

//�������
void BinaryPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryPostOrder(root->left);
	BinaryPostOrder(root->right);
	printf("%c ", root->data);
}

//�������
//�������
void BinaryLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}

//���ĸ���
int BinaryTreeSize(BTNode* root)
{
	//if (root == NULL)
	//{
	//	return 0;
	//}
	//return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;

	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//��k����ĸ���
int BinaryTreeKLevelSize(BTNode* root, int k)
{
	if (k < 1 || root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeKLevelSize(root->left, k - 1) + BinaryTreeKLevelSize(root->right, k - 1);
}

//����ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret)
		return lret;
	BTNode* rret = BinaryTreeFind(root->right, x);
	if (rret)
		return rret;
	return NULL;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

//����������
int BinaryTreeMaxDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	return Max(BinaryTreeMaxDepth(root->left), BinaryTreeMaxDepth(root->right)) + 1;
}

//����������
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//void BinaryTreeDestroy(BTNode** root)
//{
//	if (*root == NULL)
//		return;
//
//	BinaryTreeDestroy(&(*root)->left);
//	BinaryTreeDestroy(&(*root)->right);
//	free(*root);
//	*root = NULL;
//}

//void BinaryTreeDestroy(BTNode*& root)//ȡ����
//{
//	if (root == NULL)
//		return;
//
//	BinaryTreeDestroy(root->left);
//	BinaryTreeDestroy(root->right);
//	free(root);
//	root = NULL;
//}

//�ж϶������Ƿ�����ȫ������
bool IsCompleteTree(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

//�ж϶������Ƿ��ǵ�ֵ������
bool IsUnivalTree(BTNode* root)
{
	if (root == NULL)
		return true;
	if (root->left && root->left->data != root->data)
		return false;
	if (root->right && root->right->data != root->data)
		return false;
	return IsUnivalTree(root->left) && IsUnivalTree(root->right);
}

//ǰ�����
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void preorder(BTNode* root, int* arr, int* pi)
{
	if (root == NULL)
		return;
	arr[(*pi)++] = root->data;
	//printf("%d ",root->val);
	preorder(root->left, arr, pi);
	preorder(root->right, arr, pi);
}
int* preorderTraversal(BTNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	preorder(root, arr, &i);
	return arr;
}