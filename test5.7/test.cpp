#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<list>
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
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:

	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		//, _x(5)
		//, a(1)
	{
	}
	void print()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
istream& operator>>(istream& cin, Date& d)
{
	cin >> d._year >> d._month >> d._day;
	return cin;
}



//class A
//{
//public:
//	A(int i)
//		:_a(i)
//	{
//	}
//private:
//	int _a;
//};

//int main()
//{
//	A aa1(A(1));
//	A aa2 = 2;
//	//用2调用A的函数构造，生成一个临时变量，在用这个对象去拷贝构造函数
//	//A& ref = 2;
//	const A& ref = 2;
//	return 0;
//}




class Solution {
	class sum {
	public:
		sum() {
			_ret += _i;
			_i++;
		}
		static int getret() {
			return _ret;
		}
	};
public:
	int Sum_Solution(int n) {
		//sum a[n];
		return _ret;
	}
private:
	static int _i;
	static int _ret;
};
int Solution::_i = 1;
int Solution::_ret = 0;


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

class B
{
public:
	B()//生成一次加1
	{
		++_count;
	}
	B(const B& t)
	{
		++_count;
	}
	static int getret()
	{
		return _count;
	}
	~B()
	{
		--_count;
	}
private:
	static int _count;
};
int B::_count = 0;

//int main()
//{
//	B b1;
//	B b2;
//	B b3(b1);
//	cout << B::getret() << endl;
//	cout << "---------------"  << endl;
//	const B();
//	cout << B::getret() << endl;
//	return 0;
//}


struct ListNode
{
	struct ListNode* next;
	int _val;
	ListNode(int val=0)
		:_val(val)
		,next(nullptr)
	{
	}
};
//int main()
//{
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	ListNode* n5 = new ListNode(5);
//	ListNode* n6 = new ListNode(6);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	return 0;
//}

template<class T>
T add(T a, T b)
{
	return a + b;
}
template<class T>
T* func(int n)
{
	return new T[n];
}
template <class T>
class A
{
public:
	A(T a)
		:_a(a)
	{
	}
	~A();
private:
	T _a;
};
template <class T>
A<T>::~A()
{
	//delete _a;
}
void func(const string& s)
{
	//只可以读，不可以写
	auto it = s.begin();
	while (it != s.end())
	{
		//(*it)++;//写
		cout << *it << " ";//读
		++it;
	}
	cout << endl;
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}
void test1()
{
	string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyy");
	func(s1);
	string s2(s1);
	cout << s2 << endl;
	string s3(s1, 6, 5);//从第六个开始，拷贝5个
	cout << s3 << endl;
	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	s3.resize(7);
	s3.reserve(100);
	cout << s3.size() << endl;
	cout << s3.capacity() << endl;
	//s3.clear();//只会清空size与str，capacity不会变
	cout << s3.empty() << endl;//空是1  非空是0
	s3.shrink_to_fit();//减小capacity
	cout << s3.at(2) << endl;
	s3.push_back('a');

	s3.insert(0, 1, 'x');
	//s2.assign(s3);
	//cout << s2 << endl;
	//s3.append(s2);
	cout << s3 << endl;
	s3.erase(1, 5);
	cout << s3 << endl;
	string str("hello world5");
	str.back() = '!';//指向最后一个
	cout << str << endl;

	//string s4(s1, 6, s1.size() - 4);
	//cout << s4 << endl;
	//cout << s3.capacity() << endl;
	//cout << s3.max_size() << endl;
}
void test2()
{
	string s1("hello world");
	s1.replace(5, 1, "20%");
	cout << s1 << endl;
	string s2("The quick brown fox jumps over a lazy dog.");
	string s3;
	for (auto ch : s2)
	{
		if (ch != ' ')
		{
			s3 += ch;
		}
		else
		{
			s3 += "20%";
		}
	}
	cout << s3 << endl;
	swap(s2, s3);
	cout << s3 << endl;
	cout << s2 << endl;
}
void test3()
{
	string s1("test.cpp.tar.zip");
	size_t i = s1.rfind(".");
	string s2 = s1.substr(i);
	cout << s2 << endl;
	string s3("https://legacy.cplusplus.com/reference/string/string/rfind/");
	// 协议
    // 域名
    // 资源名
	string sub1, sub2, sub3;
	size_t i1 = s3.find(':');//返回的是下标
	//size_t i4 = s3.find('h');//返回的是下标
	if (i1 != string::npos)
	{
		sub1 = s3.substr(0, i1);//第二个参数是个数，不是下标
	}
	else
	{
		cout << "没有找到i1" << endl;
	}
	size_t i2 = s3.find('/', i1 + 3);
	sub2 = s3.substr(i1 + 3, i2 - (i1 + 3));
	sub3 = s3.substr(i2 + 1);
	cout << sub1 << endl;
	cout << sub2 << endl;
	cout << sub3 << endl;
}
void test4()
{
	string str("Please, replace the vowels in this sentence by asterisks.");
	string s1("P");
	size_t found = str.find_first_of("abcd");
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("abcd", found + 1);
	}
	cout << str << '\n';
}
int main()
{


	test4();

	//string s1;
	//cin >> s1;
	//cout << s1 << endl;
	//cin >> s1;
	//cout << s1 << endl;
	//string s2 = ("asasasas");
	//string s3 = "hello world";
	//string ret = s2 + s3 + "我来了";
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << ret << endl;
	//string::iterator it = s3.begin();
	////auto it = s3.begin();
	//auto end = s3.rbegin();
	//while (it != s3.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	//for (auto ch : s3)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;
	//while (end != s3.rend())
	//{
	//	cout << *end << " ";
	//	++end;
	//}
	//cout << endl;

	//string s1(s3, 6);
	//for (auto ch : s1)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;
	//for (auto& end : s3)
	//{
	//	++end;
	//}
	//for (auto ch : s3)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;


	////char arr[] = "asdasd";//字符串数组
	////char arr[] = { 'a','b','c' };//字符数组，不带‘/0’


	////cout << add(1, 1) << endl;
	////cout << add((double)1, 1.2) << endl;
	////cout << add<double>(1, 1.21) << endl;

	////int* p1=func<int>(5);//必须要进行显示实例化

	////A <int> a1(5);
	////A <double> a2(5.5);

	////char s2[] = "hello world";
	////string s1 = ("hello world");
	////int a1=sizeof(s1);
	////int a2=sizeof(s2);

	////内存栈
	////B* b1 = (B*)operator new(sizeof(B));
	////new(b1)B();

	////b1->~B();
	////operator delete(b1);
	//string s;
	//cin >> s;
	////sort(s);
	//for (auto ch : s)
	//{
	//	cout << ch << " ";
	//}
	return 0;
}