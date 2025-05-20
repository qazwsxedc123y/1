#pragma once
#include "CP3.h"
#include "CP2.h"
class CProjection
{
public:
    CProjection(void); // 构造函数
    virtual ~CProjection(void); // 析构函数

    CP2 OrthogonalProjection(CP3 WorldPoint); // 正交投影
    CP2 CavalierProjection(CP3 WorldPoint); // 斜等测投影
    CP2 CabinetProjection(CP3 WorldPoint); // 斜二测投影
    CP2 PerspectiveProjection2(CP3 WorldPoint); // 二维透视投影
    CP3 PerspectiveProjection3(CP3 WorldPoint); // 新增三维透视投影

    void SetEye(CP3 Eye); // 设置视点
    CP3 GetEye(); // 获取视点

private:
    CP3 EyePoint; // 视点
    double R, d; // 视径和视距
};
