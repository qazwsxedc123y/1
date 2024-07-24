#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"RBTree.h"
int main()
{
	RBTree<int, int> t;
	t.Insert(make_pair(1, 1));
	t.Insert(make_pair(2, 2));
	return 0;
}