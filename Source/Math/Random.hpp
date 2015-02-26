#ifndef CONFICIA_RANDOM_HPP
#define CONFICIA_RANDOM_HPP

#include <random>
#include <ctime>
#include <cassert>

namespace cf
{

int random(int min, int max);

unsigned int random(unsigned int min, unsigned int max);

float random(float min, float max);

float randomDev(float middle, float deviation);

}

#endif // CONFICIA_RANDOM_HPP
