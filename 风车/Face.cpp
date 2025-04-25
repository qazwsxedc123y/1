#include "pch.h"
#include "Face.h"
#include <afxwin.h>  // ����MFC�Ļ�ͼ���ͷ�ļ�

// Ĭ�Ϲ��캯�����������ʼ��Ϊԭ��
CFace::CFace()
{
    for (int i = 0; i < 4; ++i)
    {
        vertices[i] = CP2(0, 0);
    }
}

// �������Ĺ��캯����ֱ�ӳ�ʼ������
CFace::CFace(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4)
{
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
}

// ������Ķ���
void CFace::SetVertices(const CP2& v1, const CP2& v2, const CP2& v3, const CP2& v4)
{
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
}

// ��ȡָ�������Ķ���
CP2 CFace::GetVertex(int index) const
{
    if (index >= 0 && index < 4)
    {
        return vertices[index];
    }
    // ����򵥷���ԭ�㣬ʵ�ʿ��Ը���������������
    return CP2(0, 0);
}

// �����棬����򵥵����������Ӷ���
void CFace::Draw(CDC* pDC)
{
    for (int i = 0; i < 3; ++i)
    {
        pDC->MoveTo(vertices[i].x, vertices[i].y);
        pDC->LineTo(vertices[i + 1].x, vertices[i + 1].y);
    }
    // �������һ������͵�һ������
    pDC->MoveTo(vertices[3].x, vertices[3].y);
    pDC->LineTo(vertices[0].x, vertices[0].y);
}