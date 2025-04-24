#include "pch.h"
#include "CFace.h"

CFace::CFace()
{
	fNormal = CVector3(CP3(0.0, 0.0, 1.0));
}
CFace::~CFace() 
{

}

void CFace::SetFaceNormal(CP3 p1, CP3 p2, CP3 p3)
{
	CVector3 v01(p1, p2);
	CVector3 v02(p1, p3);
	this->fNormal = Cross(v01, v02);
}