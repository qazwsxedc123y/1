#define  _CRT_SECURE_NO_WARNINGS

#include"BTree.h"

//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;

BTNode* BuyNode(BTDataType* a,int* pi)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
	}
	node->_data = a[*pi];
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
//// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (n <= *pi)
	{
		return NULL;
	}
	if (a[*pi] == '#' )
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = BuyNode(a,pi);
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) +
		BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) +
		BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BinaryTreeFind(root->_left, x);
	BinaryTreeFind(root->_right, x);
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		return;
	}
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* Front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", Front->_data);
		if (Front->_left)
		{
			QueuePush(&q, Front->_left);
		}
		if (Front->_right)
		{
			QueuePush(&q, Front->_right);
		}
	}
	printf("\n");
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* Front = QueueFront(&q);
		QueuePop(&q);
		if (Front == NULL)
		{
			break;
		}
		QueuePush(&q, Front->_left);
		QueuePush(&q, Front->_right);
	}
	//检查后面是否全空，
	while (!QueueEmpty(&q))
	{
		BTNode* Front = QueueFront(&q);
		QueuePop(&q);
		if (Front != NULL)
		{
			return false;
		}
	}
	return true;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}