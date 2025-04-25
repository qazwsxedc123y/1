#include "pch.h"
#include "P2.h"
// CP2��Ĺ��캯�����޲�
CP2::CP2() : x(0), y(0), w(1) {}
// CP2�����������
CP2::~CP2() {}
// CP2����вι��캯��
CP2::CP2(double _x, double _y) : x(_x), y(_y), w(1) {}

// ���ؼӷ������
CP2 operator+(const CP2& p1, const CP2& p2) {
    return CP2(p1.x + p2.x, p1.y + p2.y);
}

// ���ؼ��������
CP2 operator-(const CP2& p1, const CP2& p2) {
    return CP2(p1.x - p2.x, p1.y - p2.y);
}

// ���������������double��ǰ��
CP2 operator*(double scalar, const CP2& p) {
    return CP2(scalar * p.x, scalar * p.y);
}

// ���������������CP2��ǰ��
CP2 operator*(const CP2& p, double scalar) {
    return CP2(scalar * p.x, scalar * p.y);
}

// ���س��������
CP2 operator/(const CP2& p, double scalar) {
    return CP2(p.x / scalar, p.y / scalar);
}

// ���ظ��ϼӷ������
CP2 operator+=(CP2& p1, const CP2& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// ���ظ��ϼ��������
CP2 operator-=(CP2& p1, const CP2& p2) {
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

// ���ظ������������
CP2 operator*=(CP2& p, double scalar) {
    p.x *= scalar;
    p.y *= scalar;
    return p;
}

// ���ظ��ϳ��������
CP2 operator/=(CP2& p, double scalar) {
    p.x /= scalar;
    p.y /= scalar;
    return p;
}


// CTransform��Ĺ��캯��
CTransform::CTransform() {
    // ��ʼ���任����Ϊ��λ����
    Identity();
    Pold = nullptr;
    num = 0;
}

// CTransform�����������
CTransform::~CTransform() {
    if (Pold != nullptr) {
        delete[] Pold;
    }
}

// ���þ����������
void CTransform::SetMat(CP2* points, int count) {
    Pold = points;
    num = count;
}

// ���þ���Ϊ��λ����
void CTransform::Identity() {
    T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
    T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
    T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
}

// ƽ�Ʊ任����
void CTransform::Translate(double tx, double ty) {
    T[0][2] = tx;
    T[1][2] = ty;
}

// �����任����
void CTransform::Scale(double sx, double sy) {
    T[0][0] = sx;
    T[1][1] = sy;
}

// ����������ı����任����
void CTransform::Scale(double sx, double sy, CP2 p) {
    Translate(-p.x, -p.y);
    Scale(sx, sy);
    Translate(p.x, p.y);
}

// ��ת�任������ԭ�㣩
void CTransform::Rotate(double angle) {
    double cosA = cos(angle);
    double sinA = sin(angle);
    T[0][0] = cosA; T[0][1] = -sinA;
    T[1][0] = sinA; T[1][1] = cosA;
}

// �������������ת�任����
void CTransform::Rotate(double angle, CP2 p) {
    Translate(-p.x, -p.y);
    Rotate(angle);
    Translate(p.x, p.y);
}

// ԭ�㷴��任����
void CTransform::ReflectOrg() {
    T[0][0] = -1;
    T[1][1] = -1;
}

// X�ᷴ��任����
void CTransform::ReflectX() {
    T[0][0] = 1;
    T[1][1] = -1;
}

// Y�ᷴ��任����
void CTransform::ReflectY() {
    T[0][0] = -1;
    T[1][1] = 1;
}

// ���б任����
void CTransform::Shear(double shx, double shy) {
    T[0][1] = shx;
    T[1][0] = shy;
}

// �������
void CTransform::MultiMatrix() {
    // �����ʾ����ʵ�ʸ����������ƾ�������߼�
    // ������������������T������˵Ĺ���
}