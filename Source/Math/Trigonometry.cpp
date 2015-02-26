#include "Trigonometry.hpp"

namespace cf
{

float sin(float deg)
{
    return std::sin(degToRad(deg));
}

float cos(float deg)
{
    return std::cos(degToRad(deg));
}

float tan(float deg)
{
    return std::tan(degToRad(deg));
}

float asin(float value)
{
    return radToDeg(std::asin(value));
}

float acos(float value)
{
    return radToDeg(std::acos(value));
}

float atan2(float valY, float valX)
{
    return radToDeg(std::atan2(valY,valX));
}

float pi()
{
    return 3.141592653589793238462643383f;
}

float radToDeg(float rad)
{
    return 180 / pi() * rad;
}

float degToRad(float deg)
{
    return pi() / 180 * deg;
}

}
