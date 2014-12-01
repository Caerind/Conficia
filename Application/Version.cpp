#include "Version.hpp"

namespace app
{

Version::Version(unsigned int major, unsigned int minor)
: mMajor(major)
, mMinor(minor)
{
}

void Version::setMajor(unsigned int major)
{
    mMajor = major;
}

void Version::setMinor(unsigned int minor)
{
    mMinor = minor;
}

unsigned int Version::getMajor() const
{
    return mMajor;
}

unsigned int Version::getMinor() const
{
    return mMinor;
}

std::string Version::toString() const
{
    return std::string(IO::toString(mMajor) + "." + IO::toString(mMinor));
}

unsigned int Version::toIntegrer() const
{
    return 100 * mMajor + mMinor;
}

} // namespace app
