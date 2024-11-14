#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include <iostream>

using namespace std;


class Weapon 
{
public:
    virtual double attack() = 0;
};

class ShortWeapon : public Weapon 
{
private:
    double w; 
    double s;
public:

    ShortWeapon(double _w, double _s)
        : w(_w)
        , s(_s) 
    {
        if (_w <= 0) w = 0;
        if (_s <= 0) s = 0;
    }

    double attack()
    {
        return w * s * 0.5;
    }
};

class RemoteWeapon : public Weapon 
{
private:
    double w;
    double s;
public:
    // ���캯��
    RemoteWeapon(double _w, double _s) 
        : w(_w)
        , s(_s)
    {
        if (_w <= 0) w = 0;
        if (_s <= 0) s = 0;
    }


    double attack()
    {
        return w * s * 2; 
    }
}; 

int main()
{
    Weapon* wep1, * wep2; //����������ָ��
    int w1, s1, w2, s2;
    cin >> w1 >> s1 >> w2 >> s2;
    wep1 = new ShortWeapon(w1, s1); //������ָ��wep1ָ��ShortWeapon����
    wep2 = new RemoteWeapon(w2, s2); //������ָ��wep2ָ��RemoteWeapon����
    cout << "The attack value is :" << wep1->attack() << endl; //������������Ĺ���ֵ
    cout << "The attack value is :" << wep2->attack() << endl; //���Զ�������Ĺ���ֵ
}


//class Shape 
//{
//public:
//    virtual double area() = 0;
//};
//
//// ������������
//class Triangle : public Shape 
//{
//public:
//    Triangle(double _w, double _h)
//        : w(_w)
//        , h(_h)
//    {
//        if (_w <= 0) w = 0;
//        if (_h <= 0) h = 0;
//    }
//    double area()
//    {
//        return w * h * 0.5;
//    }
//private:
//    double w;
//    double h;
//};
//
//// ����������
//class Rectangel : public Shape 
//{
//public:
//    Rectangel(double _w, double _h)
//        : w(_w)
//        , h(_h) 
//    {
//        if (_w <= 0) w = 0;
//        if (_h <= 0) h = 0;
//    }
//    // ʵ���������
//    double area()
//    {
//        return w * h;
//    }
//private:
//    double w;
//    double h;
//};
//
//
//int main()
//{
//    Shape* s1, * s2; //����������ָ��
//    int w1, h1, w2, h2;
//    cin >> w1 >> h1 >> w2 >> h2;
//    s1 = new Triangle(w1, h1); //������ָ��s1ָ��Triangle����
//    s2 = new Rectangel(w2, h2); //������ָ��s2ָ��Rectangle����
//    cout << "The area of triangle is :" << s1->area() << endl; //��������ε����
//    cout << "The area of rectangle is :" << s2->area() << endl; //������ε����
//}

//class Shape 
//{
//public:
//    virtual double area() = 0;  
//};
//
//// ��������
//class Triangle : public Shape 
//{
//public:
//    Triangle(double _l, double _h) 
//        :l(_l)
//        ,h(_h) 
//    {}
//
//    double area()
//    {
//        return 0.5 * l * h;
//    }
//private:
//    double l;
//    double h; 
//};
//
//// ��������
//class Square : public Shape 
//{
//public:
//    Square(double _l,double _w) 
//        :l(_l) 
//        ,w(_w) 
//    {}
//
//    double area() 
//    {
//        return l * w;
//    }
//private:
//    double l;
//    double w;
//};
//
//// Բ����
//class Circle : public Shape 
//{
//public:
//    Circle(double _r) 
//        : r(_r) 
//    {}
//
//    double area() 
//    {
//        return 3.14 * r * r;
//    }
//private:
//    double r;
//};
//
//// ��������ͼ�������
//double total(Shape& shapes)
//{
//    double sum = 0;
//    sum += shapes.area();
//    return sum;
//}
//int main() {
//    int l1, h1, l2, w2, r;
//    cin >> l1 >> h1;
//    cin >> l2 >> w2;
//    cin >> r;
//    Triangle t(l1, h1); 
//    Square s(l2,w2);
//    Circle c(r);
//    double sum = 0;
//    sum += total(t);
//    sum += total(s);
//    sum += total(c);
//    cout << "sum = " << sum << endl;
//    return 0;
//}
