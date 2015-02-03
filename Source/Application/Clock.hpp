#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#include <string>

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

#endif // CLOCK_HPP
