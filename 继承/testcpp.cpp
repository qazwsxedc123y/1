#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person(const char* name)" << endl;
	}
	Person(const Person& s)
		:_name(s._name)
	{
		cout << "Person(const Person& s)" << endl;
	}
	Person& operator=(const Person& s)
	{
		if (&s != this)
		{
			_name = s._name;
		}
		cout << "Person& operator=(const Person& s)" << endl;
		return *this;
	}
	~Person()
	{
		_name.clear();
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};
class student : public Person
{
public:
	student(const char* name, int id)
		:Person(name)
		,_id(id)
	{
		cout << "Student(const char* name, int id)" << endl;
	}
	student(const student& s)
		:Person(s)
		,_id(s._id)
	{
		cout << "student(const student & s)" << endl;
	}
	student& operator=(const student& s)
	{
		if (&s != this)
		{
			Person::operator=(s);
			_id = s._id;
		}
		cout << "student& operator=(const student& s)" << endl;
		return *this;
	}
	~student()
	{
		_id = 0;
		//先析构子，后析构父（因为多态）
		//但编译器优化过后，是自动调用父类析构，省去了这一步骤
		cout << "~student()" << endl;
		//Person::~Person();
	}
protected:
	int _id;
};
int main()
{
	student s("张三",19);
	//student s1(s);
	student s2("李四", 20);
	s2 = s;

	return 0;
}