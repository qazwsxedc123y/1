#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1("hello world");
	s1.erase(8, 1);
	cout << s1 << endl;
	return 0;
}