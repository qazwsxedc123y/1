#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//基类1
class Base1
{
public:
	virtual void func1() { cout << "Base1::func1()" << endl; }
	virtual void func2() { cout << "Base1::func2()" << endl; }
private:
	int _b1;
};
//基类2
class Base2
{
public:
	virtual void func1() { cout << "Base2::func1()" << endl; }
	virtual void func2() { cout << "Base2::func2()" << endl; }
private:
	int _b2;
};
//多继承派生类
class Derive : public Base1, public Base2
{
public:
	virtual void func1() { cout << "Derive::func1()" << endl; }
	virtual void func3() { cout << "Derive::func3()" << endl; }
private:
	int _d1;
};
typedef void(*VF)();//函数指针,打印虚表地址及其内容
void printfVF(VF* a)
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		printf("[%d]:%p->", i, a[i]);//打印虚表当中的虚函数地址
		VF f = a[i];
		f();//使用虚函数地址调用虚函数
	}
	printf("\n");
}
int main()
{
	Base1 b1;
	printfVF((VF*)(*((int*)&b1)));
	Base2 b2;
	printfVF((VF*)(*((int*)&b2)));//打印基类对象d的虚表地址及其内容
	Derive d;
	printfVF((VF*)(*((int*)&d)));//打印基类对象d的虚表地址及其内容
	printfVF((VF*)*((int*)((char*) &d + sizeof(Base1))));
	return 0;
}



//int static_i = 0;
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("vfptr:%p\n", *((int*)p)); //000FDCAC
//	int i = 0;
//	printf("栈上地址:%p\n", &i);       //005CFE24
//	printf("数据段地址:%p\n", &static_i);     //0010038C
//
//	int* k = new int;
//	printf("堆上地址:%p\n", k);       //00A6CA00
//	const char* cp = "hello world";
//	printf("代码段地址:%p\n", cp);    //000FDCB4
//	return 0;
//}