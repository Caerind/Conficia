#ifndef CONFICIA_TIMER_HPP
#define CONFICIA_TIMER_HPP

#include "StopWatch.hpp"

#include <SFML/System/Time.hpp>

namespace cf
{

class Timer
{
	public:
		Timer();

		virtual ~Timer();

		sf::Time getRemainingTime() const;
		bool isRunning() const;
		bool isExpired() const;

		void start();
		void stop();

		// Resets the timer's remaining time to the given limit and stops it.
		virtual void reset(sf::Time timeLimit);

		// Resets the timer's remaining time to the given limit and starts it again.
		virtual void restart(sf::Time timeLimit);

    private:
		StopWatch					mStopWatch;
		sf::Time					mLimit;
};

}

#endif // CONFICIA_TIMER_HPP
