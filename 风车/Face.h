#pragma once
#include "P2.h"

class CFace
{
private:
    CP2 vertices[4];  // �洢���4������

public:
    // ���캯������ʼ����Ķ���
    CFace();
    CFace(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4);

    // ������Ķ���
    void SetVertices(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4);

    // ��ȡָ�������Ķ���
    CP2 GetVertex(int index) const;

    // �����棬����ʹ��CDC��ͼ
    void Draw(CDC* pDC);
};
