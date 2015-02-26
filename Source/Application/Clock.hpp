#ifndef CONFICIA_CLOCK_HPP
#define CONFICIA_CLOCK_HPP

#include <ctime>
#include <string>

namespace cf
{

class Clock
{
    public:
        Clock();

        int getTimeSecond();

        std::string getTime();

    protected:

        void update();

        int getHour();
        int getMinute();
        int getSecond();

        char mHour[5];
        char mMinute[5];
        char mSecond[5];
};

}

#endif // CONFICIA_CLOCK_HPP
