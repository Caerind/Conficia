#include "Clock.hpp"

namespace app
{

Clock::Clock()
{
    update(); // Load it for the first time
}

void Clock::update()
{
    time_t rawtime;
    time(&rawtime);
    struct tm* timeInfo;
    timeInfo = localtime(&rawtime);
    strftime(mHour,5,"%H",timeInfo);
    strftime(mMinute,5,"%M",timeInfo);
    strftime(mSecond,5,"%S",timeInfo);
}

int Clock::getHour() const
{
    return IO::fromString<int>(mHour);
}

int Clock::getMinute() const
{
    return IO::fromString<int>(mMinute);
}

int Clock::getSecond() const
{
    return IO::fromString<int>(mSecond);
}

int Clock::getSecondTotal() const
{
    return getHour() * 3600 + getMinute() * 60 + getSecond();
}

std::string Clock::getString() const
{
    std::ostringstream ss;
    ss << mHour << ":" << mMinute << ":" << mSecond;
    return ss.str();
}

} // namespace app
