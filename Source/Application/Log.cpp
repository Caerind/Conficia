#include "Log.hpp"
#include "Application.hpp"

namespace cf
{

Log::Log()
{
    mType = Log::INFO;
}

Log::~Log()
{
    if (mFile.is_open())
    {
        mFile.close();
    }
}

bool Log::openFile(std::string const& filename)
{
    mFile.open(filename);
    if (!mFile)
    {
        return false;
    }
    return true;
}

void Log::logTime()
{
    mFile << "[" << std::to_string(Application::getClock().getTime()) << "]";
}

void Log::logType()
{
    switch (mType)
    {
        case Log::ERROR:
            mFile << "[ERROR]: ";
            break;

        case Log::WARNING:
            mFile << "[WARNING]: ";
            break;

        default:
            mFile << "[INFO]: ";
            break;
    }
}

void Log::logText(std::string const& text)
{
    mFile << text;
}

}
