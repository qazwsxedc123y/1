#pragma once
#include "CP3.h"
class CVector3
{
public:
    // 构造函数和析构函数
    CVector3();
    ~CVector3();
    CVector3(double, double, double);
    CVector3(const CP3&);
    CVector3(const CP3&, const CP3&);

    // 成员函数
    double Mag(); // 计算向量的模
    CVector3 Normalize(); // 计算单位向量

    // 友元函数
    friend double Dot(const CVector3&, const CVector3&); // 向量点积
    friend CVector3 CrossProduct(const CVector3&, const CVector3&); // 向量叉积

    // 公有数据成员
    double x, y, z; // 方便外部访问的公有数据成员
};
