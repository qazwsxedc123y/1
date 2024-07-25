#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
////基类
//class Person
//{
//public:
//	//构造函数
//	Person(const string& name = "张三")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person& k)
//		:_name(k._name)
//	{
//		cout << "Person(const Person& k)" << endl;
//	}
//	//赋值运算符重载函数
//	Person& operator=(const Person& k)
//	{
//		cout << "Person& operator=(const Person& k)" << endl;
//		if (this != &k)
//		{
//			_name = k._name;
//		}
//		return *this;
//	}
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //姓名
//};
////子类
//class Student : public Person
//{
//public: 
//	//构造函数
//	Student(const string& name, int age)
//		:Person(name)//调用初始化基类的构造函数去初始化基类那一部分的成员
//		,_age(age)//初始化派生类的成员
//	{
//		cout << "Student()" << endl;
//	}
//	//拷贝构造函数
//	Student(const Student& s)
//		:Person(s)////调用初始化基类的拷贝函数去拷贝基类那一部分的成员
//		//同样传s也涉及到了切割的基本原则
//		,_age(s._age)//拷贝派生类的成员
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//赋值运算符重载函数
//	Student& operator=(const Student& k)
//	{
//		cout << "Student& operator=(const Student& k)" << endl;
//		if (this != &k)
//		{
//			Person::operator=(k); //调用基类的operator=完成基类成员的赋值
//			_age = k._age; //完成派生类成员的赋值
//		}
//		return *this;
//	}
//	//析构函数
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//~Person();会自动调用先调用派生类的，后自动调用基类
//		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
//	}
//protected:
//	int _age;
//};

class Tire
{
protected:
	string _brand; //品牌
	size_t _size; //尺寸
};
class Car
{
protected:
	string _colour; //颜色
	string _num; //车牌号
	Tire _t; //轮胎
};


////父类
//class Person
//{
//protected:
//	string _name = "张三";
//};
//
////子类
//struct student : public Person//默认为public继承
//{
//protected:
//	int _id;
//};

//int main()
//{
//	int a = 5;
//	int& b = a;
//	double d = a;
//	return 0;
//}