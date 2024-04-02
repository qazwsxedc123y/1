#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<errno.h>
#include<time.h>

typedef int BTDataType;
typedef struct BTNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x);

void Prev_Order(BTNode* root);
void In_Order(BTNode* root);
void Post_Order(BTNode* root);

int BT_Size(BTNode* root);

int BT_Leaf_Size(BTNode* root);

int BT_Depth_Size(BTNode* root);

int BT_Size_Levre_k(BTNode* root, int k);