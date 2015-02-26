#ifndef CONFICIA_STOPWATCH_HPP
#define CONFICIA_STOPWATCH_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace cf
{

class StopWatch
{
	public:
		StopWatch();

		sf::Time getElapsedTime() const;

		bool isRunning() const;

		void start();
		void stop();

		// Resets the stopwatch's elapsed time to zero and stops it.
		void reset();

		// Resets the stopwatch's elapsed time to zero and starts it again.
		void restart();

    private:
		sf::Clock					mClock;
		sf::Time					mTimeBuffer;
		bool						mRunning;
};

}

#endif // CONFICIA_STOPWATCH_HPP
