#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//class Person
//{
//public :
//	virtual void BuyTicket()
//	{
//		cout << "Person��Ʊ-ȫ��" << endl;
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
//		cout << "Student��Ʊ-���" << endl;
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


////�ѵ�
//
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	//���������test�е�thisָ����A*
//	virtual void test() { func(); }//�����ڵ���func����func��������д�����������
//	//������д���func����̬���ã������ø����������ȥ���ã�
//	//��̬�����麯����д�Ļ����麯����д��̳��˸���Ľӿ�������������������
//	//���Ի�ʹval�߸������������val��ֵΪ1��
//	//Ȼ��������д��ĺ���ʵ�֣���ӡ   B->1   
//	
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//	//virtual��һ�������¿��Բ��ӣ�������
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
//	p->test();//���ӡ  B->1   ��Ϊ�Ƕ�̬����
//	//������õ���testȻ����p��B����󣬻���ã�����������test��
//	// ����testû�н�����д������test�е�thisָ�뻹��ָ��A��
//	
//	p->func();//�������������������Ϊ�����ɶ�̬���ã����Դ�ӡ  B->0
//	//���ɶ�̬���õ������������ָ�������ȥ����������麯��//һ�����麯��
//	 
//	 
//	//A* c = new A;
//	//c = p;
//	//c->f();//��Ϊf�����麯�������Բ����϶�̬���ã������Ա���
//
//	return 0;
//}


////�麯����д����ʵ���ȿ�������ĺ�����Ȼ����麯��������д
////�ض��壨���أ�ֻҪ��������ͬ(��Ҫ�������ص�Ҫ����ʵ����ʵ���Ͼ������أ���
//
//
//// �ض����£�
//// ����������£����ͨ������ָ������õ��ú���������ø���ĺ������������ࡣ
//// �ض��壨���Ϊ���أ�������ԭ������Ϊ��������ͬ�������б�ͬ�����±������޷�ȷ��������һ���汾�ĺ�����
//// ����������£����� C++ �Ĺ���ͨ������ָ������õ��ú���ʱ������ø���ĺ�������������ĺ�����
//// ������Ϊ�� C++ �У������������ڱ����ھ�̬ȷ���ģ���̬�󶨣����������������ڶ�̬ȷ���ģ���̬�󶨣���
//// ��ͨ������ָ������õ��ú���ʱ��������ֻ����Ҹ�����ƥ��ĺ��������Ҳ��ῼ�������е�ͬ��������
//// ��ˣ���ʹͨ������ָ�������ָ��һ���������Ҳֻ�ܷ��ʵ�����ĺ����������������ͬ����������
//// �����Ҫʵ�ֶ�̬��������ĺ���������ʹ���麯���ͺ�����д��override���ķ�ʽ��
//// ���ڸ����н���������Ϊ�麯��ʱ������ͨ������ָ������õ��øú���ʱ��̬���������������д�汾��
//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::��Ʊ-ȫ��" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	// ����
//	// ����/�ض���
//	// �麯����д
//	void BuyTicket(int x = 0) { cout << "Student::��Ʊ-���" << endl; }
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


// ////final �����࣬���ܱ��̳�
// ////final �����麯�������ܱ���д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }//�����麯��final���β�����д
//};


////class Car {
////public:
////	virtual void Drive() {}
////};
////
////class Benz :public Car {
////public:
////	// override������������麯��
////	// ����Ƿ������д
////	virtual void Drive() override { cout << "Benz-����" << endl; }
////};


//���麯��

//�����ࣺ�������麯��������������ࣨҲ�нӿ��ࣩ
//�����಻��ʵ����������
//������̳к�Ҳ����ʵ����������ֻ����д���麯�������������ʵ����������
class car
{
public:
	virtual void Drive() = 0;//���ǳ�������ӣ�д����
};// ���麯��
////	// 1�����ǿ��ȥ������ȥ��д
////	// 2��������-����ʵ����������

//�����BazҲ�ǳ�����

class Baz :public car
{
	//����������಻������д��������ʵʲôҲû��
};

class Bax :public car
{
	virtual void Drive()
	{
		cout << "class Bax :public car" << endl;
	}
};



// ������಻��д�麯���������������������Ƿ�һ����
// ��Ϊ��д��ʵ���Ƚ��п�����������һ����



//�������������

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//
//void func()
//{
//	cout << "void func()" << endl;
//}
//int main()
//{
//	Base b1;
//
//	static int a = 0;//��̬��
//	int b = 0;//ջ��
//	int* p1 = new int;//����
//	const char* p = "hello world";//����Σ���������
//	printf("��̬��:%p\n", &a);
//	printf("ջ��:%p\n", &b);
//	printf("����:%p\n", p1);
//	printf("�����:%p\n", p);
//	printf("���:%p\n", *((int*) & b1));
//	printf("�麯���ĵ�ַ:%p\n", &Base::func1);
//	printf("��ͨ�����ĵ�ַ:%p\n", func);
//	return 0;
//}

// �麯���ĵ�ַһ���ᱻ�Ž�����麯�������ǵ�

//��ӡ���

typedef void(*VF)();//����ָ��

////class Base {
////public:
////	virtual void func1() { cout << "Base::func1" << endl; }
////	virtual void func2() { cout << "Base::func2" << endl; }
////private:
////	int a;
////};
////
////class Derive :public Base {
////public:
////	virtual void func1() { cout << "Derive::func1" << endl; }
////	virtual void func3() { cout << "Derive::func3" << endl; }
////	virtual void func4() { cout << "Derive::func4" << endl; }
////	void func5() { cout << "Derive::func5" << endl; }
////private:
////	int b;
////};
////
////class X :public Derive {
////public:
////	virtual void func3() { cout << "X::func3" << endl; }
////};
void printfVF(VF* a)
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		printf("[%d]:%p->", i, a[i]);
		VF f = a[i];
		f();
	}
	printf("\n");
}
////int main()
////{
////	Base b;
////	Derive d;
////	X x;
////	printfVF((VF*)(*((long long*)&b)));
////	printfVF((VF*)(*((long long*)&d)));
////	printfVF((VF*)(*((long long*)&x)));
////	return 0;
////}



//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() 
//	{ 
//		cout << "Derive::func1" << endl;
//	}
//
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//int main()
//{
//	//Base2* ptr = &d;
//	//PrintVFT((VFUNC*)(*(int*)ptr));
//
//	Derive d;
//	printfVF((VF*)*((int*)&d));
//	printfVF((VF*)*((int*)((char*) &d+sizeof(Base1))));
//	//[0] :006C1235->Derive::func1//��һ��
//	//[1] : 006C14C4->Base1::func2
//	//[2] : 006C1226->Derive::func3
//
//	//[0] : 006C14C9->Derive::func1//����Ϊ������һ����ʹ�䣬�ڶ���Ҫ�޸�thisָ��ָ��Derive
//	//[1] : 006C14B5->Base2::func2
//	Base2* p1 = &d;
//	printfVF((VF*)(*(int*)p1));
//	return 0;
//}




class A
{
public:
	virtual void func1() 
	{ 
		cout << "A::func1" << endl;
	}
public:
	int _a;
};

//class B : public A
class B : virtual public A
{
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}

public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	virtual void func1()
	{
		cout << "C::func1" << endl;
	}
public:
	int _c;
};

class D : public B, public C
{
public:
	virtual void func1()
	{
		cout << "D::func1" << endl;
	}

	virtual void func2()
	{
		cout << "D::func2" << endl;
	}
public:
	int _d = 1;
};

int main()
{
	D d;//һ����2�����
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}