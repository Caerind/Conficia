#include "Clock.hpp"

Clock::Clock()
{
    update();
}

int Clock::getTime()
{
    update();
    return getHour() * 3600 + getMinute() * 60 + getSecond();
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

int Clock::getHour()
{
    return std::stoi(mHour);
}

int Clock::getMinute()
{
    return std::stoi(mMinute);
}

int Clock::getSecond()
{
    return std::stoi(mSecond);
}
