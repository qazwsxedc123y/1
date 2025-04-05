#include "pch.h"
#include "Cwindmill.h"
#define ARA(angle) ((angle) * 3.1415926 / 180.0)

void Cwindmill::ReadPoint()
{
	double angle = 0;
	p[0] = CP2(0, 0);
	for (int i = 0; i < 9; i++)
	{
		if (i % 2 != 0)
		{
			p[i] = CP2(r * cos(ARA(angle)), r * sin(ARA(angle)));
		}
		else
		{
			p[i] = CP2(R * cos(ARA(angle)), R * sin(ARA(angle)));
		}
		if (i % 2 == 0)
		{
			angle += 90;
		}
	}
}

CP2* Cwindmill::GetPoint()
{
	return p;
}

void Cwindmill::SetParameter(int _R, int _r) 
{
	R = _R;
	r = _r;
}

void Cwindmill::ReadFace() 
{
	CP2* points = GetPoint();
	for (int i = 0; i < 4; ++i) 
	{
		int startIndex = i * 2;
		CFace face;
		// 假设CFace类的SetVertices函数用于设置面的顶点
		face.SetVertices(points[startIndex], points[startIndex + 1],
			points[(startIndex + 2) % 8], points[(startIndex + 3) % 8]);
		F[i] = face;
	}
}

void Cwindmill::Draw(CDC* pDC)
{
	for (int i = 0; i < 4; ++i)
	{
		F[i].Draw(pDC);
	}
}