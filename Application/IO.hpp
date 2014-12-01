#ifndef APP_IO_HPP
#define APP_IO_HPP

#include <string>
#include <sstream>
#include <algorithm>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

namespace app
{

class IO
{
    public:
        //Rect
        template<typename T>
        static std::string toStr(sf::Rect<T> rect);

        template<typename T>
        static sf::Rect<T> toRect(std::string const& str);

        //Vector2
        template<typename T>
        static std::string toStr(sf::Vector2<T> vector);

        template<typename T>
        static sf::Vector2<T> toVector2(std::string const& str);

        //Vector3
        template<typename T>
        static std::string toStr(sf::Vector3<T> vector);

        template<typename T>
        static sf::Vector3<T> toVector3(std::string const& str);

        //Color
        static std::string toStr(sf::Color color);

        static sf::Color toColor(std::string const& str);

        static void toLowercase(std::string& str);
        static void toUppercase(std::string& str);

        template<typename T>
        static std::string toString(T const& value);

        template<typename T>
        static T fromString(std::string const& str);
};

template<typename T>
std::string IO::toStr(sf::Rect<T> rect)
{
    std::ostringstream oss;
    oss << rect.left << ";" << rect.top << ";" << rect.width << ";" << rect.height << ";";
    return oss.str();
}

template<typename T>
sf::Rect<T> IO::toRect(std::string const& str)
{
    sf::Rect<T> rect;
    std::string value;
    std::istringstream iss(str);

    std::getline(iss,value,';');
    rect.left = fromString<T>(value);

    std::getline(iss,value,';');
    rect.top = fromString<T>(value);

    std::getline(iss,value,';');
    rect.width = fromString<T>(value);

    std::getline(iss,value,';');
    rect.height = fromString<T>(value);

    return rect;
}

template<typename T>
std::string IO::toStr(sf::Vector2<T> vector)
{
    std::ostringstream oss;
    oss << vector.x << ";" << vector.y << ";";
    return oss.str();
}

template<typename T>
sf::Vector2<T> IO::toVector2(std::string const& str)
{
    sf::Vector2<T> vector;
    std::string value;
    std::istringstream iss(str);

    std::getline(iss,value,';');
    vector.x = fromString<T>(value);

    std::getline(iss,value,';');
    vector.y = fromString<T>(value);

    return vector;
}

template<typename T>
std::string IO::toStr(sf::Vector3<T> vector)
{
    std::ostringstream oss;
    oss << vector.x << ";" << vector.y << ";" << vector.z << ";";
    return oss.str();
}

template<typename T>
sf::Vector3<T> IO::toVector3(std::string const& str)
{
    sf::Vector3<T> vector;
    std::string value;
    std::istringstream iss(str);

    std::getline(iss,value,';');
    vector.x = fromString<T>(value);

    std::getline(iss,value,';');
    vector.y = fromString<T>(value);

    std::getline(iss,value,';');
    vector.z = fromString<T>(value);

    return vector;
}

template<typename T>
std::string IO::toString(T const& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
T IO::fromString(std::string const& str)
{
    std::istringstream iss(str);
    T dest;
    if (iss >> dest)
    {
        return dest;
    }
    return 0;
}

} // namespace app

#endif // APP_IO_HPP
