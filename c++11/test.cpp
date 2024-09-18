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
//	int arr2[5] = { 0 };//ȫ����ʼ��Ϊ0
//	//������ĳ�ʼ����
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

// һ�ж��������б��ʼ��
// ���ҿ���ʡ�Ե�=

// c++11�У�����������ʼ���б�

//int main()
//{
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };//ȫ����ʼ��Ϊ0
//	Point p{ 1, 2 };
//
//	Date d1(2023, 11, 25);
//	// ����ת��  ����+��������-���Ż�ֱ�ӹ���
//	Date d2 = { 2023,11,25 };
//	Date d2{ 2023,11,25 };
//
//	const Date& d3 = { 2023,11,25 };
//
//	Date* p1 = new Date[3]{ d1,d2,d3 };
//	Date* p2 = new Date[3]{ {2023,11,23},{2023,12,23},{2023,11,22} };
//	return 0;
//}


// ʹ��initializer_list ���г�ʼ������

//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5,6 };
//	// ʹ�� vector<int> v2 = {1, 2, 3, 4, 5, 6};
//	// ���г�ʼ��ʱ��ʵ������ʹ����һ���б��ʼ��initialization_list 
//	// ����һ����ʱ������,���������������е�Ԫ�ء�
//
//	//ͬ������list��
//	list<int> l1 = { 1,2,3,4,5,6 };
//
//	// �������������ת��  ����+��������-���Ż�ֱ�ӹ���
//	// ����Ӧ���캯����������ƥ��
//	// { 2023,11,23 }����
//	// Date d2 = { 2023,11,23 };����Ϊ��������
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
//	pair <string, string> kv1{ "insert", "����" };
//	map<string, string> dict = { {"insert", "����"},{"get","��ȡ"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	return 0;
//}


// ��ȡ���͵�����

//int main()
//{
//	int i = 1;
//	double d = 2.2;
//	// �������ַ�����ʽ��ȡ��
//	cout << typeid(i).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	// typeid ��һ������������ڻ�ȡ���ʽ i ��������Ϣ��
//	// typeid(i)����һ�� std::type_info ���󣬸ö�������� i ��������Ϣ��
//	// name() ��������һ�� C �����ַ�������ʾ i ���������ơ�
//	// ������Ƶľ����ʽ�����ڱ�����������������ɶ�����������Ҳ������һЩ�ڲ���ʾ��
//
//	// typeid(i).name() j;// �����ԣ���Ϊ��������Ϊ�ַ�����ʽ
//	auto j = i;
//
//	auto ret = i * d;
//
//	decltype(ret) x;
//	cout << typeid(x).name() << endl; // double
//	// ��ret������ȥʵ����vector
//	// decltype�����Ƶ���������͡���������ǿ�����
//    // ����ģ��ʵ�Σ������ٶ������
//
//	vector<decltype(ret)> v;
//	v.push_back(1);
//	v.push_back(1.1);
//	v.push_back(2.0);
//	//��Ȼ����Ԫ�������� double��������Խ� int ���͵���ֵ�������У��������ᴦ������ת����
//	// ʵ���ϴ����1.0
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// ���ڴ�ӡ�б��������Ż�������push 2.0����ӡ��ʱ��ͻ���ȥ�����0����ӡ2
//	return 0;
//}


//int main()
//{
//	//�����������Ա�c���Ե�ԭ�����飬��֮��ͬ���Ƕ���Խ�����˸��ϸ�ļ�飬������vector
//	array<int, 10> a1;
//	cout << sizeof(a1) << endl;
//	//a1[10];
//	 
//	// ��ֵ�ܷ����ֵȡ������
//	// ֱ���ǲ��е�
//	// Ȩ�޷Ŵ�, ����const����
//	const int& p1 = 10;
//
//	// ��ֵ����
//	int&& pp1 = 10;
//	// ��ֵ�����ܷ����ֵȡ�����������ܣ����������ÿ�����move������ǿתΪ��ֵ����ȡ����
//	int i = 5;
//	// int&& rr2 = i;  // ����
//	int&& rr2 = move(i);
//	return 0;
//}


//����ģ�壺��������

//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//template<class T>
//void PerfectForward(T&& t)
//{
//	// ��������ʵ�ε������أ�
//    // ����ת��
//	Fun(forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10);// ��ֵ
//
//	int a = 11;
//	PerfectForward(a);//��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);//��ֵ const
//	PerfectForward(std::move(b)); //��ֵ const
//	return 0;
//}


// �ɱ����

// Args��һ��ģ���������args��һ�������ββ�����
//template<class ...Args>
//void showList(Args...args)
//{
//	cout << sizeof...(args) << endl;
//	//ע�ⲻ��sizeof(args) 
//	 
//	// ��֧����ô��
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


////����ʱ�ĵݹ�����
//void _showList()//��ȫ����ӡ��������  �޲�
//{
//	cout << endl;
//}
//template<class T,class...Args>
//void _showList(const T& val, Args...args)
//{
//	cout << val << " ";
//	_showList(args...);//���ƶ���һ��val������
//	//��һ��ģ�����һ�ν�����ȡ����ֵ
//}
//template<class...Args>
//void _showList(Args...args)//�������
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
//	// ��ͨ������ PrintArg ����ʼ��һ������ arr��
//	// ������ĳ�ʼ��ǿ�ƽ����������е�ÿ���������Ӷ���ӡ�����д��ݸ� ShowList �Ĳ�����
//
//	// ���ǣ�arr��û�н��г�ʼ����������ҪĿ����Ϊ��ǿ��չ�����������Ա���� PrintArg ����
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


//�º���

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


// lambda ���ʽ��д��

struct Goods
{
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����
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
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	// �������Ϳ��Դ����ٴδ�����д�º���
//	// ����
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	// ����
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//
//	// ͨ������ֵ��bool���Բ�д����ϸ�ڿ����Ƶ�������                 bool
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
//	// ������������
//	// ʹ�� typeid ����ȡ lambda ���ʽ������ʱ��
//	// ȷʵ���Եõ�һ���������ƣ����������ͨ���Ǳ��������ɵ��ڲ����ƣ�����������ͨ�������ġ��������ơ���
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
//	// �ı���ֵ
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
//	// ��׽�������ڵı���
//	// �����Ǳ�������Ķ���
//	//   ����һ��Ҫ��   mutable
//	//        �ڴ˴�����Ҫ��׽�Ķ���
//	//   ��ֵ��׽
//	auto f2 = [a,b]()mutable {
//		cout << &a << ":" << &b << endl;
//		int tmp = a;//ϣ���� lambda �ڲ��޸���������ĸ������������mutable
//		a = b;// ��ô����Ͳ�ͨ��
//		b = tmp;
//		};
//	f2();//��ʱ��Ͳ���Ҫ���д�����
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
		// �Ჶ׽�������������б�������this
		// ����ĸ��������������

		// �ڲ����������lambda
		auto f1 = [=]() {
			cout << a1 << endl;
			cout << a2 << endl;
		};

		f1();
	}
private:
	int a1 = 1;//��������
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