#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
			return month_day[month];
	}



	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}



	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (&d != this)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}



	// 析构函数

	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}



	// 日期+=天数

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}



	// 日期+天数

	Date operator+(int day)
	{
		if (day < 0)
		{
			return *this - (-day);
		}
		Date tmp(*this);
		tmp += day;
		return tmp;
	}



	// 日期-天数

	Date operator-(int day)
	{
		if (day < 0)
		{
			return *this + (-day);
		}
		Date tmp(*this);
		tmp += -day;
		return tmp;
	}



	// 日期-=天数

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += (-day);
		}
		_day -= day;
		while (_day < 0)
		{
			--_month;
			_day += GetMonthDay(_year, _month);			
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
		}
		return *this;
	}



	// 前置++

	Date& operator++()
	{
		return *this += 1;
	}



	// 后置++

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}



	// 后置--

	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}



	// 前置--

	Date& operator--()
	{
		return *this -= 1;
	}



	// >运算符重载

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		    return false;
	}



	// ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}



	// >=运算符重载

	bool operator >= (const Date& d)
	{
		return ((*this > d) || (*this == d));
	}



	// <运算符重载

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}



	// <=运算符重载

	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}



	// !=运算符重载

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// 日期-日期 返回天数

	int operator-(const Date& d)
	{
		Date left = *this;
		Date right = d;
		int flag = 1;
		if (left < right)
		{
			left = d;
			right = *this;
			flag = -1;
		}
		int n = 0;
		while (left != right)
		{
			++n;
			++right;
		}
		return n * flag;
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int year = 0, month = 0, day = 0, m = 0;
		cin >> year >> month >> day >> m;
		Date d(year, month, day);
		d += m;
		cout << d._year << "-" << d._month << "-" << d._day;
	}
	return 0;
}

//
//class A
//
//{
//
//public:
//
//	A(int a)
//
//		:_a1(a)
//
//		, _a2(_a1)
//
//	{}
//
//
//
//	void Print()
//
//	{
//
//		cout << _a1 << " " << _a2 << endl;
//
//	}
//
//private:
//
//	int _a2;
//
//	int _a1;
//
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//}
//int main()
//{
//	Date d1(2024, 7, 8);//7月有31天
//	cout << "2024年7月有" << d1.GetMonthDay(2024, 7) << "天" << endl;
//	Date d2(d1);
//	cout << "拷贝构造：";
//	d2.print();
//	Date d3;
//	cout << "赋值运算符重载前：";
//	d3.print();
//	cout << "赋值运算符重载后：";
//	d3 = d1;
//	d3.print();
//	cout << "d1,日期 += 天数：";
//	d1 += 1;
//	d1.print();
//	cout << "d1,日期 + 天数：";
//	Date d4=d1 + 1;
//	d4.print();
//	cout << "d1,日期 - 天数：";
//	d4 = d1 - 1;
//	d4.print();
//	cout << "d1,日期 -= 天数：";
//	d1 -= 1;
//	d1.print();
//	cout << "d1,前置++：";
//	++d1;
//	d1.print();
//	cout << "d1,后置++：";
//	d4 = d1++;
//	d4.print();
//	cout << "d1,后置--：";
//	d4 = d1--;
//	d4.print();
//	cout << "d1,前置--：";
//	--d1;
//	d1.print();
//	cout << "d1,日期 - 日期：";
//	cout << d1 - d4 << endl;
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << a._a << endl;
//		}
//	};
//private:
//	int _a;
//};
//int main()
//{
//	A::B b;
//	b.foo(A(1));
//	return 0;
//}


//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成
//	//员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}
//class A
//{
//public:
//	A() { A::GetACount(); }//或者GetACount();都可以
//	A(const A& t)
//	{ 
//		A::GetACount();
//	}
//	~A() { --_scount; }
//	static int GetACount() 
//	{ 
//		++_scount;
//		return _scount; 
//	}
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
////或者int MyClass::count = 0; // 在类外定义静态成员变量，不添加 static 关键字
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//int main()
//{
//	TestA();
//	return 0;
//}


//class Date
//{
//public:
//
//	
//	//  虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转
//   //换作用
//	// explicit修饰构造函数，禁止类型转换
//	explicit Date(int year = 1, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	Date d1();
//}
//int main()
//{
//	Test();
//	return 0;
//}


//#define swap_bits(num) (((num&0x55555555)<<1)|((num&0xAAAAAAAA)>>1))
////第一个是奇位  ，第二个为偶位
//int main()
//{
//	int num = 123;  // 0111 1011    10110111  183
//	printf("交换前: %d\n", num);
//	printf("预计答案:183\n");
//	int ret = swap_bits(num);
//	printf("交换后: %d\n", ret);
//	return 0;
//}

