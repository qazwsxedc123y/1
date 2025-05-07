#pragma once
#include "CP3.h"
#include "CFace.h"
#include "CProjection.h"
class CCube
{
public:
	CCube();
	~CCube();
	void ReadPoint();
	void ReadFacet();
	CP3* GetVertexArrayName();
	void Draw(CDC* pDC);

private:
	CP3 P[8];
	CFace F[6];
};

