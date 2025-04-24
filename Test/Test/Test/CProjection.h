#pragma once
#include "CP2.h"
#include "CP3.h"
class CProjection
{
public:
	CProjection();
	~CProjection();
	CP2 obliqueProjection(CP3 worldPoint);
	CP2 orthogonalProjection(CP3 worldPoint);
	CP2 PerspectiveProjection(CP3 WorldPoint);//Õ∏ ”Õ∂”∞

public:
	CP3 EyePoint;
	double R, d;
};

