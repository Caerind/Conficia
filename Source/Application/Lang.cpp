#include "Lang.hpp"
#include "Application.hpp"

Lang::Lang()
{
}

bool Lang::loadFromFile(std::string const& filename)
{
    mLang = filename.substr(0,filename.find(".")-1);

    std::ifstream file(filename);
    if (!file)
    {
        Application::getLog() << Log::ERROR << std::string("Failed to load lang : " + mLang);
        return false;
    }
    std::string line;
    while (std::getline(file,line))
    {
        std::size_t pos = line.find(":");
        if (pos != std::string::npos)
        {
            std::string id = line.substr(0,pos-1);
            std::string value = line.substr(pos+1,line.size());
            while (id.back() == ' ')
            {
                id.pop_back();
            }
            while (value.front() == ' ')
            {
                value = value.substr(1,value.size());
            }
            mValues[id] = value;
        }
    }
    file.close();
    return true;
}

std::string Lang::getValue(std::string const& index)
{
    if (mValues.find(index) == mValues.end())
    {
        Application::getLog() << Log::ERROR << std::string("Failed to find lang : " + index);
    }
    return mValues[index];
}

std::string Lang::getLang()
{
    return mLang;
}
