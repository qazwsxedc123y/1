#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;


//// �����ࣨҲ�нӿ��ࣩ
//// �д��麯������г����� �����಻����ʵ����
//class Person
//{
//public:
//    // �Ǵ��麯��
//    virtual void BuyTicket() = 0;
//};
//class Student : public Person
//{
//    //û����д���麯��
//};
//class Soldier : public Person
//{
//public:
//    //��д�˴��麯��
//    virtual void BuyTicket()
//    {
//        cout << "��Ʊ-����" << endl;
//    }
//};
//int mian()
//{
//	Person p;//�޷�ʵ����������
//    Student s;//�޷�ʵ����������
//    Soldier s1;
//	return 0;
//}

//double area() ����
//double area() const ������

// ����Shape��ͨ���������������� Rectangle,Circle
// ������
class Shape
{
public:
    // ���麯��
    virtual double area()const = 0;
};

class Rectangle : public Shape // ������
{
public:
    Rectangle(double _w, double _l)
        : w(_w), l(_l) {}

    virtual double area()
    {
        return w * l; // ���㳤�������
    }

private:
    double w; // ���
    double l; // ����
};

class Circle : public Shape // Բ��
{
public:
    Circle(double _r)
        : r(_r) {}

    virtual double area()
    {
        return 3.14 * r * r; // ����Բ�����
    }

private:
    double r; // �뾶
};

int main() {
    // ����������ʾ��̬
    Shape* shape1 = new Rectangle(5.0, 3.0);  // ������
    Shape* shape2 = new Circle(4.0);           // Բ��

    // ʹ�û���ָ������������area����
    cout << "Rectangle area: " << shape1->area() << endl;
    cout << "Circle area: " << shape2->area() << endl;

    return 0;
}

// ��д�Ĳ���
// ���˵��������������ͬ�����������һ���ĸú���Ϊ�麯��
// ��ô������ĸú����ͻ������д�������Ǹ��ǣ�
//class Person
//{
//public:
//    virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person
//{
//public:
//    virtual void BuyTicket() override
//    { cout << "��Ʊ-���" << endl; } 
//};
//// ��д����������  ��д������
//// Person   Student 
//int main()
//{
//    Person p;
//    Student s;
//    p.BuyTicket();
//    s.BuyTicket();
//    return 0;
//}