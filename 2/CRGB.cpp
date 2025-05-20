#include "pch.h"
#include "CRGB.h"
CRGB::CRGB()
{
    red = 1.0;
    green = 1.0;
    blue = 1.0;
}
CRGB::~CRGB()
{
}
CRGB::CRGB(double red, double green, double blue, double alpha)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}
void CRGB::Normalize(void)
{
    red = (red < 0.0) ? 0.0 : ((red > 1.0) ? 1.0 : red);
    green = (green < 0.0) ? 0.0 : ((green > 1.0) ? 1.0 : green);
    blue = (blue < 0.0) ? 0.0 : ((blue > 1.0) ? 1.0 : blue);
}
CRGB operator * (double scalar, const CRGB& c)
{
    CRGB color;
    color.red = scalar * c.red;
    color.green = scalar * c.green;
    color.blue = scalar * c.blue;
    return color;
}
CRGB operator + (const CRGB& c0, const CRGB& c1)
{
    CRGB color;
    color.red = c0.red + c1.red;
    color.green = c0.green + c1.green;
    color.blue = c0.blue + c1.blue;
    return color;
}