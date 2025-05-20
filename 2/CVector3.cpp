#include "pch.h"
#include "CVector3.h"
CVector3::CVector3()
{
    x = 0.0;
    y = 0.0;
    z = 1.0;
}
CVector3::~CVector3()
{
    
}
CVector3::CVector3(const CP3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}
CVector3::CVector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
CVector3::CVector3(const CP3& p0, const CP3& p1)
{
    x = p1.x - p0.x;
    y = p1.y - p0.y;
    z = p1.z - p0.z;
}
double CVector3::Mag()
{
    return sqrt(x * x + y * y + z * z);
}
CVector3 CVector3::Normalize()
{
    CVector3 vector;
    double Mag = sqrt(x * x + y * y + z * z);
    if (fabs(Mag) < 1e-6)
        Mag = 1.0;
    vector.x = x / Mag;
    vector.y = y / Mag;
    vector.z = z / Mag;
    return vector;
}
double Dot(const CVector3& v0, const CVector3& v1)
{
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}
CVector3 CrossProduct(const CVector3& v0, const CVector3& v1)
{
    CVector3 vector;
    vector.x = v0.y * v1.z - v0.z * v1.y;
    vector.y = v0.z * v1.x - v0.x * v1.z;
    vector.z = v0.x * v1.y - v0.y * v1.x;
    return vector;
}