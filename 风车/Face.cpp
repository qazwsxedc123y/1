#include "pch.h"
#include "Face.h"
#include <afxwin.h>  // 包含MFC的绘图相关头文件

// 默认构造函数，将顶点初始化为原点
CFace::CFace()
{
    for (int i = 0; i < 4; ++i)
    {
        vertices[i] = CP2(0, 0);
    }
}

// 带参数的构造函数，直接初始化顶点
CFace::CFace(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4)
{
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
}

// 设置面的顶点
void CFace::SetVertices(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4)
{
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
}

// 获取指定索引的顶点
CP2 CFace::GetVertex(int index) const
{
    if (index >= 0 && index < 4)
    {
        return vertices[index];
    }
    // 这里简单返回原点，实际可以根据需求处理错误情况
    return CP2(0, 0);
}

// 绘制面，假设简单地用线条连接顶点
void CFace::Draw(CDC* pDC)
{
    for (int i = 0; i < 3; ++i)
    {
        pDC->MoveTo(vertices[i].x, vertices[i].y);
        pDC->LineTo(vertices[i + 1].x, vertices[i + 1].y);
    }
    // 连接最后一个顶点和第一个顶点
    pDC->MoveTo(vertices[3].x, vertices[3].y);
    pDC->LineTo(vertices[0].x, vertices[0].y);
}