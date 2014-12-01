#include "Log.hpp"

namespace app
{

Log::Log(std::string const& filename)
{
    mFile.open(filename);
    if (mFile.is_open())
    {
        mFile << "---------------------------------------" << std::endl << std::endl;
    }
}

Log::~Log()
{
    if (mFile.is_open())
    {
        mFile.close();
    }
}

} // namespace app
