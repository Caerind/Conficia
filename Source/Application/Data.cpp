#include "Data.hpp"

Data::Data()
{
}

void Data::set(std::string const& id, std::string const& data)
{
    mData[id] = data;
}

std::string Data::get(std::string const& id)
{
    return mData[id];
}