//默认对齐数的修改

//#pragma pack(4)//设置默认对齐数为4  此时这个结构体大小为12
////#pragma pack()//中不写数字的话，表示取消之前的指定对齐数，改为默认的值
////默认对齐数为1的话下面大小就是9
//struct s
//{
//	char a;
//	double d;
//};
//int main()
//{
//	printf("%d", sizeof(s));
//	return 0;
//}


//宏的使用  offsetof
//需要引用头文件  stddef.h
//作用查看该类型所在的偏移量
//第一个为类型名（不是变量名）
//第二个是成员名

//#define my_offsetof(type,member) (size_t)(&(((type*)0)->member))
////先将结构体地址手动置为0，此时member也会改变，然后将其指向member
////此时member的地址对应的就是偏移量
//struct s
//{
//	char a;
//	int c;
//	double d;
//};
//int main()
//{
//	printf("%d\n", my_offsetof(struct s, a));
//	printf("%d\n", offsetof(struct s, a));
//	return 0;
//}

//int main()
//{
//	int* p = new int[10];
//
//	// 将该函数放在main函数之后，每次程序退出的时候就会检测是否存在内存泄漏
//	_CrtDumpMemoryLeaks();
//	return 0;
//}

//
//                  先走析构函数
//delete 
//                  后进行调用operator  delete(与c语言的free差不多)

//          operator new
//new  
//          placement new

//class A 
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int b = 0)
//		: _b(b)
//	{
//		cout << "B():" << this << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//private:
//	int _b;
//};
//A a(2);
//
//int main()
//{
//	int tmp = 8;
//	int n = 1;
//	for (int i = 0; i < 31; i++)
//	{
//		if (tmp % 2 == 1)
//			break;
//		else
//		{
//
//
//				n *= 2;
//		}
//		tmp >>= 1;
//	}
//	return 0;
//}

//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构
//	//造函数和析构函数
//	A* a1 = new A(2);
//	A* a2 = (A*)malloc(sizeof(A));
//
//	free(a2);
//	delete a1;
//	return 0;
//}

//int main()
//{
//	//动态开辟一个int类型的对象
//	int* p1 = new int;
//	//动态开辟一个int类型的空间并初始化为10
//	int* p2 = new int(10);
//	//动态申请10个int类型的空间
//	int* p3 = new int[10];
//
//	//在c语言中我们动态开辟后又free，同样在c++中也有操作符delete
//	delete p1;
//	delete p2;
//	delete []p3;//注意数组的要加[]
//	return 0;
//}


//using namespace std;
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char char2[] = "abcd";
//	const char* pchar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4,sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2,sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//int main()
//{
//	test();
//	return 0;
//}



//int main()
//{
//	string t("abcdef");
//	string::iterator it = t.begin();
//	while (it != t.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//    vector<double> v{ 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
//
//    vector<double>::iterator biggest = max_element(begin(v), end(v));
//    cout << "Max element is " << *biggest << " at position " << distance(begin(v), biggest) << endl;
//
//    auto smallest = min_element(begin(v), end(v));
//    cout << "min element is " << *smallest << " at position " << distance(begin(v), smallest) << endl;
//
//    return 0;
//}

//istream& operator>>(istream& in, string& s)
//{
//	s.clear();
//	char ch;
//	ch = in.get();
//	while (ch != ' ' && ch != '\n')
//	{
//		s += ch;
//		ch = in.get();
//	}
//	return in;
//}
//int main()
//{
//	int aa = 0;
//	printf("栈区的地址：%p\n", &aa);
//	int* pl = new int;
//	printf("堆区的地址：%p\n", pl);
//	string a("abcddddddddddddddddddddddddd", 16);
//	printf("a的地址:    %p\n", &a);
//	printf("a[0]的地址: %p\n", &a[0]);
//	a[1] = 'X';
//	cout << a << endl;
//	printf("a的地址:    %p\n", &a);
//	printf("a[0]的地址: %p\n", &a[0]);
//	string b("abc");
//	printf("b的地址:    %p\n", &b);
//	printf("b[0]的地址: %p\n", &b[0]);
//	return 0;
//}


//int main()
//{
//	string b("abcd");
//	cout << b.c_str();
//	return 0;
//}
//int main()
//{
//	string b("abcd",3);//这种构造方法是通过字符串abcd，然后只取前3个字符进行构造string
//	//但是这个字符串存放的其实是 abcd\0
//	cout << b.capacity() << endl;
//	cout << b.size() << endl;
//
//	if (b[3] == '\0')
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//	return 0;
//}