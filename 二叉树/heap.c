#define  _CRT_SECURE_NO_WARNINGS

#include"heap.h"

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

void Prev_Order(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
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
		printf("N ");
		return;
	}
	In_Order(root->left);
	printf("%d ", root->val);
	In_Order(root->right);
}

void Post_Order(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	Post_Order(root->left);

	Post_Order(root->right);
	printf("%d ", root->val);
}

int BT_Size(BTNode* root)
{
	return root == NULL ? 0 : BT_Size(root->left) +
		BT_Size(root->right) + 1;
}


int BT_Leaf_Size(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BT_Leaf_Size(root->left) +
		BT_Leaf_Size(root->right);
}

int BT_Depth_Size(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left_depth = BT_Depth_Size(root->left);
	int right_depth = BT_Depth_Size(root->right);
	return 
		left_depth > right_depth ? 
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
	return BT_Size_Levre_k(root->left, k - 1) +
		BT_Size_Levre_k(root->right, k - 1);
}