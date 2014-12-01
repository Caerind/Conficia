#include "Math.hpp"

namespace app
{

std::mt19937 Math::mEngine = createEngine();

Math::Engine Math::createEngine()
{
    return Engine(static_cast<unsigned long>(std::time(nullptr)) );
}

float Math::distance(sf::Transformable const& a, sf::Transformable const& b)
{
    return sqrt((a.getPosition().x-b.getPosition().x)*(a.getPosition().x-b.getPosition().x)+(a.getPosition().y-b.getPosition().y)*(a.getPosition().y-b.getPosition().y));
}

float Math::distance(sf::Vector2f const& a, sf::Vector2f const& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

sf::Vector2f Math::normalize(sf::Vector2f const& vect)
{
    float magnitude = sqrt((vect.x*vect.x)+(vect.y*vect.y));
    sf::Vector2f normal =sf::Vector2f(vect.x/magnitude,vect.y/magnitude);
    return normal;
}

float Math::dotProduct(sf::Vector2f const& a, sf::Vector2f const& b)
{
    return ((a.x*b.x)+(a.y*b.y));
}

float Math::toRadians(float const& deg)
{
    return deg * PI / 180;
}

float Math::toDegrees(float const& rad)
{
    return rad * 180 / PI;
}

} // namespace app
