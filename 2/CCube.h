#pragma once
#include "CP3.h"
#include "CFace.h"
#include "ZBuffer.h"
#include "CProjection.h"
class CCube
{
public:
    CCube(void);
    virtual ~CCube(void);

    CP3* GetVertexArrayName(void);
    void ReadVertex(void);  // 读入点表
    void ReadFace(void);    // 读入面表
    void Draw(CDC* pDC, CZBuffer* pZBuffer);  // 绘制立方体

public:
    CP3 V[8];  // 立方体8个顶点
    CFace F[6]; // 立方体6个面
    CProjection projection; // 投影变换工具
};