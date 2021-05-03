#include "BinaryTree.h"
#include "queue.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int main()
{
	BTNode* A = BuyNode('A');
	BTNode* B = BuyNode('B');
	BTNode* C = BuyNode('C');
	BTNode* D = BuyNode('D');
	BTNode* E = BuyNode('E');
	BTNode* F = BuyNode('F');
	//BTNode* G = BuyNode('G');
	A->left = B;
	A->right = C;
	B->left = D;
	//B->right = G;
	C->left = E;
	C->right = F;

	printf("前序遍历:");
	BinaryPrevOrder(A);
	printf("\n");

	printf("中序遍历:");
	BinaryInOrder(A);
	printf("\n");

	printf("后序遍历:");
	BinaryPostOrder(A);
	printf("\n");

	printf("结点的个数:%d\n", BinaryTreeSize(A));

	printf("叶子结点的个数:%d\n", BinaryTreeLeafSize(A));

	printf("第%d层结点的个数:%d\n", 3, BinaryTreeKLevelSize(A, 3));

	printf("值为%c的结点地址:%p\n", 'E', BinaryTreeFind(A, 'E'));
	printf("值为%c的结点地址:%p\n", 'G', BinaryTreeFind(A, 'G'));

	printf("最大深度:%d\n", BinaryTreeMaxDepth(A));

	printf("层序遍历:");
	BinaryLevelOrder(A);
	printf("\n");

	printf("是否是完全二叉树:%d\n", IsCompleteTree(A));

	printf("是否是单值二叉树:%d\n", IsUnivalTree(A));

	BinaryTreeDestroy(A);
	A = NULL;
	return 0;
}