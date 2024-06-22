#define  _CRT_SECURE_NO_WARNINGS
//

//
//class Solution {
//public:
//    string toHex(int num) {
//        if (num == 0)
//        {
//            return "0";
//        }
//        string s;
//        for (int i = 7; i >= 0; i--)
//        {
//            int val = (num >> (i * 4)) & 0xf;
//            char digit;
//            if (s.size() != 0 || val > 0)
//            {
//                digit = val < 10 ? (char)'0' + val : (char)'a' + val - 10;
//                s.push_back(digit);
//            }
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    int val = (-1 >> (7 * 4)) & 0xf;
//    cout << ( - 1 >> (7 * 4)) << endl;
//    cout << val << endl;
//    memmove()
//}



//#include<iostream>
//#include<vector>
//#include <algorithm>
//using namespace std;
//
//class A
//{
//protected:
//	int _a;
//};
//
//class B : virtual public A
//{
//protected:
//	int _b;
//};
//
//class C : virtual public A
//{
//protected:
//	int _c;
//};
//
//class D :public B, public C
////class D 
//{
//protected:
//	int _d;
//};
//int main()
//{
//	cout << sizeof(D) << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};

//class B :virtual public A
class B : public A
{
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};

class C : public A
{
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};

class D : public C, public B
{
public:
	//D(const char* s1, const char* s2, const char* s3, const char* s4) 
	//	:B(s1, s2)
	//	, C(s1, s3)
	//	, A(s1)
	//{
	//	cout << s4 << endl;
	//}

	D(const char* s1, const char* s2, const char* s3, const char* s4)
		:B(s1, s2)
		, C(s1, s3)
	{
		cout << s4 << endl;
	}
};

int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}