#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;
//����
//class Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "����";
//};
////����
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "����";
//};
//// ���ݵĶ�����
//int main()
//{
//	Student s;
//	s.Person::fun();//���ӡ��Person::_name
//	s.fun(); //���ӡ����
//	return 0;
//}



// �����

// ����
//class Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "����";
//};
//// ����
////    ����     virtual  �̳з�ʽ  ����
//class Student : virtual public Person
//{
//public:
//	void fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "����";
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
	d.funA();// ����ʾ����D::fun����ȷ
	return 0;
}