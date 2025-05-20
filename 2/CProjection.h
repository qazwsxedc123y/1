#pragma once
#include "CP3.h"
#include "CP2.h"
class CProjection
{
public:
    CProjection(void); // ���캯��
    virtual ~CProjection(void); // ��������

    CP2 OrthogonalProjection(CP3 WorldPoint); // ����ͶӰ
    CP2 CavalierProjection(CP3 WorldPoint); // б�Ȳ�ͶӰ
    CP2 CabinetProjection(CP3 WorldPoint); // б����ͶӰ
    CP2 PerspectiveProjection2(CP3 WorldPoint); // ��ά͸��ͶӰ
    CP3 PerspectiveProjection3(CP3 WorldPoint); // ������ά͸��ͶӰ

    void SetEye(CP3 Eye); // �����ӵ�
    CP3 GetEye(); // ��ȡ�ӵ�

private:
    CP3 EyePoint; // �ӵ�
    double R, d; // �Ӿ����Ӿ�
};
