#pragma once
#include "CP3.h"

class CVector3
{
public:
    CVector3();
    ~CVector3();
    CVector3(double x, double y, double z);
    CVector3(const CP3&);
    CVector3(const CP3&, const CP3&);
    double Mag();//矢量的模
    CVector3 Normalize();//单位矢量
    friend double Dot(const CVector3&, const CVector3&);  //矢量点积
    friend CVector3 Cross(const CVector3&, const CVector3&);//矢量叉积

public:
    double x, y, z;//公有数据成员，方便外部访问
};
