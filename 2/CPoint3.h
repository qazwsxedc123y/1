#pragma once
#include"CPoint2.h"
class CPoint3 :public CPoint2// 继承自CPoint2
{
public:
    CPoint3(void);                     // 默认构造函数
    CPoint3(int x, int y, double z);   // 带参数的构造函数
    virtual ~CPoint3(void);            // 虚析构函数（支持多态）

public:
    double z;  // 新增的z坐标（浮点类型）
};
