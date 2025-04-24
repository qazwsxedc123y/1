#pragma once
#include "CP3.h"
#include "CVector3.h"
class CFace
{
public:
	CFace();
	~CFace();
	void SetFaceNormal(CP3 p1, CP3 p2, CP3 p3);
public:
	int Number;
	int Index[4];
	CVector3 fNormal;
};

