#include "Properties.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Properties::Properties()
{
}

////////////////////////////////////////////////////////////
int Properties::getInt(std::string const& name)
{
    return toNumber<int>(mProperties[name]);
}

////////////////////////////////////////////////////////////
float Properties::getFloat(std::string const& name)
{
    return toNumber<float>(mProperties[name]);;
}

////////////////////////////////////////////////////////////
std::string Properties::getString(std::string const& name)
{
    return mProperties[name];
}

////////////////////////////////////////////////////////////
bool Properties::getBool(std::string const& name)
{
    return toBool(mProperties[name]);
}

////////////////////////////////////////////////////////////
std::map<std::string,std::string> Properties::getProperties() const
{
    return mProperties;
}

////////////////////////////////////////////////////////////
bool Properties::hasProperty(std::string const& name) const
{
    return mProperties.find(name) != mProperties.end();
}

////////////////////////////////////////////////////////////
bool Properties::isEmpty() const
{
    return mProperties.empty();
}

////////////////////////////////////////////////////////////
int Properties::getPropertyCount() const
{
    return mProperties.size();
}

////////////////////////////////////////////////////////////
Properties::Property Properties::getProperty(int id) const
{
    if (id < 0 || id >= getPropertyCount())
    {
        return Properties::Property("","");
    }
    int i = 0;
    for (auto itr = mProperties.begin(); itr != mProperties.end(); itr++)
    {
        if (id == i)
        {
            return Properties::Property(itr->first,itr->second);
        }
        i++;
    }
    return Properties::Property("","");
}

////////////////////////////////////////////////////////////
void Properties::setProperty(std::string const& name, int value)
{
    mProperties[name] = toString<int>(value);
}

////////////////////////////////////////////////////////////
void Properties::setProperty(std::string const& name, float value)
{
    mProperties[name] = toString<float>(value);
}

////////////////////////////////////////////////////////////
void Properties::setProperty(std::string const& name, std::string value)
{
    mProperties[name] = value;
}

////////////////////////////////////////////////////////////
void Properties::setProperty(std::string const& name, bool value)
{
    mProperties[name] = toString(value);
}

////////////////////////////////////////////////////////////
void Properties::setProperty(Property property)
{
    mProperties.insert(property);
}

////////////////////////////////////////////////////////////
void Properties::setProperties(std::map<std::string,std::string> properties)
{
    mProperties = properties;
}

////////////////////////////////////////////////////////////
bool Properties::toBool(std::string const& value)
{
    return (value == "true");
}

////////////////////////////////////////////////////////////
std::string Properties::toString(bool boolean)
{
    return (boolean) ? "true" : "false";
}

} // namespace tme
