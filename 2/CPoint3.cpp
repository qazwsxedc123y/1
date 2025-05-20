#include "pch.h"
#include "CPoint3.h"
CPoint3::CPoint3(void) {}  // 删除多余右花括号

CPoint3::~CPoint3(void) {} // 删除多余右花括号
CPoint3::CPoint3(int x, int y, double z):CPoint2(x,y)
{
    this->z = z;  // 在构造函数体内赋值
}