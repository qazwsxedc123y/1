#include "pch.h"
#include "CProjection.h"
#include "CP3.h"
CProjection::CProjection()
{
    R = 1200;
    d = 800;
    EyePoint.x = 0;
    EyePoint.y = 0;
    EyePoint.z = R;
}

// ��������ʵ��
CProjection::~CProjection()
{
    
}

// бͶӰ����ʵ��


// ����ͶӰ����ʵ��
CP2 CProjection::OrthogonalProjection(CP3 WorldPoint)
{
    CP2 ScreenPoint;
    ScreenPoint.x = WorldPoint.x;
    ScreenPoint.y = WorldPoint.y;
    return ScreenPoint;
}

CP3 CProjection::PerspectiveProjection3(CP3 WorldPoint)
{
    CP3 ViewPoint; // �۲�����ϵ��ά��
    ViewPoint.x = WorldPoint.x;
    ViewPoint.y = WorldPoint.y;
    ViewPoint.z = R - WorldPoint.z;
    ViewPoint.c = WorldPoint.c;

    CP3 ScreenPoint; // ��Ļ����ϵ��ά��
    ScreenPoint.x = d * ViewPoint.x / ViewPoint.z;
    ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
    ScreenPoint.z = (ViewPoint.z - d) * d / ViewPoint.z; // Bouknight��ʽ
    ScreenPoint.c = ViewPoint.c;

    return ScreenPoint;
}
CP3 CProjection::GetEye()
{
    return this->EyePoint;
}