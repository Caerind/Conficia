#ifndef CONFICIA_LANG_HPP
#define CONFICIA_LANG_HPP

#include <fstream>
#include <map>
#include <string>

namespace cf
{

class Lang
{
    public:
        Lang();

        bool loadFromFile(std::string const& filename);

        std::string getValue(std::string const& index);

        std::string getLang();

    protected:
        std::string mLang;
        std::map<std::string,std::string> mValues;
};

}

#endif // CONFICIA_LANG_HPP
