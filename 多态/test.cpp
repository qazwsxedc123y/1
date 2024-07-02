#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//class Person
//{
//public :
//	virtual void BuyTicket()
//	{
//		cout << "Person买票-全价" << endl;
//	}
//	virtual ~Person()
//	//~Person()
//	{
//		cout << "~Person" << endl;
//	}
//};
//class Student:public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "Student买票-半价" << endl;
//	}
//	virtual ~Student()
//	//~Student()
//	{
//		cout << "~Student" << endl;
//	}
//};
//void func(Person& p)
//{
//	p.BuyTicket();
//}

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

//int main()
//{
//	Person* p = new Person();
//	delete p;
//	p = new Student();
//	delete p;
//	return 0;
//}


//class A
//{
//	virtual void func()
//	{
//
//	}
//	virtual void funca()
//	{
//
//	}
//	virtual void funcaa()
//	{
//
//	}
//private:
//	int a;
//};
//int main()
//{
//	//a0 ce d2 77 
//	//f6 7f 00 00
//	//5a 15 d2 77
//	A a;
//	cout << sizeof(A) << endl;
//	int b;
//	int* aa = &b;
//	cout << sizeof(aa) << endl;
//	return 0;
//}


////难点
//
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	//所以这里的test中的this指针是A*
//	virtual void test() { func(); }//这里在调用func，但func进行了重写，所以这里会
//	//调用重写后的func（多态调用，符合用父类接收子类去调用）
//	//多态调用虚函数重写的话，虚函数重写会继承了父类的接口声明（函数的声明）
//	//所以会使val走父类的声明，将val赋值为1；
//	//然后在走重写后的函数实现，打印   B->1   
//	
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//	//virtual在一定条件下可以不加（特例）
//	//virtual void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//	void f()
//	{
//		cout << "sss" << endl;
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();//会打印  B->1   因为是多态调用
//	//这里调用的是test然后，且p是B类对象，会调用；派生出来的test，
//	// 但是test没有进行重写，所以test中的this指针还是指向A类
//	
//	p->func();//根据上面描述后，这个因为不构成多态调用，所以打印  B->0
//	//构成多态调用的条件：父类的指针或引用去调用子类的虚函数//一定是虚函数
//	 
//	 
//	//A* c = new A;
//	//c = p;
//	//c->f();//因为f不是虚函数，所以不符合多态调用，不可以编译
//
//	return 0;
//}


////虚函数重写，其实是先拷贝父类的函数，然后对虚函数进行重写
////重定义（隐藏）只要求函数名相同(但要符合重载的要求，其实两者实际上就是重载）；
//
//
//// 重定义下：
//// 在这种情况下，如果通过父类指针或引用调用函数，会调用父类的函数而不是子类。
//// 重定义（或称为隐藏）发生的原因是因为函数名相同但参数列表不同，导致编译器无法确定调用哪一个版本的函数。
//// 在这种情况下，根据 C++ 的规则，通过父类指针或引用调用函数时，会调用父类的函数而不是子类的函数。
//// 这是因为在 C++ 中，函数解析是在编译期静态确定的（静态绑定），而不是在运行期动态确定的（动态绑定）。
//// 当通过父类指针或引用调用函数时，编译器只会查找父类中匹配的函数，并且不会考虑子类中的同名函数。
//// 因此，即使通过父类指针或引用指向一个子类对象，也只能访问到父类的函数（如果子类中有同名函数）。
//// 如果想要实现动态调用子类的函数，可以使用虚函数和函数重写（override）的方式。
//// 当在父类中将函数声明为虚函数时，可以通过父类指针或引用调用该函数时动态决定调用子类的重写版本。
//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::买票-全价" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	// 重载
//	// 隐藏/重定义
//	// 虚函数重写
//	void BuyTicket(int x = 0) { cout << "Student::买票-半价" << endl; }
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}


// ////final 修饰类，不能被继承
// ////final 修饰虚函数，不能被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }//父类虚函数final修饰不可重写
//};


////class Car {
////public:
////	virtual void Drive() {}
////};
////
////class Benz :public Car {
////public:
////	// override修饰派生类的虚函数
////	// 检查是否完成重写
////	virtual void Drive() override { cout << "Benz-舒适" << endl; }
////};


//纯虚函数

//抽象类：包含纯虚函数的类叫做抽象类（也叫接口类）
//抽象类不能实例化出对象。
//派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象
class car
{
public:
	virtual void Drive() = 0;//就是长这个样子，写死的
};// 纯虚函数
////	// 1、间接强制去派生类去重写
////	// 2、抽象类-不能实例化出对象

//这里的Baz也是抽象类

class Baz :public car
{
	//所以如果子类不进行重写，这里其实什么也没有
};

class Bax :public car
{
	virtual void Drive()
	{
		cout << "class Bax :public car" << endl;
	}
};



// 如果子类不重写虚函数，父类和子类对象的虚表是否一样？
// 因为重写其实是先进行拷贝，所以是一样的