#pragma once
#include"CPoint2.h"
class CPoint3 :public CPoint2// �̳���CPoint2
{
public:
    CPoint3(void);                     // Ĭ�Ϲ��캯��
    CPoint3(int x, int y, double z);   // �������Ĺ��캯��
    virtual ~CPoint3(void);            // ������������֧�ֶ�̬��

public:
    double z;  // ������z���꣨�������ͣ�
};
