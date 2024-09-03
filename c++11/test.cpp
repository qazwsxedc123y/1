#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
using namespace std;

#include<assert.h>

struct Point
{
	int _x;
	int _y;
};


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[5] = { 0 };//全部初始化为0
//	//对于类的初始化：
//	Point p2 = { 1,2 };
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// 一切都可以用列表初始化
// 并且可以省略掉=

// c++11中，可以这样初始化列表

//int main()
//{
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };//全部初始化为0
//	Point p{ 1, 2 };
//
//	Date d1(2023, 11, 25);
//	// 类型转换  构造+拷贝构造-》优化直接构造
//	Date d2 = { 2023,11,25 };
//	Date d2{ 2023,11,25 };
//
//	const Date& d3 = { 2023,11,25 };
//
//	Date* p1 = new Date[3]{ d1,d2,d3 };
//	Date* p2 = new Date[3]{ {2023,11,23},{2023,12,23},{2023,11,22} };
//	return 0;
//}


// 使用initializer_list 进行初始化类型

//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5,6 };
//	// 使用 vector<int> v2 = {1, 2, 3, 4, 5, 6};
//	// 进行初始化时，实际上是使用了一个列表初始化initialization_list 
//	// 创建一个临时的数组,这个数组包含了所有的元素。
//
//	//同样还有list的
//	list<int> l1 = { 1,2,3,4,5,6 };
//
//	// 多参数构造类型转换  构造+拷贝构造-》优化直接构造
//	// 跟对应构造函数参数个数匹配
//	// { 2023,11,23 }构造
//	// Date d2 = { 2023,11,23 };被视为拷贝构造
//	Date d2 = { 2023,11,23 };
//
//	// the type of il is an initializer_list 
//	auto li1 = { 10,20,30,40,50 };
//	cout << typeid(li1).name() << endl;
//	initializer_list<int>::iterator it1 = li1.begin();
//	while (it1 != li1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//	for (auto& e : li1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	pair <string, string> kv1{ "insert", "插入" };
//	map<string, string> dict = { {"insert", "插入"},{"get","获取"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	return 0;
//}


// 获取类型的名字

//int main()
//{
//	int i = 1;
//	double d = 2.2;
//	// 类型以字符串形式获取到
//	cout << typeid(i).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	// typeid 是一个运算符，用于获取表达式 i 的类型信息。
//	// typeid(i)返回一个 std::type_info 对象，该对象包含了 i 的类型信息。
//	// name() 方法返回一个 C 风格的字符串，表示 i 的类型名称。
//	// 这个名称的具体格式依赖于编译器，可能是人类可读的类型名，也可能是一些内部表示。
//
//	// typeid(i).name() j;// 不可以，因为返回类型为字符串形式
//	auto j = i;
//
//	auto ret = i * d;
//
//	decltype(ret) x;
//	cout << typeid(x).name() << endl; // double
//	// 用ret的类型去实例化vector
//	// decltype可以推导对象的类型。这个类型是可以用
//    // 用来模板实参，或者再定义对象
//
//	vector<decltype(ret)> v;
//	v.push_back(1);
//	v.push_back(1.1);
//	v.push_back(2.0);
//	//虽然它的元素类型是 double，但你可以将 int 类型的数值插入其中，编译器会处理类型转换。
//	// 实际上存的是1.0
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 但在打印中编译器会优化，比如push 2.0，打印的时候就会舍去后面的0，打印2
//	return 0;
//}


//int main()
//{
//	//数组容器，对标c语言的原生数组，与之不同的是对于越界有了更严格的检查，但不如vector
//	array<int, 10> a1;
//	cout << sizeof(a1) << endl;
//	//a1[10];
//	 
//	// 左值能否给右值取别名？
//	// 直接是不行的
//	// 权限放大, 加上const即可
//	const int& p1 = 10;
//
//	// 右值引用
//	int&& pp1 = 10;
//	// 右值引用能否给左值取别名？（不能，但优质引用可以用move，将其强转为右值，在取别名
//	int i = 5;
//	// int&& rr2 = i;  // 不行
//	int&& rr2 = move(i);
//	return 0;
//}


void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }
template<class T>
void PerfectForward(T&& t)
{
	// 期望保持实参的属性呢！
    // 完美转发
	Fun(forward<T>(t));
}
int main()
{

	return 0;
}