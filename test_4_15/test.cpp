#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
namespace _name
{
	int Add(int a, int b)
	{
		return a + b;
	}
	int Add(double a, double b)
	{
		return a + b;
	}
	//double Add(double a, double b)
	//{
	//	return a + b;
	//}
	int rand = 1;
	namespace name
	{
		int rand = 2;
	}
}
void Func(int a , int b , int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	Func(1,2);
	cout << "Add = " << _name::Add(1,2) << endl;
	cout << "Add = " << _name::Add(1.1,2.2) << endl;
	cout << "rand = " << _name::rand << endl;
	cout << "rand = " << _name::name::rand << endl;
	cout << "rand = " << rand << endl;
	return 0;
}