#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int& func()
{
	int a = 0;
	a++;
	return a;
}
int main()
{
	int& a = func();
	cout << "a = " << a << endl;
	cout << "a = " << a << endl;
	return 0;
}