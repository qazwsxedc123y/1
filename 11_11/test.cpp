#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;


//// 抽象类（也叫接口类）
//// 有纯虚函数的类叫抽象类 抽象类不可以实例化
//class Person
//{
//public:
//    // 是纯虚函数
//    virtual void BuyTicket() = 0;
//};
//class Student : public Person
//{
//    //没有重写纯虚函数
//};
//class Soldier : public Person
//{
//public:
//    //重写了纯虚函数
//    virtual void BuyTicket()
//    {
//        cout << "买票-优先" << endl;
//    }
//};
//int mian()
//{
//	Person p;//无法实例化抽象类
//    Student s;//无法实例化抽象类
//    Soldier s1;
//	return 0;
//}

//double area() 基类
//double area() const 派生类

// 基类Shape，通过派生出他的子类 Rectangle,Circle
// 抽象类
class Shape
{
public:
    // 纯虚函数
    virtual double area()const = 0;
};

class Rectangle : public Shape // 长方形
{
public:
    Rectangle(double _w, double _l)
        : w(_w), l(_l) {}

    virtual double area()
    {
        return w * l; // 计算长方形面积
    }

private:
    double w; // 宽度
    double l; // 长度
};

class Circle : public Shape // 圆形
{
public:
    Circle(double _r)
        : r(_r) {}

    virtual double area()
    {
        return 3.14 * r * r; // 计算圆形面积
    }

private:
    double r; // 半径
};

int main() {
    // 创建对象并演示多态
    Shape* shape1 = new Rectangle(5.0, 3.0);  // 长方形
    Shape* shape2 = new Circle(4.0);           // 圆形

    // 使用基类指针调用派生类的area函数
    cout << "Rectangle area: " << shape1->area() << endl;
    cout << "Circle area: " << shape2->area() << endl;

    return 0;
}

// 重写的步骤
// 如果说基类与派生类有同名函数，并且基类的该函数为虚函数
// 那么派生类的该函数就会进行重写（而不是覆盖）
//class Person
//{
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person
//{
//public:
//    virtual void BuyTicket() override
//    { cout << "买票-半价" << endl; } 
//};
//// 先写参数的类型  再写参数名
//// Person   Student 
//int main()
//{
//    Person p;
//    Student s;
//    p.BuyTicket();
//    s.BuyTicket();
//    return 0;
//}