#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;
//父类
//class Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "李四";
//};
////子类
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "张三";
//};
//// 数据的二义性
//int main()
//{
//	Student s;
//	s.Person::fun();//会打印：Person::_name
//	s.fun(); //会打印张三
//	return 0;
//}



// 虚基类

// 父类
//class Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "李四";
//};
//// 子类
////    子类     virtual  继承方式  父类
//class Student : virtual public Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "张三";
//};
//int main()
//{
//	Student s;
//	return 0;
//}



class A 
{
public:
	void funA() 
	{
		cout << "Function fun() from A" << endl;
	}
};

class B : virtual  public A
{
public:
	void fun() 
	{
		cout << "Function fun() from B" << endl;
	}
};

class C : virtual  public A
{
public:
	void fun() 
	{
		cout << "Function fun() from C" << endl;
	}
};
class D :public B, public C
{
public:
};

int main()
{
	D d;
	d.funA();// 会显示报错D::fun不明确
	return 0;
}