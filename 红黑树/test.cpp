#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"RBTree.h"
int main()
{
	const int N = 10000;
	vector<int> v;
	v.reserve(N);
	//srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
	}
	size_t begin2 = clock();
	RBTree<int, int> t;
	for (auto e : v)
	{
		if (e == 26500)
		{
			int m = 0;
		}
		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();
	cout << t.IsBalance() << endl;
	return 0;
}