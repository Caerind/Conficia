#ifndef TME_PROPERTIES_HPP
#define TME_PROPERTIES_HPP

#include <map>
#include <string>
#include <sstream>

namespace tme
{

class Properties
{
    public:
        typedef std::pair<std::string,std::string> Property;

    public:
        Properties();

        int getInt(std::string const& name);
        float getFloat(std::string const& name);
        std::string getString(std::string const& name);
        bool getBool(std::string const& name);
        std::map<std::string,std::string> getProperties() const;

        bool hasProperty(std::string const& name) const;
        bool isEmpty() const;
        int getPropertyCount() const;
        Property getProperty(int id) const;

        void setProperty(std::string const& name, int value);
        void setProperty(std::string const& name, float value);
        void setProperty(std::string const& name, std::string value);
        void setProperty(std::string const& name, bool value);
        void setProperty(Property property);
        void setProperties(std::map<std::string,std::string> properties);

    public:
        template <typename T>
        static T toNumber(std::string const& value);
        static bool toBool(std::string const& value);

        template <typename T>
        static std::string toString(T number);
        static std::string toString(bool boolean);

    protected:
        std::map<std::string,std::string> mProperties;
};

////////////////////////////////////////////////////////////
template <typename T>
T Properties::toNumber(std::string const& value)
{
    T number;
    std::istringstream iss(value);
    iss >> number;
    return number;
}

////////////////////////////////////////////////////////////
template <typename T>
std::string Properties::toString(T number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

} // namespace tme

#endif // TME_PROPERTIES_HPP
