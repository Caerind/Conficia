#include "Random.hpp"

namespace cf
{

std::mt19937 globalEngine(static_cast<unsigned long>(std::time(nullptr)));

int random(int min, int max)
{
	assert(min <= max);
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(globalEngine);
}

unsigned int random(unsigned int min, unsigned int max)
{
	assert(min <= max);
	std::uniform_int_distribution<unsigned int> distribution(min, max);
	return distribution(globalEngine);
}

float random(float min, float max)
{
	assert(min <= max);
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(globalEngine);
}

float randomDev(float middle, float deviation)
{
	assert(deviation >= 0.f);
	return random(middle-deviation, middle+deviation);
}

}
