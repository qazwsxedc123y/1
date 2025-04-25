#pragma once
#include "P2.h"
#include "Face.h"
class Cwindmill
{
private:
	int R, r;
	CP2 p[9];
	CFace F[5];
public:
	void SetParameter(int _R, int _r);
	void ReadFace();
	void Draw(CDC* pDC);
	void ReadPoint();
	CP2* GetPoint();
};

