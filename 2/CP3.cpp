#include "pch.h"
#include "CP3.h"
CP3::CP3()
{
x = 0, y = 0, z = 0, w = 1;
}

CP3::CP3(double x, double y, double z) :CP2(x, y)
{
	this->z = z;
}

CP3::~CP3()
{
}