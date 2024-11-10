#define  _CRT_SECURE_NO_WARNINGS

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
template <class T>
class Less // 大堆
{
public:
    bool operator()(const T& x, const T& y) { return x < y; }
};
template <class T, class Container = vector<T>, class Compare = Less<T>>
class priority {
public:
    priority() {}
    template <class InputIterator>
    priority(InputIterator first, InputIterator last) : _con(first, last) {
        for (int i = (_con.size() - 2) / 2; i >= 0; --i) {
            adjust_down(i);
        }
    }
    void adjust_down(size_t parent)
    {
        Compare com;
        size_t child = parent * 2 + 1;
        while (child < _con.size())
        {
            //if (child + 1 < _con.size()
                //&& _con[child] < _con[child + 1])
            if (child + 1 < _con.size()
                && _con[child] < _con[child + 1])
            {
                ++child;
            }
            if (com(_con[parent], _con[child]))
            {
                swap(_con[parent], _con[child]);
                parent = child;
                child = parent * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    void print()
    {
        int sz = _con.size();
        for (int i = 0; i < sz; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << _con[i];
        }
        cout << endl;
    }
private:
    Container _con;
};
void test()
{
    int arr[50];
    int i = 0;
    int num;
    while (cin >> num)
    {
        arr[i++] = num;
        if (cin.get() == '\n')
        {
            break;
        }
    }
    priority <int, vector<int>, Less<int>> a(arr, arr + i);
    a.print();
}
int main()
{
    test();
    return 0;
}
//class Box
//{
//public:
//	Box(int _l,int _w,int _h)
//		:l(_l)
//		,w(_w)
//		,h(_h)
//	{}
//	void display_v()
//	{
//		int v = l * w * h;
//		cout << v << endl;
//	}
//private:
//	int l;
//	int w;
//	int h;
//};
//int main()
//{
//	int l, w, h;
//	cin >> l >> w >> h;
//	Box b1(l, w, h);
//	b1.display_v();
//	return 0;
//}



//class Point 
//{
//public:
//    Point()
//        :x(0)
//        ,y(0)
//    {}
//    Point(int _x,int _y)
//        :x(_x)
//        ,y(_y)
//    {}
//    Point move(int _x, int _y)
//    {
//        x += _x;
//        y += _y;
//        return *this;
//    }
//    void show()
//    {
//        printf("The point value is :(%d,%d)", x, y);
//    }
//private:
//    int x;
//    int y;
//};
//
//int main()
//{
//    int x, y;
//    Point p1, p2;  //定义点对象p1,p2,并将其坐标初始化为（0,0）
//    cin >> x >> y;
//    p1 = Point(x, y);  //将p1点坐标更新为（x,y)
//    int xDis, yDis;
//    cin >> xDis >> yDis;
//    p2 = p1.move(xDis, yDis);//将p1点平移(xDis, yDis),并将p2点坐标更新为平移后的新坐标
//    p2.show();  //输出平移后的新坐标值
//}




//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//class Complex
//{
//public:
//	friend Complex operator+(const Complex& a, const Complex& b);
//	friend Complex operator-(const Complex& a, const Complex& b);
//	Complex(int _real,int _imag)
//		:real(_real)
//		,imag(_imag)
//	{}
//	void print() 
//	{
//		cout << real << "+" << imag << "i" << endl;
//	}
//private:
//	int real;   // 实部
//	int imag;   // 虚部
//};
//Complex operator+(const Complex& a, const Complex& b)
//{
//	return Complex(a.real + b.real, a.imag + b.imag);
//}
//Complex operator-(const Complex& a, const Complex& b)
//{
//	return Complex(a.real - b.real, a.imag - b.imag);
//}
//
//int main()
//{
//	int real1, imag1, real2, imag2;
//	cin >> real1 >> imag1;
//	cin >> real2 >> imag2;
//	Complex c1(real1, imag1);
//	Complex c2(real2, imag2);
//	Complex sum = c1 + c2;
//	Complex dif = c1 - c2;
//	sum.print();
//	dif.print();
//	return 0;
//}


//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//
//
//#include<iostream>
//using namespace std;
//
//template<class T>
//T Add(const T& x, const T& y);
//int main()
//{
//	cout << Add(2, 3) << endl;
//	return 0;
//}




//class Solution {
//public:
//    string minWindow(string s, string t) {
//        int n = s.size();
//        int hash1[128] = { 0 };
//        int kinds = 0;
//        for (auto& e : t)
//        {
//            if (hash1[e] == 0)
//            {
//                kinds++;
//            }
//            hash1[e]++;
//        }
//        int mi = INT_MAX;
//        int hash2[128] = { 0 };
//        int begin = 0;
//        for (int left = 0, right = 0, count = 0; right < n; right++)
//        {
//            char in = s[right];
//            if (++hash2[in] == hash1[in]) count++;
//            while (count == kinds)
//            {
//                if (right - left + 1 < mi)
//                {
//                    mi = right - left + 1;
//                    begin = left;
//                }
//                char ou = s[left];
//                if (hash2[ou] == hash1[ou]) count--;
//                hash2[ou]--;
//                left++;
//            }
//        }
//        if (begin == -1) return "";
//        else return s.substr(begin, mi);
//    }
//};
//
//int main()
//{
//    Solution s;
//    string s1{ "a" };
//    string s2{ "aa" };
//    s.minWindow(s1, s2);
//    return 0;
//}