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