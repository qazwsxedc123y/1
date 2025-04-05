#include "pch.h"
#include "P2.h"
// CP2类的构造函数，无参
CP2::CP2() : x(0), y(0), w(1) {}
// CP2类的析构函数
CP2::~CP2() {}
// CP2类的有参构造函数
CP2::CP2(double _x, double _y) : x(_x), y(_y), w(1) {}

// 重载加法运算符
CP2 operator+(const CP2& p1, const CP2& p2) {
    return CP2(p1.x + p2.x, p1.y + p2.y);
}

// 重载减法运算符
CP2 operator-(const CP2& p1, const CP2& p2) {
    return CP2(p1.x - p2.x, p1.y - p2.y);
}

// 重载数乘运算符（double在前）
CP2 operator*(double scalar, const CP2& p) {
    return CP2(scalar * p.x, scalar * p.y);
}

// 重载数乘运算符（CP2在前）
CP2 operator*(const CP2& p, double scalar) {
    return CP2(scalar * p.x, scalar * p.y);
}

// 重载除法运算符
CP2 operator/(const CP2& p, double scalar) {
    return CP2(p.x / scalar, p.y / scalar);
}

// 重载复合加法运算符
CP2 operator+=(CP2& p1, const CP2& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// 重载复合减法运算符
CP2 operator-=(CP2& p1, const CP2& p2) {
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

// 重载复合数乘运算符
CP2 operator*=(CP2& p, double scalar) {
    p.x *= scalar;
    p.y *= scalar;
    return p;
}

// 重载复合除法运算符
CP2 operator/=(CP2& p, double scalar) {
    p.x /= scalar;
    p.y /= scalar;
    return p;
}


// CTransform类的构造函数
CTransform::CTransform() {
    // 初始化变换矩阵为单位矩阵
    Identity();
    Pold = nullptr;
    num = 0;
}

// CTransform类的析构函数
CTransform::~CTransform() {
    if (Pold != nullptr) {
        delete[] Pold;
    }
}

// 设置矩阵相关数据
void CTransform::SetMat(CP2* points, int count) {
    Pold = points;
    num = count;
}

// 设置矩阵为单位矩阵
void CTransform::Identity() {
    T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
    T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
    T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
}

// 平移变换矩阵
void CTransform::Translate(double tx, double ty) {
    T[0][2] = tx;
    T[1][2] = ty;
}

// 比例变换矩阵
void CTransform::Scale(double sx, double sy) {
    T[0][0] = sx;
    T[1][1] = sy;
}

// 相对于任意点的比例变换矩阵
void CTransform::Scale(double sx, double sy, CP2 p) {
    Translate(-p.x, -p.y);
    Scale(sx, sy);
    Translate(p.x, p.y);
}

// 旋转变换矩阵（绕原点）
void CTransform::Rotate(double angle) {
    double cosA = cos(angle);
    double sinA = sin(angle);
    T[0][0] = cosA; T[0][1] = -sinA;
    T[1][0] = sinA; T[1][1] = cosA;
}

// 相对于任意点的旋转变换矩阵
void CTransform::Rotate(double angle, CP2 p) {
    Translate(-p.x, -p.y);
    Rotate(angle);
    Translate(p.x, p.y);
}

// 原点反射变换矩阵
void CTransform::ReflectOrg() {
    T[0][0] = -1;
    T[1][1] = -1;
}

// X轴反射变换矩阵
void CTransform::ReflectX() {
    T[0][0] = 1;
    T[1][1] = -1;
}

// Y轴反射变换矩阵
void CTransform::ReflectY() {
    T[0][0] = -1;
    T[1][1] = 1;
}

// 错切变换矩阵
void CTransform::Shear(double shx, double shy) {
    T[0][1] = shx;
    T[1][0] = shy;
}

// 矩阵相乘
void CTransform::MultiMatrix() {
    // 这里简单示例，实际根据需求完善矩阵相乘逻辑
    // 假设已有其他矩阵与T矩阵相乘的规则
}