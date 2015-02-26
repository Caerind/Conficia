#include "../include/Clock.hpp"

namespace cf
{

Clock::Clock()
{
    update();
}

int Clock::getTimeSecond()
{
    update();
    return getHour() * 3600 + getMinute() * 60 + getSecond();
}

std::string Clock::getTime()
{
    update();
    return std::string(std::to_string(getHour()) + ":" + std::to_string(getMinute()) + ":" + std::to_string(getSecond()));
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

}
