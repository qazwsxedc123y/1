#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


//class SLqust
//{
//public:
//	SLqust(int capacity=4)
//	{
//		_a=(int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//		memset(_a, 0, sizeof(int) * _capacity);
//	}
//	void push(int x)
//	{
//		if (_size == _capacity)
//		{
//			int capacity = _capacity == 0 ? 4 : _capacity * 2;
//			int* tmp = (int*)realloc(_a, sizeof(int)* capacity);
//			if (tmp == nullptr)
//			{
//				cout << "realloc fail" << endl;
//				return;
//			}
//			_a = tmp;
//			_capacity = capacity;
//		}
//		_a[_size++] = x;
//	}
//	int operator[](int i)
//	{
//		return _a[i];
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _x(5)
//		, a(1)
//	{
//	}
//	void print()const
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _x;
//	SLqust a;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	cout << d._year << "/" << d._month << "/" << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& cin, Date& d)
//{
//	cin >> d._year >> d._month >> d._day;
//	return cin;
//}
//int main()
//{
//	//SLqust d1(6);
//	//d1.push(1);
//	//d1.push(2);
//	//d1.push(3);
//	//d1.push(4);
//	//d1.push(5);
//	//cout << d1.operator[](2) << endl;
//	//cout << d1[2] << endl;
//	
//	 
//	Date d1(1, 2, 3);
//	cout << d1<<endl;
//	cin >> d1;
//	cout << d1 << endl;
//	d1.print();
//	return 0;
//}


class A
{
public:
	A(int i)
		:_a(i)
	{
	}
private:
	int _a;
};

int main()
{
	A aa1(1);
	A aa2 = 2;
	//用2调用A的函数构造，生成一个临时变量，在用这个对象去拷贝构造函数
	//A& ref = 2;
	const A& ref = 2;
	return 0;
}