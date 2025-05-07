#include "pch.h"
#include "CProjection.h"


CProjection::CProjection()
{
	R = 1200;
	d = 800;
	EyePoint.x = 0;
	EyePoint.y = 0;
	EyePoint.z = R;
}
CProjection::~CProjection()
{

}
CP2 CProjection::obliqueProjection(CP3 worldPoint)
{
	CP2 ScreenPoint;
	ScreenPoint.x = worldPoint.x - 0.3536 * worldPoint.z;
	ScreenPoint.y = worldPoint.y - 0.3536 * worldPoint.z;
	return ScreenPoint;
}
CP2 CProjection::orthogonalProjection(CP3 worldPoint)
{
	CP2 ScreenPoint;
	ScreenPoint.x = worldPoint.x;
	ScreenPoint.y = worldPoint.y;
	return ScreenPoint;
}
CP2 CProjection::PerspectiveProjection(CP3 WorldPoint)
{
	CP3 ViewPoint;
	ViewPoint.x = WorldPoint.x;
	ViewPoint.y = WorldPoint.y;
	ViewPoint.z = EyePoint.z - WorldPoint.z;

	CP2 ScreenPoint;
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z;
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
	return ScreenPoint;
}