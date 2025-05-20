#include "pch.h"
#include "CTransform3.h"
#include "CP3.h"
#define PI 3.1415926
CTransform3::CTransform3()
{
    // ��ʼ�����루����У�
}

// ��������
CTransform3::~CTransform3()
{
    // ������루����У�
}
void CTransform3::Identity() // ��λ�����ʼ��
{
    M[0][0] = 1.0; M[0][1] = 0.0; M[0][2] = 0.0; M[0][3] = 0.0;
    M[1][0] = 0.0; M[1][1] = 1.0; M[1][2] = 0.0; M[1][3] = 0.0;
    M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0; M[2][3] = 0.0;
    M[3][0] = 0.0; M[3][1] = 0.0; M[3][2] = 0.0; M[3][3] = 1.0;
}

void CTransform3::SetMatrix(CP3* P, int ptNumber) // ���������ʼ��
{
    this->P = P;
    this->ptNumber = ptNumber;
}

void CTransform3::Translate(double tx, double ty, double tz) // ƽ�Ʊ任
{
    Identity();
    M[0][3] = tx;
    M[1][3] = ty;
    M[2][3] = tz;
    MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz) // �����任
{
    Identity();
    M[0][0] = sx;
    M[1][1] = sy;
    M[2][2] = sz;
    MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz, CP3 p) // ����������ı����任
{
    Translate(-p.x, -p.y, -p.z);
    Scale(sx, sy, sz);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateX(double beta) // ��X����ת�任
{
    Identity();
    double rad = beta * PI / 180;
    M[1][1] = cos(rad); M[1][2] = -sin(rad);
    M[2][1] = sin(rad); M[2][2] = cos(rad);
    MultiplyMatrix();
}

void CTransform3::RotateY(double beta) // ��Y����ת�任
{
    Identity();
    double rad = beta * PI / 180;
    M[0][0] = cos(rad); M[0][2] = sin(rad);
    M[2][0] = -sin(rad); M[2][2] = cos(rad);
    MultiplyMatrix();
}

void CTransform3::RotateZ(double beta) // ��Z����ת�任
{
    Identity();
    double rad = beta * PI / 180;
    M[0][0] = cos(rad); M[0][1] = -sin(rad);
    M[1][0] = sin(rad); M[1][1] = cos(rad);
    MultiplyMatrix();
}
void CTransform3::RotateX(double beta, CP3 p) // �����������X����ת�任
{
    Translate(-p.x, -p.y, -p.z);
    RotateX(beta);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateY(double beta, CP3 p) // �����������Y����ת�任
{
    Translate(-p.x, -p.y, -p.z);
    RotateY(beta);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateZ(double beta, CP3 p) // �����������Z����ת�任
{
    Translate(-p.x, -p.y, -p.z);
    RotateZ(beta);
    Translate(p.x, p.y, p.z);
}
void CTransform3::ReflectX() // X�ᷴ��任
{
    Identity();
    M[1][1] = -1;
    M[2][2] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectY() // Y�ᷴ��任
{
    Identity();
    M[0][0] = -1;
    M[2][2] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectZ() // Z�ᷴ��任
{
    Identity();
    M[0][0] = -1;
    M[1][1] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectXOY() // XOY�淴��任
{
    Identity();
    M[2][2] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectYOZ() // YOZ�淴��任
{
    Identity();
    M[0][0] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectZOX() // ZOX�淴��任
{
    Identity();
    M[1][1] = -1;
    MultiplyMatrix();
}
void CTransform3::ShearX(double b, double c) // X������б任
{
    Identity();
    M[0][1] = b;
    M[0][2] = c;
    MultiplyMatrix();
}
void CTransform3::ShearY(double d, double f) // Y������б任
{
    Identity();
    M[1][0] = d;
    M[1][2] = f;
    MultiplyMatrix();
}
void CTransform3::ShearZ(double g, double h) // Z������б任
{
    Identity();
    M[2][0] = g;
    M[2][1] = h;
    MultiplyMatrix();
}
void CTransform3::MultiplyMatrix() // �������
{
    CP3* PTemp = new CP3[ptNumber];
    for (int i = 0; i < ptNumber; i++)
    {
        PTemp[i] = P[i];
    }
    for (int i = 0; i < ptNumber; i++)
    {
        P[i].x = M[0][0] * PTemp[i].x + M[0][1] * PTemp[i].y + M[0][2] * PTemp[i].z + M[0][3] * PTemp[i].w;
        P[i].y = M[1][0] * PTemp[i].x + M[1][1] * PTemp[i].y + M[1][2] * PTemp[i].z + M[1][3] * PTemp[i].w;
        P[i].z = M[2][0] * PTemp[i].x + M[2][1] * PTemp[i].y + M[2][2] * PTemp[i].z + M[2][3] * PTemp[i].w;
        P[i].w = M[3][0] * PTemp[i].x + M[3][1] * PTemp[i].y + M[3][2] * PTemp[i].z + M[3][3] * PTemp[i].w;
    }
    delete[] PTemp;
}