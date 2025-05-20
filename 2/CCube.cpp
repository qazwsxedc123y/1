#include "pch.h"
#include "CP3.h"
#include "CCube.h"
#include "CFace.h"
#include "CProjection.h"
#include "CTransform3.h"
#define ROUND(d) int(d + 0.5)
double DotProduct(const CVector3& v1, const CVector3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
CCube::CCube()
{
    // ��ʼ�����루����У�
}

// ʵ����������
CCube::~CCube()
{
    // ������루����У�
}
CP3* CCube::GetVertexArrayName(void)
{
    return V;
}

void CCube::ReadVertex(void) // ���
{
    V[0].x = 0, V[0].y = 0, V[0].z = 0; V[0].c = CRGB(0.0, 0.0, 0.0); //��ɫ
    V[1].x = 1, V[1].y = 0, V[1].z = 0; V[1].c = CRGB(1.0, 0.0, 0.0); //��ɫ
    V[2].x = 1, V[2].y = 1, V[2].z = 0; V[2].c = CRGB(1.0, 1.0, 0.0); //��ɫ
    V[3].x = 0, V[3].y = 1, V[3].z = 0; V[3].c = CRGB(0.0, 1.0, 0.0); //��ɫ
    V[4].x = 0, V[4].y = 0, V[4].z = 1; V[4].c = CRGB(0.0, 0.0, 1.0); //��ɫ
    V[5].x = 1, V[5].y = 0, V[5].z = 1; V[5].c = CRGB(1.0, 0.0, 1.0); //Ʒ��
    V[6].x = 1, V[6].y = 1, V[6].z = 1; V[6].c = CRGB(1.0, 1.0, 1.0); //��ɫ
    V[7].x = 0, V[7].y = 1, V[7].z = 1; V[7].c = CRGB(0.0, 1.0, 1.0); //��ɫ
}

void CCube::ReadFace(void) // ���
{
    // ��Ķ������
    F[0].Index[0] = 4; F[0].Index[1] = 5; F[0].Index[2] = 6; F[0].Index[3] = 7;
    F[1].Index[0] = 0; F[1].Index[1] = 3; F[1].Index[2] = 2; F[1].Index[3] = 1;
    F[2].Index[0] = 0; F[2].Index[1] = 4; F[2].Index[2] = 7; F[2].Index[3] = 3;
    F[3].Index[0] = 1; F[3].Index[1] = 2; F[3].Index[2] = 6; F[3].Index[3] = 5;
    F[4].Index[0] = 2; F[4].Index[1] = 3; F[4].Index[2] = 7; F[4].Index[3] = 6;
    F[5].Index[0] = 0; F[5].Index[1] = 1; F[5].Index[2] = 5; F[5].Index[3] = 4;
}
void CCube::Draw(CDC* pDC, CZBuffer* pZBuffer)
{
    CP3 ScreenPoint4[4]; //��άͶӰ��
    CP3 Eye = projection.GetEye(); //�ӵ�
    CVector3 N4[4]; //����ķ�ʸ��
    for (int nFace = 0; nFace < 6; nFace++) //��ѭ��
    {
        CVector3 Vector01(V[F[nFace].Index[0]], V[F[nFace].Index[1]]); //���һ����ʸ��
        CVector3 Vector02(V[F[nFace].Index[0]], V[F[nFace].Index[2]]); //�����һ����ʸ��
        CVector3 FaceNormal = CrossProduct(Vector01, Vector02); //��ķ�ʸ��
        FaceNormal = FaceNormal.Normalize(); //��һ����ʸ��
        for (int nPoint = 0; nPoint < 4; nPoint++) //����ѭ��
        {
            ScreenPoint4[nPoint] = projection.PerspectiveProjection3(V[F[nFace].Index[nPoint]]); //͸��ͶӰ
        }
        //��������������
        CP3 LTP[3] = { ScreenPoint4[0], ScreenPoint4[2], ScreenPoint4[3] };
        pZBuffer->SetPoint(LTP);
        pZBuffer->Fill(pDC);
        //��������������
        CP3 RDP[3] = { ScreenPoint4[0], ScreenPoint4[1], ScreenPoint4[2] };
        pZBuffer->SetPoint(RDP);
        pZBuffer->Fill(pDC);
    }
}