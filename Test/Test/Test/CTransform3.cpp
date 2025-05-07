#include "pch.h"
#include "CTransform3.h"
#include <math.h>

#define PI 3.1415926

CTransform3::CTransform3()
{
}

CTransform3::~CTransform3(void)
{
}

void CTransform3::SetMatrix(CP3* P, int ptNumber)
{
    this->P = P;
    this->ptNumber = ptNumber;
}

void CTransform3::Identity(void)
{
    // 初始化4x4单位矩阵
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            T[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

void CTransform3::Translate(double tx, double ty, double tz)
{
    Identity();
    T[0][3] = tx;
    T[1][3] = ty;
    T[2][3] = tz;
    MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz)
{
    Identity();
    T[0][0] = sx;
    T[1][1] = sy;
    T[2][2] = sz;
    MultiplyMatrix();
}

void CTransform3::Scale(double sx, double sy, double sz, CP3 p)
{
    Translate(-p.x, -p.y, -p.z);
    Scale(sx, sy, sz);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateX(double beta)
{
    double rad = beta * PI / 180;
    Identity();
    T[1][1] = cos(rad);
    T[1][2] = -sin(rad);
    T[2][1] = sin(rad);
    T[2][2] = cos(rad);
    MultiplyMatrix();
}

void CTransform3::RotateX(double beta, CP3 p)
{
    Translate(-p.x, -p.y, -p.z);
    RotateX(beta);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateY(double beta)
{
    double rad = beta * PI / 180;
    Identity();
    T[0][0] = cos(rad);
    T[0][2] = sin(rad);
    T[2][0] = -sin(rad);
    T[2][2] = cos(rad);
    MultiplyMatrix();
}

void CTransform3::RotateY(double beta, CP3 p)
{
    Translate(-p.x, -p.y, -p.z);
    RotateY(beta);
    Translate(p.x, p.y, p.z);
}

void CTransform3::RotateZ(double beta)
{
    double rad = beta * PI / 180;
    Identity();
    T[0][0] = cos(rad);
    T[0][1] = -sin(rad);
    T[1][0] = sin(rad);
    T[1][1] = cos(rad);
    MultiplyMatrix();
}

void CTransform3::RotateZ(double beta, CP3 p)
{
    Translate(-p.x, -p.y, -p.z);
    RotateZ(beta);
    Translate(p.x, p.y, p.z);
}

void CTransform3::ReflectO(void)
{
    Identity();
    T[0][0] = -1;
    T[1][1] = -1;
    T[2][2] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectXOY(void)
{
    Identity();
    T[2][2] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectYOZ(void)
{
    Identity();
    T[0][0] = -1;
    MultiplyMatrix();
}

void CTransform3::ReflectZOX(void)
{
    Identity();
    T[1][1] = -1;
    MultiplyMatrix();
}

void CTransform3::Shear(double b, double c, double d)
{
    Identity();
    T[0][1] = b; // XY方向错切
    T[0][2] = c; // XZ方向错切
    T[1][2] = d; // YZ方向错切
    MultiplyMatrix();
}

void CTransform3::MultiplyMatrix(void)
{
    CP3* PTemp = new CP3[ptNumber];
    for (int i = 0; i < ptNumber; i++)
        PTemp[i] = P[i];

    for (int i = 0; i < ptNumber; i++)
    {
        double x = PTemp[i].x;
        double y = PTemp[i].y;
        double z = PTemp[i].z;
        double w = PTemp[i].w;

        P[i].x = T[0][0] * x + T[0][1] * y + T[0][2] * z + T[0][3] * w;
        P[i].y = T[1][0] * x + T[1][1] * y + T[1][2] * z + T[1][3] * w;
        P[i].z = T[2][0] * x + T[2][1] * y + T[2][2] * z + T[2][3] * w;
        P[i].w = T[3][0] * x + T[3][1] * y + T[3][2] * z + T[3][3] * w;
    }

    delete[] PTemp;
}