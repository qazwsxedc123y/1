#include "pch.h"
#include "CPoint3.h"
CPoint3::CPoint3(void) {}  // ɾ�������һ�����

CPoint3::~CPoint3(void) {} // ɾ�������һ�����
CPoint3::CPoint3(int x, int y, double z):CPoint2(x,y)
{
    this->z = z;  // �ڹ��캯�����ڸ�ֵ
}