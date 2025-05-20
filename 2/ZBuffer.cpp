#include "pch.h"
#include "ZBuffer.h"
#include "CVector3.h"
#define ROUND(d) ((d) > 0 ? int(floor((d) + 0.5)) : int(floor((d) - 0.5)))
CZBuffer::CZBuffer()
{

}
CZBuffer::~CZBuffer()
{
    for (int i = 0; i < nWidth; i++)
    {
        delete[] zBuffer[i];
        zBuffer[i] = NULL;
    }
    if (zBuffer != NULL)
    {
        delete zBuffer;
        zBuffer = NULL;
    }
}
void CZBuffer::SetPoint(CP3 P[3])
{
    for (int nPoint = 0; nPoint < 3; nPoint++)
    {
        this->P[nPoint] = P[nPoint];
        point[nPoint].x = ROUND(P[nPoint].x);
        point[nPoint].y = ROUND(P[nPoint].y);
        point[nPoint].z = P[nPoint].z;
        point[nPoint].c = P[nPoint].c;
    }
}
void CZBuffer::InitialDepthBuffer(int nWidth, int nHeight, double nDepth)
{
    this->nWidth = nWidth, this->nHeight = nHeight;
    zBuffer = new double* [nWidth];
    for (int i = 0; i < nWidth; i++)
        zBuffer[i] = new double[nHeight];
    for (int i = 0; i < nWidth; i++)
        for (int j = 0; j < nHeight; j++)
            zBuffer[i][j] = nDepth;
}
void CZBuffer::Fill(CDC* pDC) // ���������
{
    // ���������ΰ�Χ��
    int xMin = min(point[0].x, min(point[1].x, point[2].x));
    int yMin = min(point[0].y, min(point[1].y, point[2].y));
    int xMax = max(point[0].x, max(point[1].x, point[2].x));
    int yMax = max(point[0].y, max(point[1].y, point[2].y));

    double CurrentDepth = 0.0;
    CVector3 Vector01(P[0], P[1]), Vector02(P[0], P[2]);
    CVector3 fNormal = CrossProduct(Vector01, Vector02);
    double A = fNormal.x, B = fNormal.y, C = fNormal.z; // ƽ�淽�� Ax+By+Cz+D=0 ��ϵ��
    double D = -A * P[0].x - B * P[0].y - C * P[0].z; // ϵ��D

    if (fabs(C) < 1e-4)
        C = 1.0;

    double DepthStep = -A / C; // ɨ������Ȳ���
    CurrentDepth = -(A * xMin + B * yMin + D) / C; // ������ʼ���������

    // ɨ�������
    for (int y = yMin; y < yMax; y++) // �����������
    {
        for (int x = xMin; x < xMax; x++) // �����������
        {
            double Area = point[0].x * point[1].y + point[1].x * point[2].y + point[2].x * point[0].y
                - point[1].x * point[0].y - point[2].x * point[1].y - point[0].x * point[2].y;
            double Area0 = x * point[1].y + point[1].x * point[2].y + point[2].x * y
                - point[1].x * y - point[2].x * point[1].y - x * point[2].y;
            double Area1 = x * point[2].y + point[2].x * point[0].y + point[0].x * y
                - point[2].x * y - point[0].x * point[2].y - x * point[0].y;

            double alpha = Area0 / Area, beta = Area1 / Area, gara = 1 - alpha - beta;

            if (alpha >= 0 && beta >= 0 && gara >= 0)
            {
                CurrentDepth = -(A * x + B * y + D) / C;
                CRGB crColor = alpha * point[0].c + beta * point[1].c + gara * point[2].c;

                if (CurrentDepth <= zBuffer[x + nWidth / 2][y + nHeight / 2])
                {
                    zBuffer[x + nWidth / 2][y + nHeight / 2] = CurrentDepth;
                    pDC->SetPixel(x, y, RGB(crColor.red * 255, crColor.green * 255, crColor.blue * 255));
                }
            }

            CurrentDepth += DepthStep;
        }
    }
}