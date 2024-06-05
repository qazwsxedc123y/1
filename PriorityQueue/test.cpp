#define  _CRT_SECURE_NO_WARNINGS
#include"Priority_Queuq.h"

// 仿函数
//class Less
//{
//public:
//    bool operator()(int x, int y)
//    {
//        return x < y;
//    }
//};
template<class T>
class Less//大堆
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
void test_1()
{
	test::priority <int> s;
	s.push(3);
	s.push(1);
	s.push(5);
	s.push(4);
	int arr[10] = { 12,3,4,5,6,8,92 };
	test::priority <int> a(arr, arr + 6);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	while (!a.empty())
	{
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;
}
void test_2()
{
	test::priority <int,vector<int>,Greater<int>> s;
	s.push(3);
	s.push(1);
	s.push(5);
	s.push(4);
	int arr[10] = { 12,3,4,5,6,8,92 };
	test::priority <int, vector<int>, Greater<int>> a(arr, arr + 6);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	while (!a.empty())
	{
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d) const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d) const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 特化 -- 全特化
template<>
class Data<int, double>
{
public:
	Data() { cout << "Data<int, double>" << endl; }
};

template<>
class Data<int, int>
{
public:
	Data() { cout << "Data<int, int>" << endl; }
};

template<>
class Data<double, double>
{
public:
	Data() { cout << "Data<double, double>" << endl; }
};

//template<>
//class Less<Date*>
//{
//public:
//	bool operator()(Date* x, Date* y)
//	{
//		return *x < *y;
//	}
//};
template<class T>
class Less<T*>
{
public:
	bool operator()(T* x, T* y)
	{
		return *x < *y;
	}
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};
int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	Data<double, double> d3;
	Data<double*, double*> d4;
	Data<int*, double*> d5;


    test::priority<Date> q1;
    q1.push(Date(2018, 10, 29));
    q1.push(Date(2018, 10, 28));
    q1.push(Date(2018, 10, 30));
    cout << q1.top() << endl;

    test::priority<Date*> q2;
    q2.push(new Date(2018, 10, 29));
    q2.push(new Date(2018, 10, 28));
    q2.push(new Date(2018, 10, 30));
    cout << *(q2.top()) << endl;

    return 0;
}


//int main()
//{
//	//Less<int> less;
//	//cout << less(3, 2) << endl;
//	Greater<int> greater;
//	//cout << greater(10, 6) << endl;
//
//	test_2();
//	//test_1();
//	return 0;
//}