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
    // 初始化代码（如果有）
}

// 实现析构函数
CCube::~CCube()
{
    // 清理代码（如果有）
}
CP3* CCube::GetVertexArrayName(void)
{
    return V;
}

void CCube::ReadVertex(void) // 点表
{
    V[0].x = 0, V[0].y = 0, V[0].z = 0; V[0].c = CRGB(0.0, 0.0, 0.0); //黑色
    V[1].x = 1, V[1].y = 0, V[1].z = 0; V[1].c = CRGB(1.0, 0.0, 0.0); //红色
    V[2].x = 1, V[2].y = 1, V[2].z = 0; V[2].c = CRGB(1.0, 1.0, 0.0); //黄色
    V[3].x = 0, V[3].y = 1, V[3].z = 0; V[3].c = CRGB(0.0, 1.0, 0.0); //绿色
    V[4].x = 0, V[4].y = 0, V[4].z = 1; V[4].c = CRGB(0.0, 0.0, 1.0); //蓝色
    V[5].x = 1, V[5].y = 0, V[5].z = 1; V[5].c = CRGB(1.0, 0.0, 1.0); //品红
    V[6].x = 1, V[6].y = 1, V[6].z = 1; V[6].c = CRGB(1.0, 1.0, 1.0); //白色
    V[7].x = 0, V[7].y = 1, V[7].z = 1; V[7].c = CRGB(0.0, 1.0, 1.0); //青色
}

void CCube::ReadFace(void) // 面表
{
    // 面的顶点序号
    F[0].Index[0] = 4; F[0].Index[1] = 5; F[0].Index[2] = 6; F[0].Index[3] = 7;
    F[1].Index[0] = 0; F[1].Index[1] = 3; F[1].Index[2] = 2; F[1].Index[3] = 1;
    F[2].Index[0] = 0; F[2].Index[1] = 4; F[2].Index[2] = 7; F[2].Index[3] = 3;
    F[3].Index[0] = 1; F[3].Index[1] = 2; F[3].Index[2] = 6; F[3].Index[3] = 5;
    F[4].Index[0] = 2; F[4].Index[1] = 3; F[4].Index[2] = 7; F[4].Index[3] = 6;
    F[5].Index[0] = 0; F[5].Index[1] = 1; F[5].Index[2] = 5; F[5].Index[3] = 4;
}
void CCube::Draw(CDC* pDC, CZBuffer* pZBuffer)
{
    CP3 ScreenPoint4[4]; //三维投影点
    CP3 Eye = projection.GetEye(); //视点
    CVector3 N4[4]; //顶点的法矢量
    for (int nFace = 0; nFace < 6; nFace++) //面循环
    {
        CVector3 Vector01(V[F[nFace].Index[0]], V[F[nFace].Index[1]]); //面的一个边矢量
        CVector3 Vector02(V[F[nFace].Index[0]], V[F[nFace].Index[2]]); //面的另一个边矢量
        CVector3 FaceNormal = CrossProduct(Vector01, Vector02); //面的法矢量
        FaceNormal = FaceNormal.Normalize(); //归一化法矢量
        for (int nPoint = 0; nPoint < 4; nPoint++) //顶点循环
        {
            ScreenPoint4[nPoint] = projection.PerspectiveProjection3(V[F[nFace].Index[nPoint]]); //透视投影
        }
        //绘制左上三角形
        CP3 LTP[3] = { ScreenPoint4[0], ScreenPoint4[2], ScreenPoint4[3] };
        pZBuffer->SetPoint(LTP);
        pZBuffer->Fill(pDC);
        //绘制右下三角形
        CP3 RDP[3] = { ScreenPoint4[0], ScreenPoint4[1], ScreenPoint4[2] };
        pZBuffer->SetPoint(RDP);
        pZBuffer->Fill(pDC);
    }
}