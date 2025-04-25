#pragma once
#include "P2.h"

class CFace
{
private:
    CP2 vertices[4];  // 存储面的4个顶点

public:
    // 构造函数，初始化面的顶点
    CFace();
    CFace(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4);

    // 设置面的顶点
    void SetVertices(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4);

    // 获取指定索引的顶点
    CP2 GetVertex(int index) const;

    // 绘制面，假设使用CDC绘图
    void Draw(CDC* pDC);
};
