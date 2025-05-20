#pragma once
#include "CP3.h"
#include "CPoint3.h"
class CZBuffer
{
public:
    CZBuffer(void);
    ~CZBuffer(void);
    void SetPoint(CP3 P[3]);//���������㹹��������
    void InitialDepthBuffer(int nWidth, int nHeight, double zDepth);//��ʼ����Ȼ�����
    void Fill(CDC* pDC);//���������

private:
    CP3 P[3];//�����ζ���
    CPoint3 point[3];//�����ε�������������
    double** zBuffer;//��Ȼ�����
    int nWidth, nHeight;//��������Ⱥ͸߶�
};