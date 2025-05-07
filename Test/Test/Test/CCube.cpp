#include "pch.h"
#include "CCube.h"



CCube::CCube()
{

}
CCube::~CCube()
{

}
void CCube::ReadPoint(void)//���
{
    //�������ά����(x,y,z)
    P[0].x = 0, P[0].y = 0, P[0].z = 0;
    P[1].x = 1, P[1].y = 0, P[1].z = 0;
    P[2].x = 1, P[2].y = 1, P[2].z = 0;
    P[3].x = 0, P[3].y = 1, P[3].z = 0;
    P[4].x = 0, P[4].y = 0, P[4].z = 1;
    P[5].x = 1, P[5].y = 0, P[5].z = 1;
    P[6].x = 1, P[6].y = 1, P[6].z = 1;
    P[7].x = 0, P[7].y = 1, P[7].z = 1;
}
void CCube::ReadFacet(void)//���
{
    //��Ķ������
    F[0].Index[0] = 4; F[0].Index[1] = 5; F[0].Index[2] = 6; F[0].Index[3] = 7;//ǰ��
    F[1].Index[0] = 0; F[1].Index[1] = 3; F[1].Index[2] = 2; F[1].Index[3] = 1;//����
    F[2].Index[0] = 0; F[2].Index[1] = 4; F[2].Index[2] = 7; F[2].Index[3] = 3;//����
    F[3].Index[0] = 1; F[3].Index[1] = 2; F[3].Index[2] = 6; F[3].Index[3] = 5;//����
    F[4].Index[0] = 2; F[4].Index[1] = 3; F[4].Index[2] = 7; F[4].Index[3] = 6;//����
    F[5].Index[0] = 0; F[5].Index[1] = 1; F[5].Index[2] = 5; F[5].Index[3] = 4;//����
}
CP3* CCube::GetVertexArrayName(void)
{
    return P;
}

#define ROUND(d) int(d + 0.5)

void CCube::Draw(CDC* pDC)
{
    CP2 ScreenPoint, temp;
    CProjection projection;
    for (int nFacet = 0; nFacet < 6; nFacet++)// ��ѭ������������6����
    {
        CVector3 ViewVector(P[F[nFacet].Index[0]], projection.EyePoint);//�����ʸ��
        ViewVector = ViewVector.Normalize();//��ʸ����λ��
        F[nFacet].SetFaceNormal(P[F[nFacet].Index[0]], P[F[nFacet].Index[1]], P[F[nFacet].Index[2]]);
        F[nFacet].fNormal.Normalize();//��ĵ�λ����ʸ��
        for (int nPoint = 0; nPoint < 4; nPoint++)// ����ѭ����ÿ������4������
        {
            //ScreenPoint = projection.orthogonalProjection(P[F[nFacet].Index[nPoint]]);//��ͶӰ
            ScreenPoint = projection.obliqueProjection(P[F[nFacet].Index[nPoint]]);//бͶӰ 
            if (0 == nPoint)
            {
                // ����ͼ�豸�ĵ�ǰλ���ƶ���ͶӰ�����꣨ȡ����
                pDC->MoveTo(ROUND(ScreenPoint.x), ROUND(ScreenPoint.y));
                temp = ScreenPoint;
            }
            else
            {
                // �ӵ�ǰλ����ͶӰ�����꣨ȡ���󣩻���ֱ��
                pDC->LineTo(ROUND(ScreenPoint.x), ROUND(ScreenPoint.y));
            }
        }
        // ������һ����������ߺ󣬽����һ������ʼ�����ӣ����ͼ��
        pDC->LineTo(ROUND(temp.x), ROUND(temp.y));
    }
}