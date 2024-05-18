#define  _CRT_SECURE_NO_WARNINGS
#include"test.h"

void Circle::Init(double r)
{
    this->_r = r;
}
double Circle::print()
{
    double C = _r * 2 * 3.14;
    return C;
}
int main()
{
    Circle s1;
    s1.Init(10.0);
    cout << sizeof(Circle) << endl;
    //cout << s1.print() << endl;
    return 0;
}