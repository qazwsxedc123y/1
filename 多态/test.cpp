#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Person
{
public :
	virtual void BuyTicket()
	{
		cout << "Person买票-全价" << endl;
	}
	virtual ~Person()
	//~Person()
	{
		cout << "~Person" << endl;
	}
};
class Student:public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "Student买票-半价" << endl;
	}
	virtual ~Student()
	//~Student()
	{
		cout << "~Student" << endl;
	}
};
void func(Person& p)
{
	p.BuyTicket();
}

// 多态的条件:
// 1、虚函数重写
// 2、父类的指针或者引用去调用虚函数
// 
// 虚函数重写
// 父子继承关系的两个虚函数，三同(函数名/参数/返回)
// virtual只能修饰成员
// 三同(函数名/参数/返回)的例外：协变->返回值可以不同，但是必须是父子类关系的指针或者引用
// 派生类重写的虚函数函数可以不加virtual(建议都加上)
 
//int main()
//{
//	Person ps;
//	Student st;
//	func(ps);
//	func(st);
//	return 0;
//}

int main()
{
	Person* p = new Person();
	delete p;
	p = new Student();
	delete p;
	return 0;
}
