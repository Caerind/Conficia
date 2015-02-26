#ifndef CONFICIA_TRIGONOMETRY_HPP
#define CONFICIA_TRIGONOMETRY_HPP

#include <cmath>

namespace cf
{

float sin(float deg);
float cos(float deg);
float tan(float deg);
float asin(float value);
float acos(float value);
float atan2(float valY, float valX);
float pi();
float radToDeg(float rad);
float degToRad(float deg);

}

#endif // CONFICIA_TRIGONOMETRY_HPP
