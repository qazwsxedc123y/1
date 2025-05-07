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
    double Mag();//ʸ����ģ
    CVector3 Normalize();//��λʸ��
    friend double Dot(const CVector3&, const CVector3&);  //ʸ�����
    friend CVector3 Cross(const CVector3&, const CVector3&);//ʸ�����

public:
    double x, y, z;//�������ݳ�Ա�������ⲿ����
};
