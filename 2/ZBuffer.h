#pragma once
#include "CP3.h"
#include "CPoint3.h"
class CZBuffer
{
public:
    CZBuffer(void);
    ~CZBuffer(void);
    void SetPoint(CP3 P[3]);//浮点数顶点构造三角形
    void InitialDepthBuffer(int nWidth, int nHeight, double zDepth);//初始化深度缓冲器
    void Fill(CDC* pDC);//填充三角形

private:
    CP3 P[3];//三角形顶点
    CPoint3 point[3];//三角形的整数顶点坐标
    double** zBuffer;//深度缓冲区
    int nWidth, nHeight;//缓冲区宽度和高度
};