#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
////����
//class Person
//{
//public:
//	//���캯��
//	Person(const string& name = "����")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//�������캯��
//	Person(const Person& k)
//		:_name(k._name)
//	{
//		cout << "Person(const Person& k)" << endl;
//	}
//	//��ֵ��������غ���
//	Person& operator=(const Person& k)
//	{
//		cout << "Person& operator=(const Person& k)" << endl;
//		if (this != &k)
//		{
//			_name = k._name;
//		}
//		return *this;
//	}
//	//��������
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //����
//};
////����
//class Student : public Person
//{
//public: 
//	//���캯��
//	Student(const string& name, int age)
//		:Person(name)//���ó�ʼ������Ĺ��캯��ȥ��ʼ��������һ���ֵĳ�Ա
//		,_age(age)//��ʼ��������ĳ�Ա
//	{
//		cout << "Student()" << endl;
//	}
//	//�������캯��
//	Student(const Student& s)
//		:Person(s)////���ó�ʼ������Ŀ�������ȥ����������һ���ֵĳ�Ա
//		//ͬ����sҲ�漰�����и�Ļ���ԭ��
//		,_age(s._age)//����������ĳ�Ա
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//��ֵ��������غ���
//	Student& operator=(const Student& k)
//	{
//		cout << "Student& operator=(const Student& k)" << endl;
//		if (this != &k)
//		{
//			Person::operator=(k); //���û����operator=��ɻ����Ա�ĸ�ֵ
//			_age = k._age; //����������Ա�ĸ�ֵ
//		}
//		return *this;
//	}
//	//��������
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//~Person();���Զ������ȵ���������ģ����Զ����û���
//		//������������������ڱ�������ɺ��Զ����û������������
//	}
//protected:
//	int _age;
//};

class Tire
{
protected:
	string _brand; //Ʒ��
	size_t _size; //�ߴ�
};
class Car
{
protected:
	string _colour; //��ɫ
	string _num; //���ƺ�
	Tire _t; //��̥
};


////����
//class Person
//{
//protected:
//	string _name = "����";
//};
//
////����
//struct student : public Person//Ĭ��Ϊpublic�̳�
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