#pragma once
#include "CRGB.h"
class CPoint2 // 整数点类，用于在屏幕上绘图
{
public:
    CPoint2(void);                      // 默认构造函数
    CPoint2(int x, int y);              // 带坐标的构造函数
    CPoint2(int x, int y, CRGB c);      // 带坐标和颜色的构造函数
    virtual ~CPoint2(void);             // 虚析构函数（支持多态）

public:
    int x, y;    // 坐标（整数类型）
    CRGB c;      // 颜色（CRGB类型，可能是RGB颜色结构体）
};