#include "Sound.hpp"
#include "SoundManager.hpp"

namespace cf
{

Sound::Sound() : sf::Sound(), mManager(nullptr)
{
}

Sound::Sound(SoundManager* manager) : sf::Sound(), mManager(manager)
{
}

Sound::~Sound()
{
    mManager = nullptr;
}

bool Sound::play(std::string const& filename)
{
    if (mManager != nullptr)
    {
        sf::SoundBuffer* buffer = mManager->getBuffer(filename);
        if (buffer != nullptr)
        {
            setBuffer(*buffer);
            sf::Sound::play();
            return true;
        }
    }
    return false;
}

void Sound::setManager(SoundManager* manager)
{
    mManager = manager;
}

SoundManager* Sound::getManager() const
{
    return mManager;
}

}
