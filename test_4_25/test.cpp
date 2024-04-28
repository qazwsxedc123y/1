#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include"test.h"
using namespace std;
//namespace _name
//{
//	int rand = 1;
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//	int add(int a=10)
//	{
//		return a + 1;
//	}
//}
//void count(int& n)
//{
//	n++;
//}
//int& as(int n)
//{
//	int x = 5;
//	return x;
//}
//int main()
//{
//
//	//int a = 1;
//	//count(a);
//	//int n=as(a);
//	//cout << _name::add() << endl;
//	//cout << _name::add(5, 5) << endl;
//	//cout << _name::rand << endl;
//	//cout << "count="<< a << endl;
//	//cout << "as="<< n << endl;
//	//cout << "saw" << endl;
//	 
//	
//	//int a = 1;
//	//const int& c = a;//权限缩小
//	//const int b = 2;
//	//const int& d = b;//权限平移
//	////   const int x = 6;
//	////   int& y = x;//权限放大
//
//	//int ret=ad(5, 6);
//	//cout << "ret=" << ret << endl;
//
//	//int b = 8;
//	//auto a = b;
//	//int arr[] = { 1,2,3,4,5,6 };
//	//for (auto e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//for (auto &e : arr)
//	//{
//	//	e *= 2;
//	//}
//	//for (auto e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	//cout << a << endl;
//
//
//	return 0;
//}

//class stack
//{
//public:
//	void Init()
//	{
//		a = nullptr;
//		top = capacity = 0;
//	}
//	void push(int x)
//	{
//		if (top == capacity)
//		{
//			int newcapacity = capacity == 0 ? 4 : capacity * 2;
//			int *tmp=(int* )realloc(a, sizeof(int) * newcapacity);
//			if (tmp == NULL)
//			{
//				perror("push fail");
//				return;
//			}
//			a = tmp;
//			capacity = newcapacity;
//		}
//		a[top++] = x;
//	}
//	void StackPop()
//	{
//		top--;
//	}
//	int StackTop()
//	{
//		return a[top - 1];
//	}
//	int StackEmpty()//空返回1，非空返回0
//	{
//		return top == 0;
//	}
//	void destroy()
//	{
//		a = NULL;
//		top = capacity = 0;
//	}
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//class Date
//{
//public:
//	void Init()
//	{
//		a = 'b';
//	}
//private:
//	char a;
//};
//class Data
//{
//public:
//	void Init()
//	{
//	}
//private:
//};
//class Dats
//{
//public:
//	void Init()
//	{
//	}
//private:
//	int a;
//	int b;
//	int c;
//};
//
//
//int main()
//{
//	stack st;
//	st.Init();
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.StackEmpty())
//	{
//		cout << st.StackTop() << " ";
//		st.StackPop();
//	}
//	st.destroy();
//	cout << endl;
//	cout <<  sizeof(Date) << endl;
//	cout <<  sizeof(Data) << endl;
//	cout <<  sizeof(stack) << endl;
//	cout <<  sizeof(Dats) << endl;
//	return 0;
//}

class date
{
public:
	//date()
	date(int year, int month = 2, int day = 2)	
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "/" << _month << "/" << _day <<  endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	date d1(;
	d1.print();
	return 0;
}