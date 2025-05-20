#include "pch.h"
#include "CFace.h"
CFace::CFace()
{
	fNormal = CVector3(CP3(0.0, 0.0, 1.0));
}

CFace::~CFace()
{
}
void CFace::SetFaceNormal(CP3 pt0, CP3 pt1, CP3 pt2)
{
    CVector3 V01(pt0, pt1);
    CVector3 V02(pt0, pt2);
    this->fNormal = CrossProduct(V01, V02);
}