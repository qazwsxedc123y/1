#define  _CRT_SECURE_NO_WARNINGS

#include"gg.h"

BTNode* Creat_Node()
{
	BTNode* Node1 = BuyNode(1);
	BTNode* Node2 = BuyNode(2);
	BTNode* Node3 = BuyNode(3);
	BTNode* Node4 = BuyNode(4);
	BTNode* Node5 = BuyNode(5);
	BTNode* Node6 = BuyNode(6);
	//BTNode* Node7 = BuyNode(7);
	Node1->left = Node2;
	Node1->right = Node4;
	Node2->left = Node3;
	Node4->left = Node5;
	Node4->right = Node6;
	//Node6->right = Node7;
	return Node1;
}
int main()
{
	BTNode* root = Creat_Node();

	Prev_Order(root);
	printf("\n");
	In_Order(root);
	printf("\n");
	Post_Order(root);
	printf("\n");

	int ret = BT_Size(root);
	printf("size=%d\n", ret);

	//求叶子结点个数
	printf("BT_Leaf_Size:%d\n", BT_Leaf_Size(root));

	//求深度
	printf("BT_Depth_Size:%d\n", BT_Depth_Size(root));

	//求第k层的结点个数
	printf("BT_Size_Levre_k:%d\n", BT_Size_Levre_k(root, 3));

	//寻找值为k的结点
	printf("%p\n", BTFind_Data_k(root, 5));

	//层序遍历打印
	Lever_Order(root);

	//// 判断二叉树是否是完全二叉树
	//printf("%s\n", BinaryTreeComplete(root) ? "true" : "false");

	////销毁
	//BinaryTreeDestory(root);
	return 0;
}