#include "StopWatch.hpp"

namespace cf
{

StopWatch::StopWatch()
: mClock()
, mTimeBuffer(sf::Time::Zero)
, mRunning(false)
{
}

sf::Time StopWatch::getElapsedTime() const
{
	if (mRunning)
		return mTimeBuffer + mClock.getElapsedTime();
	else
		return mTimeBuffer;
}

bool StopWatch::isRunning() const
{
	return mRunning;
}

void StopWatch::start()
{
	if (!mRunning)
	{
		mRunning = true;
		mClock.restart();
	}
}

void StopWatch::stop()
{
	if (mRunning)
	{
		mRunning = false;
		mTimeBuffer += mClock.getElapsedTime();
	}
}

void StopWatch::reset()
{
	mTimeBuffer = sf::Time::Zero;
	mRunning = false;
}

void StopWatch::restart()
{
	reset();
	start();
}

}
