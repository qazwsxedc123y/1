#pragma once
#include "CRGB.h"
class CPoint2 // �������࣬��������Ļ�ϻ�ͼ
{
public:
    CPoint2(void);                      // Ĭ�Ϲ��캯��
    CPoint2(int x, int y);              // ������Ĺ��캯��
    CPoint2(int x, int y, CRGB c);      // ���������ɫ�Ĺ��캯��
    virtual ~CPoint2(void);             // ������������֧�ֶ�̬��

public:
    int x, y;    // ���꣨�������ͣ�
    CRGB c;      // ��ɫ��CRGB���ͣ�������RGB��ɫ�ṹ�壩
};