#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.erase(a.begin() + 2);
	//cout <<  <<endl;
	return 0;
}