#ifndef APP_VERSION_HPP
#define APP_VERSION_HPP

#include "IO.hpp"

namespace app
{

class Version
{
    public:
        Version(unsigned int major = 0, unsigned int minor = 0);

        void setMajor(unsigned int major);
        void setMinor(unsigned int minor);

        unsigned int getMajor() const;
        unsigned int getMinor() const;

        std::string toString() const;
        unsigned int toIntegrer() const;

    protected:
        unsigned int mMajor;
        unsigned int mMinor;
};

} // namespace app

#endif // APP_VERSION_HPP
