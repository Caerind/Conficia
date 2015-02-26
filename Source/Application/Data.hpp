#ifndef CONFICIA_DATA_HPP
#define CONFICIA_DATA_HPP

#include <map>
#include <string>

namespace cf
{

class Data
{
    public:
        Data();

        void set(std::string const& id, std::string const& data);
        std::string get(std::string const& id);

    protected:
        std::map<std::string,std::string> mData;
};

}

#endif // CONFICIA_DATA_HPP
