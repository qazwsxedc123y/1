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


void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
template<class T>
void PerfectForward(T&& t)
{
	// ��������ʵ�ε������أ�
    // ����ת��
	Fun(forward<T>(t));
}
int main()
{

	return 0;
}