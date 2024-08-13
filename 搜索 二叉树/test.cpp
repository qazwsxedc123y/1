#include<iostream>
using namespace std;
#include"BinarySearchTree.h"
#include"KVTree.h"

int main()
{
	test::TestBSTree();
	return 0;
}

//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> bt;
//	for (auto e : a)
//	{
//		bt.InsertR(e);
//	}
//	bt.InOrder();
//	//cout << bt.Find(3) << endl;
//	bt.EraseR(6);
//	bt.Erase(4);
//	bt.InOrder();
//	for (auto e : a)
//	{
//		bt.EraseR(e);
//		bt.InOrder();
//	}
//
//	return 0;
//}