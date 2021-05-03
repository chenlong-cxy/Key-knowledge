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

	printf("ǰ�����:");
	BinaryPrevOrder(A);
	printf("\n");

	printf("�������:");
	BinaryInOrder(A);
	printf("\n");

	printf("�������:");
	BinaryPostOrder(A);
	printf("\n");

	printf("���ĸ���:%d\n", BinaryTreeSize(A));

	printf("Ҷ�ӽ��ĸ���:%d\n", BinaryTreeLeafSize(A));

	printf("��%d����ĸ���:%d\n", 3, BinaryTreeKLevelSize(A, 3));

	printf("ֵΪ%c�Ľ���ַ:%p\n", 'E', BinaryTreeFind(A, 'E'));
	printf("ֵΪ%c�Ľ���ַ:%p\n", 'G', BinaryTreeFind(A, 'G'));

	printf("������:%d\n", BinaryTreeMaxDepth(A));

	printf("�������:");
	BinaryLevelOrder(A);
	printf("\n");

	printf("�Ƿ�����ȫ������:%d\n", IsCompleteTree(A));

	printf("�Ƿ��ǵ�ֵ������:%d\n", IsUnivalTree(A));

	BinaryTreeDestroy(A);
	A = NULL;
	return 0;
}