#pragma once
#include "CVector3.h"
class CFace
{
public:
    CFace();
    ~CFace();
    void SetFaceNormal(CP3, CP3, CP3);

public:
    int Number; // 表面顶点数目
    int Index[4]; // 面的顶点索引号
    CVector3 fNormal;
};

