#ifndef CONFICIA_VECTOR_HPP
#define CONFICIA_VECTOR_HPP

#include <SFML/System/Vector2.hpp>
#include "Trigonometry.hpp"

namespace cf
{

float length(sf::Vector2f v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

float distance(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::sqrt((v2.x-v1.x) * (v2.x-v1.x) + (v2.y-v1.y) * (v2.y-v1.y));
}

void rotate(sf::Vector2f& v, float deg)
{
    float c = cf::cos(deg);
    float s = cf::sin(deg);
    v = sf::Vector2f(c * v.x - s * v.y, s * v.x + c * v.y);
}

}

#endif // CONFICIA_VECTOR_HPP
