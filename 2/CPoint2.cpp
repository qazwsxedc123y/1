#include "pch.h"
#include "CPoint2.h"
CPoint2::CPoint2(void)
{
    x = 0;
    y = 0;
    c = CRGB(0, 0, 0);
}  // ��ȫ�һ�����
CPoint2::~CPoint2(void)
{
}  // ɾ��������һ�����
CPoint2::CPoint2(int x, int y)
{
    this->x = x;
    this->y = y;
    c = CRGB(0, 0, 0);
}  // ��ȫ�һ�����
CPoint2::CPoint2(int x, int y, CRGB c) : x(x), y(y), c(c) {}