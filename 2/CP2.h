#pragma once
#include "CRGB.h"
class CP2
{
public:
    CP2();                          
    ~CP2();                         
    CP2(double x, double y);
    CP2(double x, double y, CRGB c);
    friend CP2 operator +(const CP2&, const CP2&);
    friend CP2 operator -(const CP2&, const CP2&);
    friend CP2 operator *(const CP2&, double);
    friend CP2 operator *(double, const CP2&);
    friend CP2 operator /(const CP2&, double);
    friend CP2 operator+=(const CP2&, const CP2&);
    friend CP2 operator-=(const CP2&, const CP2&);
    friend CP2 operator+=(const CP2&, double);
    friend CP2 operator/=(const CP2&, double);

public:
    double x;  // x����
    double y;  // y����
    double w;  // Ȩ�ػ�������꣨Ĭ��Ϊ1��
    CRGB c;
};
