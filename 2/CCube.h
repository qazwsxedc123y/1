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
    void ReadVertex(void);  // ������
    void ReadFace(void);    // �������
    void Draw(CDC* pDC, CZBuffer* pZBuffer);  // ����������

public:
    CP3 V[8];  // ������8������
    CFace F[6]; // ������6����
    CProjection projection; // ͶӰ�任����
};