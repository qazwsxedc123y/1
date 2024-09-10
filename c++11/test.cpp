#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<array>
#include<functional>
#include<algorithm>
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


//函数模板：万能引用

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//template<class T>
//void PerfectForward(T&& t)
//{
//	// 期望保持实参的属性呢！
//    // 完美转发
//	Fun(forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10);// 右值
//
//	int a = 11;
//	PerfectForward(a);//左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);//左值 const
//	PerfectForward(std::move(b)); //右值 const
//	return 0;
//}


// 可变参数

// Args是一个模板参数包，args是一个函数形参参数包
//template<class ...Args>
//void showList(Args...args)
//{
//	cout << sizeof...(args) << endl;
//	//注意不是sizeof(args) 
//	 
//	// 不支持这么玩
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	showList(1);               // 1
//	showList(1, 2);            // 2
//	showList(1, 2, 'x');       // 3
//	showList(1, 2, 'x', 2.2);  // 4
//	return 0;
//}


////编译时的递归推演
//void _showList()//当全部打印完才走这个  无参
//{
//	cout << endl;
//}
//template<class T,class...Args>
//void _showList(const T& val, Args...args)
//{
//	cout << val << " ";
//	_showList(args...);//会推断下一个val的属性
//	//第一个模板参数一次解析获取参数值
//}
//template<class...Args>
//void _showList(Args...args)//先走这个
//{
//	_showList(args...);
//}
//int main()
//{
//	_showList(1, 2, 'x', 2.2);
//	return 0;
//}


//template<class T>
//int printArgs(T&& t)
//{
//	cout << t << " ";
//	return 0;
//}
//template<class...Args>
//void showList(Args...args)
//{
//	int arr[] = { printArgs(args)... };
//	// 它通过调用 PrintArg 来初始化一个数组 arr，
//	// 该数组的初始化强制解析参数包中的每个参数，从而打印出所有传递给 ShowList 的参数。
//
//	// 但是，arr并没有进行初始化，它的主要目的是为了强制展开参数包，以便调用 PrintArg 函数
//	cout << endl;
//}
//int main()
//{
//	showList(1, 'A');
//	return 0;
//}


//int main()
//{
//	list<string> lt;
//	string s1("1111");
//	lt.push_back(s1);
//	lt.push_back(move(s1));
//
//	string s2("1111");
//	lt.emplace_back(s2);
//	lt.emplace_back(move(s2));
//
//	cout << endl;
//	lt.push_back("xxxx");
//	lt.emplace_back("xxxx");
//
//	return 0;
//}


//仿函数

//template<class T>
//class Swap
//{
//public:
//	void operator()(T& x, T& y)
//	{
//		T tmp = x;
//		x = y;
//		y = tmp;
//	}
//};
//int main()
//{
//	Swap<int> s;
//	int a = 5, b = 10;
//	s(a, b);
//	cout << a << "  " << b;
//	return 0;
//}


// lambda 表达式书写表

struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	//...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};
struct ComparePriceLess
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price < g2._price;
	}
};
struct ComparePriceGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	// 就这样就可以代替再次创建书写仿函数
//	// 降序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	// 升序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//
//	// 通常返回值（bool可以不写，其细节可以推到出来）                 bool
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {return g1._price < g2._price; });
//
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate < g2._evaluate; });
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}


//int main()
//{
//	// 匿名函数对象
//	// 使用 typeid 来获取 lambda 表达式的类型时，
//	// 确实可以得到一个类型名称，但这个名称通常是编译器生成的内部名称，而不是我们通常所理解的“函数名称”。
//	auto f1 = [](int x)->int {cout << x << endl; return 0; };
//	f1(1); 
//	cout << typeid(f1).name() << endl;
//	// class `int __cdecl main(void)'::`2'::<lambda_1>
//
//	auto f2 = [](int x)
//		{
//			cout << x << endl;
//			return 0;
//		};
//	f2(2);
//	cout << typeid(f2).name() << endl;
//	// class `int __cdecl main(void)'::`2'::<lambda_2>
//
//	ComparePriceGreater f3;
//	cout << typeid(f3).name() << endl;
//	// struct ComparePriceGreater
//	return 0;
//}


//int main()
//{
//	// 改变其值
//	int a = 5, b = 10;
//	//cout << &a << ":" << &b << endl;
//	auto f1 = [](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//	f1(a, b);
//	cout << a << "  " << b << endl;
//	cout << &a << ":" << &b << endl;
//
//	// 捕捉作用域内的变量
//	// 必须是本作用域的对象
//	//   但是一定要加   mutable
//	//        在此处传需要捕捉的对象
//	//   传值捕捉
//	auto f2 = [a,b]()mutable {
//		cout << &a << ":" << &b << endl;
//		int tmp = a;//希望在 lambda 内部修改这个变量的副本，如果不加mutable
//		a = b;// 那么编译就不通过
//		b = tmp;
//		};
//	f2();//这时候就不需要进行传参了
//	cout << a << " " << b << endl;
//
//	auto f3 = [&a, &b]()mutable {
//		cout << &a << ":" << &b << endl;
//		int tmp = a;
//		a = b;
//		b = tmp;
//		};
//	f3();
//	cout << a << " " << b << endl;
//	return 0;
//}


class AA
{
public:
	void func()
	{
		/*auto f1 = [this]() {
			cout << a1 << endl;
			cout << a2 << endl;
		};*/
		// 会捕捉父作用域内所有变量包含this
		// 这里的父作用域就是类中

		// 内部作用域就是lambda
		auto f1 = [=]() {
			cout << a1 << endl;
			cout << a2 << endl;
		};

		f1();
	}
private:
	int a1 = 1;//父作用域
	int a2 = 1;
};
int main()
{
	int x = 0, y = 1, z = 2;
	auto f1 = [=, &z]() {
		z++;

		cout << x << endl;
		cout << y << endl;
		cout << z << endl;
	};

	f1();
	AA a;
	a.func();
	return 0;
}