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
    void Translate(double, double);//ƽ�Ʊ任����
    void Scale(double, double);//�����任����
    void Scale(double, double, CP2);//����������ı����任����
    void Rotate(double);//��ת�任����
    void Rotate(double, CP2);//�������������ת�任����
    void ReflectOrg();//ԭ�㷴��任����
    void ReflectX();//X�ᷴ��任����
    void ReflectY();//Y�ᷴ��任����
    void Shear(double, double);//���б任����
    void MultiMatrix();//�������
public:
    double T[3][3];
    CP2* Pold;
    int num;
};

