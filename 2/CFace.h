#pragma once
#include "CVector3.h"
class CFace
{
public:
    CFace();
    ~CFace();
    void SetFaceNormal(CP3, CP3, CP3);

public:
    int Number; // ���涥����Ŀ
    int Index[4]; // ��Ķ���������
    CVector3 fNormal;
};

