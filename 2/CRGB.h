#pragma once
class CRGB
{
public:
    // 构造函数和析构函数
    CRGB();
    ~CRGB();

    // 带参数的构造函数，可以指定红色、绿色、蓝色和透明度，默认透明度为0.0
    CRGB(double red, double green, double blue, double alpha = 0.0);

    // 友元函数：重载加法运算符，用于两个 CRGB 对象相加
    friend CRGB operator + (const CRGB& c0, const CRGB& c1);

    // 友元函数：重载乘法运算符，用于一个标量与 CRGB 对象相乘
    friend CRGB operator * (double scalar, const CRGB& c);

    // 成员函数：将颜色分量归一化到 [0,1] 区间
    void Normalize(void);

public:
    // 公有成员变量：存储红色、绿色、蓝色和透明度分量
    double red;   // 红色分量
    double green; // 绿色分量
    double blue;  // 蓝色分量
    double alpha; // 透明度分量
};