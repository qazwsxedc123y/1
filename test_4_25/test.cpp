#define  _CRT_SECURE_NO_WARNINGS
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

class stack
{
public:
	stack()
	{
		a = nullptr;
		top = capacity = 0;
	}
	stack(const stack& ps)
	{
		cout << "stack(const stack& ps)" << endl;
		a=(int*)malloc(sizeof(int)*(ps.capacity));
		if (a == NULL)
		{
			perror("malloc fail");
			return;
		}
		memcpy(a, ps.a, sizeof(int) * (ps.top));
		top = ps.top;
		capacity = ps.capacity;
	}
	void push(int x)
	{
		if (top == capacity)
		{
			int newcapacity = capacity == 0 ? 4 : capacity * 2;
			int *tmp=(int* )realloc(a, sizeof(int) * newcapacity);
			if (tmp == NULL)
			{
				perror("push fail");
				return;
			}
			a = tmp;
			capacity = newcapacity;
		}
		a[top++] = x;
	}
	void StackPop()
	{
		top--;
	}
	int StackTop()
	{
		return a[top - 1];
	}
	int StackEmpty()//空返回1，非空返回0
	{
		return top == 0;
	}
	~stack()
	{
		a = NULL;
		top = capacity = 0;
	}
private:
	int* a;
	int top;
	int capacity;
};


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
 
	//void ::print()
	//{
	//	cout << _year << "/" << _month << "/" << _day <<  endl;
	//}


date::date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
date::date(const date& d)
{
	//cout << "date(date& d)" << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
bool date::operator<(date& d)
{
	return _year < d._year ||
		((_year == d._year) && (_month < d._month)) ||
		((_year == d._year) && (_month == d._month) && (_day < d._day));
}
bool date::operator==(date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool date::operator!=(date& d)
{
	return !(*this == d);
}

bool date::operator<=(date& d)
{
	return *this == d || *this < d;
}

int date::Get_month_day(int year, int month)
{
	int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return month_day[month];
}

date date::operator += (int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > Get_month_day(_year, _month))
	{
		_day -= Get_month_day(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

date date::operator + (int day)
{
	if (day < 0)
	{
		return *this - (-day);
	}
	date tmp(*this);
	tmp += 50;
	return tmp;

	//date tmp(*this);
	//tmp._day += day;
	//while (tmp._day > Get_month_day(tmp._year, tmp._month))
	//{
	//	tmp._day -= Get_month_day(tmp._year, tmp._month);
	//	++tmp._month;
	//	if (tmp._month == 13)
	//	{
	//		tmp._year++;
	//		tmp._month = 1;
	//	}
	//}
	//return tmp;
}
date date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day < 0)
	{
		--_month;
		_day += Get_month_day(_year, _month);
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
	}
	return *this;
}
date date::operator-(int day)
{
	if (day < 0)
	{
		return *this + (-day);
	}
	date tmp(*this);
	tmp -= day;
	return tmp;
}

//日期 减 日期

int date::operator-(const date& d)
{
	date max = *this;
	date min = d;
	int flag = 1;
	if (max < min)
	{
		flag = -1;
		max = d;
		min = *this;
	}
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}
	return n * flag;
}

date date::operator++()//前置
{
	*this += 1;
	return *this;
}
date date::operator++(int)//后置
{
	date tmp(*this);
	*this += 1;
	return tmp;
}

//赋值
date& date::operator=(const date& d)
{
	if (this != &d)//1
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
date date::operator--()
{
	//this->operator-=(1);
	*this -= 1;//this为什么有时候加*，有时候不加？//2
	return *this;
}
date date::operator--(int)
{
	date tmp(*this);
	*this -= 1;
	return tmp;
}
void date::print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//date()
//{		
//}

//date(int year)
//{
//	_year = year;
//}

