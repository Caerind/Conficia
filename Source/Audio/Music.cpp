#include "Music.hpp"

namespace cf
{

Music::Music()
{
}

bool Music::openFromFile(std::string const& filename)
{
    if (sf::Music::openFromFile(filename))
    {
        mFilename = filename;
        return true;
    }
    return false;
}

bool Music::play(std::string const& filename, unsigned int times)
{
    if (openFromFile(filename))
    {
        sf::Music::play();
        mTimesLeft = times;
        return true;
    }
    return false;
}

bool Music::play(unsigned int times)
{
    if (mFilename != "")
    {
        if (sf::Music::openFromFile(mFilename))
        {
            mTimesLeft = times;
            return true;
        }
    }
    return false;
}

void Music::stop()
{
    sf::Music::stop();
    mTimesLeft = 0;
}

void Music::update()
{
    if (getStatus() == sf::Music::Stopped && mTimesLeft > 0)
    {
        mTimesLeft--;
        if (mTimesLeft > 0)
        {
            play();
        }
    }
}

unsigned int Music::getTimesLeft() const
{
    return mTimesLeft;
}

void Music::setFilename(std::string const& filename)
{
    mFilename = filename;
}

std::string Music::getFilename() const
{
    return mFilename;
}

}
