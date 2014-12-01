#include "IO.hpp"

namespace app
{

std::string IO::toStr(sf::Color color)
{
    std::ostringstream oss;
    oss << color.r << ";" << color.g << ";" << color.b << ";" << color.a;
    return oss.str();
}

sf::Color IO::toColor(std::string const& str)
{
    sf::Color color;
    std::string value;
    std::istringstream iss(str);

    std::getline(iss,value,';');
    color.r = fromString<float>(value);

    std::getline(iss,value,';');
    color.g = fromString<float>(value);

    std::getline(iss,value,';');
    color.b = fromString<float>(value);

    std::getline(iss,value,';');
    color.a = fromString<float>(value);

    return color;
}

void IO::toLowercase(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void IO::toUppercase(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

} // namespace app
