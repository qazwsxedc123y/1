#define  _CRT_SECURE_NO_WARNINGS

#include"tss.h"
class Date
{
private:
    int _year;
    int _month;
    int _day;
};
//class Data
//{
//private:
//	int a;
//};
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
int main()
{
	//test::test_1();
    cout << -1 % 9 << endl;
	return 0;
}