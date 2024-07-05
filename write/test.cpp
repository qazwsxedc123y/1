#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<stack>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int aa = 0;
	printf("栈区的地址：%p\n", &aa);
	int* pl = new int;
	printf("堆区的地址：%p\n", pl);
	string a("abcddddddddddddddddddddddddd", 16);
	printf("a的地址:    %p\n", &a);
	printf("a[0]的地址: %p\n", &a[0]);
	a[1] = 'X';
	cout << a << endl;
	printf("a的地址:    %p\n", &a);
	printf("a[0]的地址: %p\n", &a[0]);
	string b("abc");
	printf("b的地址:    %p\n", &b);
	printf("b[0]的地址: %p\n", &b[0]);
	return 0;
}


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