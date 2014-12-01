#ifndef APP_CLOCK_HPP
#define APP_CLOCK_HPP

#include <ctime>
#include <sstream>

#include "IO.hpp"

namespace app
{

class Clock
{
    public:
        Clock();

        void update();

        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        int getSecondTotal() const;

        std::string getString() const;

    protected:
        char mHour[5];
        char mMinute[5];
        char mSecond[5];
};

} // namespace app

#endif // APP_CLOCK_HPP
