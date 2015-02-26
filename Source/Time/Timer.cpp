#include "Timer.hpp"

#include <algorithm>
#include <cassert>

namespace cf
{

Timer::Timer()
: mStopWatch()
, mLimit(sf::Time::Zero)
{
}

Timer::~Timer()
{
}

sf::Time Timer::getRemainingTime() const
{
	return std::max(mLimit - mStopWatch.getElapsedTime(), sf::Time::Zero);
}

bool Timer::isRunning() const
{
	return mStopWatch.isRunning() && !isExpired();
}

bool Timer::isExpired() const
{
	return mStopWatch.getElapsedTime() >= mLimit;
}

void Timer::start()
{
	mStopWatch.start();
}

void Timer::stop()
{
	mStopWatch.stop();
}

void Timer::reset(sf::Time timeLimit)
{
	assert(timeLimit > sf::Time::Zero);

	mLimit = timeLimit;
	mStopWatch.reset();
}

void Timer::restart(sf::Time timeLimit)
{
	reset(timeLimit);
	start();
}

}
