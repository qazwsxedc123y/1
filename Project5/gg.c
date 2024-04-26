#define  _CRT_SECURE_NO_WARNINGS

#include"gg.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int BT_Size(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BT_Size(root->left) + BT_Size(root->right) + 1;
}

int BT_Leaf_Size(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BT_Leaf_Size(root->left) +
		BT_Leaf_Size(root->right);
}

int BT_Depth_Size(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left_Depth_Size = BT_Depth_Size(root->left);
	int right_Depth_Size = BT_Depth_Size(root->right);
	return left_Depth_Size > right_Depth_Size ?
		BT_Depth_Size(root->left) + 1 : 
		BT_Depth_Size(root->right) + 1;
}

int BT_Size_Levre_k(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BT_Size_Levre_k(root -> left, k - 1) +
		BT_Size_Levre_k(root -> right, k - 1);
}

BTNode* BTFind_Data_k(BTNode* root, int k)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == k)
	{
		return root;
	}
	BTNode* ret1 = BTFind_Data_k(root->left, k);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = BTFind_Data_k(root->right, k);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}
void Prev_Order(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);
	Prev_Order(root->left);
	Prev_Order(root->right);
}
void In_Order(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	In_Order(root->left);
	printf("%d ", root->val);
	Prev_Order(root->right);
}
void Post_Order(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	In_Order(root->left);
	Prev_Order(root->right);
	printf("%d ", root->val);
}
void Lever_Order(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePop(&q);
		printf("%d ", front->val);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
}
