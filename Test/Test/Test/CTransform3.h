#pragma once
#include "CP2.h"
#include "CP3.h"    
#include <math.h>
class CTransform3
{
public:
    CTransform3();
    virtual ~CTransform3(void);

    // 设置顶点数组和顶点数量
    void SetMatrix(CP3* Point, int ptNumber);

    // 将变换矩阵初始化为单位矩阵
    void Identity(void);

    // 平移变换
    void Translate(double tx, double ty, double tz);

    // 比例变换（相对于原点）
    void Scale(double sx, double sy, double sz);

    // 比例变换（相对于指定点）
    void Scale(double sx, double sy, double sz, CP3 p);

    // 旋转变换（绕X轴）
    void RotateX(double beta);

    // 旋转变换（绕X轴，以指定点为中心）
    void RotateX(double beta, CP3 p);

    // 旋转变换（绕Y轴）
    void RotateY(double beta);

    // 旋转变换（绕Y轴，以指定点为中心）
    void RotateY(double beta, CP3 p);

    // 旋转变换（绕Z轴）
    void RotateZ(double beta);

    // 旋转变换（绕Z轴，以指定点为中心）
    void RotateZ(double beta, CP3 p);

    // 反射变换（关于原点）
    void ReflectO(void);

    // 反射变换（关于XOY平面）
    void ReflectXOY(void);

    // 反射变换（关于YOZ平面）
    void ReflectYOZ(void);

    // 反射变换（关于ZOX平面）
    void ReflectZOX(void);

    // 错切变换（三维错切有多种形式，这里提供一种实现）
    void Shear(double b, double c, double d);

    // 矩阵相乘（应用变换）
    void MultiplyMatrix(void);

private:
    double T[4][4];  // 4x4 三维变换矩阵
    CP3* P;          // 顶点数组
    int ptNumber;     // 顶点数量
};

