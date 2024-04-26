#define  _CRT_SECURE_NO_WARNINGS

#include"BTree.h"
int main()
{
	char ch[] = "ABD##E#H##CF##G##";
	int n = 17;
	int i = 0;
	BTNode* root= BinaryTreeCreate(ch, n, &i);
	printf("BinaryTreeSize=%d\n",BinaryTreeSize(root));
	printf("BinaryTreeLeafSize=%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevel_3_Size=%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeLevel_4_Size=%d\n", BinaryTreeLevelKSize(root, 4));
	printf("%p\n", BinaryTreeFind(root, 'A'));
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("%s", BinaryTreeComplete(root) ? "true" : "false");

	BinaryTreeDestory(root);
	return 0;
}