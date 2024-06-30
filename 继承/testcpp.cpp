#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
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

//int main()
//{
//	student s("张三", 19);
//	student s1(s);
//	student s2("李四", 20);
//	s2 = s;
//	const int q = 5;
//	int i = 'a';
//	cout << i << endl;
//	return 0;
//}

// //C++11 新增final，修饰父类，直接不能被继承
//class A  final
//{
//public:
//	A()
//	{}
//
//private:
//	int _a;
//	int _b;
//};
//
//class B : public A
//{
//public:
//};

//// 组合
//class C
//{
//public:
//	void func()
//	{}
//protected:
//	int _c;
//};
//
//class D
//{
//public:
//	void f()
//	{
//		_c.func();
//		//_c._a++;
//	}
//protected:
//	C _c;
//	int _d;
//};
int main()
{
	return 0;
}

//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//
////class B :virtual public A
//class B : public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C : public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D : public C, public B
//{
//public:
//	//D(const char* s1, const char* s2, const char* s3, const char* s4) 
//	//	:B(s1, s2)
//	//	, C(s1, s3)
//	//	, A(s1)
//	//{
//	//	cout << s4 << endl;
//	//}
//
//	D(const char* s1, const char* s2, const char* s3, const char* s4)
//		:B(s1, s2)
//		, C(s1, s3)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}