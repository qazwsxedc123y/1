#pragma once
class CP2
{
public:
    CP2();
    ~CP2();
    CP2(double, double);
    friend CP2 operator +(const CP2&, const CP2&);
    friend CP2 operator -(const CP2&, const CP2&);
    friend CP2 operator *(double, const CP2&);
    friend CP2 operator *(const CP2&, double);
    friend CP2 operator /(const CP2&, double);
    friend CP2 operator+=(const CP2&, const CP2&);
    friend CP2 operator-=(const CP2&, const CP2&);
    friend CP2 operator*=(const CP2&, double);
    friend CP2 operator/=(const CP2&, double);
public:
    double x;
    double y;
    double w;
};

class CTransform
{
public:
    CTransform();
    ~CTransform();
    void SetMat(CP2*, int);
    void Identity();
    void Translate(double, double);//平移变换矩阵
    void Scale(double, double);//比例变换矩阵
    void Scale(double, double, CP2);//相对于任意点的比例变换矩阵
    void Rotate(double);//旋转变换矩阵
    void Rotate(double, CP2);//相对于任意点的旋转变换矩阵
    void ReflectOrg();//原点反射变换矩阵
    void ReflectX();//X轴反射变换矩阵
    void ReflectY();//Y轴反射变换矩阵
    void Shear(double, double);//错切变换矩阵
    void MultiMatrix();//矩阵相乘
public:
    double T[3][3];
    CP2* Pold;
    int num;
};

