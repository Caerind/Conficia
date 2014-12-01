#ifndef APP_MATH_HPP
#define APP_MATH_HPP

#include <cmath>
#include <random>
#include <ctime>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transformable.hpp>

#define PI 3.14159265

namespace app
{

class Math
{
    protected:
        typedef std::mt19937 Engine;
        static Engine mEngine;
        static Engine createEngine();

    public:
        template<typename T>
        static T random(T min, T max);

        template<typename T>
        static sf::Vector2<T> random(T minX, T maxX, T minY, T maxY);

        template<typename T>
        static sf::Vector2<T> random(sf::Rect<T> rect);

        template<typename T>
        static std::vector<T> random(unsigned int size, T min, T max);

        static float distance(sf::Transformable const& a, sf::Transformable const& b);
        static float distance(sf::Vector2f const& a, sf::Vector2f const& b);


        static sf::Vector2f normalize(sf::Vector2f const& vector);

        static float dotProduct(sf::Vector2f const& a, sf::Vector2f const& b);

        static float toRadians(float const& deg);

        static float toDegrees(float const& rad);
};

template<typename T>
T Math::random(T min, T max)
{
    if (min <= max)
    {
        std::uniform_real_distribution<float> distribution(min, max);
        return distribution(mEngine);
    }
    else
    {
        std::uniform_real_distribution<float> distribution(max, min);
        return distribution(mEngine);
    }
}

template<typename T>
sf::Vector2<T> Math::random(T minX, T maxX, T minY, T maxY)
{
    return sf::Vector2<T>(random<T>(minX,maxX),random<T>(minY,maxY));
}

template<typename T>
sf::Vector2<T> Math::random(sf::Rect<T> rect)
{
    return sf::Vector2<T>(random<T>(rect.left,rect.left+rect.width),random<T>(rect.top,rect.top+rect.height));
}

template<typename T>
std::vector<T> Math::random(unsigned int size, T min, T max)
{
    std::vector<T> tabelems;
    std::vector<T> ret;
    unsigned int maxi = static_cast<unsigned int>(max - min);
    if(min >= max || size > maxi + 1 || size < 1)
        return ret;
    tabelems.resize(maxi + 1);
    ret.resize(size);
    for(unsigned int i = 0; i < maxi + 1; i++)
    {
        tabelems[i] = i + min;
    }
    for(unsigned int i = 0; i < size; i++)
    {
        unsigned int indice = random<unsigned int>(0,maxi + 2);
        ret[i] = tabelems[indice];
        tabelems[indice] = tabelems[maxi];
        maxi--;
    }
    tabelems.clear();
    return ret;
}

} // namespace app

#endif // APP_MATH_HPP
