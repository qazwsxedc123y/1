#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//����1
class Base1
{
public:
	virtual void func1() { cout << "Base1::func1()" << endl; }
	virtual void func2() { cout << "Base1::func2()" << endl; }
private:
	int _b1;
};
//����2
class Base2
{
public:
	virtual void func1() { cout << "Base2::func1()" << endl; }
	virtual void func2() { cout << "Base2::func2()" << endl; }
private:
	int _b2;
};
//��̳�������
class Derive : public Base1, public Base2
{
public:
	virtual void func1() { cout << "Derive::func1()" << endl; }
	virtual void func3() { cout << "Derive::func3()" << endl; }
private:
	int _d1;
};
typedef void(*VF)();//����ָ��,��ӡ����ַ��������
void printfVF(VF* a)
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		printf("[%d]:%p->", i, a[i]);//��ӡ����е��麯����ַ
		VF f = a[i];
		f();//ʹ���麯����ַ�����麯��
	}
	printf("\n");
}
int main()
{
	Base1 b1;
	printfVF((VF*)(*((int*)&b1)));
	Base2 b2;
	printfVF((VF*)(*((int*)&b2)));//��ӡ�������d������ַ��������
	Derive d;
	printfVF((VF*)(*((int*)&d)));//��ӡ�������d������ַ��������
	printfVF((VF*)*((int*)((char*) &d + sizeof(Base1))));
	return 0;
}



//int static_i = 0;
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("vfptr:%p\n", *((int*)p)); //000FDCAC
//	int i = 0;
//	printf("ջ�ϵ�ַ:%p\n", &i);       //005CFE24
//	printf("���ݶε�ַ:%p\n", &static_i);     //0010038C
//
//	int* k = new int;
//	printf("���ϵ�ַ:%p\n", k);       //00A6CA00
//	const char* cp = "hello world";
//	printf("����ε�ַ:%p\n", cp);    //000FDCB4
//	return 0;
//}