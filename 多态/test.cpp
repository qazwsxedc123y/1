#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Person
{
public :
	virtual void BuyTicket()
	{
		cout << "Person��Ʊ-ȫ��" << endl;
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
		cout << "Student��Ʊ-���" << endl;
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

// ��̬������:
// 1���麯����д
// 2�������ָ���������ȥ�����麯��
// 
// �麯����д
// ���Ӽ̳й�ϵ�������麯������ͬ(������/����/����)
// virtualֻ�����γ�Ա
// ��ͬ(������/����/����)�����⣺Э��->����ֵ���Բ�ͬ�����Ǳ����Ǹ������ϵ��ָ���������
// ��������д���麯���������Բ���virtual(���鶼����)
 
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
