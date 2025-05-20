#pragma once
#include "CP3.h"
class CVector3
{
public:
    // ���캯������������
    CVector3();
    ~CVector3();
    CVector3(double, double, double);
    CVector3(const CP3&);
    CVector3(const CP3&, const CP3&);

    // ��Ա����
    double Mag(); // ����������ģ
    CVector3 Normalize(); // ���㵥λ����

    // ��Ԫ����
    friend double Dot(const CVector3&, const CVector3&); // �������
    friend CVector3 CrossProduct(const CVector3&, const CVector3&); // �������

    // �������ݳ�Ա
    double x, y, z; // �����ⲿ���ʵĹ������ݳ�Ա
};
