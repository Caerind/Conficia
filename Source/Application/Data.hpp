#ifndef DATA_HPP
#define DATA_HPP

#include <map>
#include <string>

class Data
{
    public:
        Data();

        void set(std::string const& id, std::string const& data);
        std::string get(std::string const& id);

    protected:
        std::map<std::string,std::string> mData;
};

#endif // DATA_HPP
