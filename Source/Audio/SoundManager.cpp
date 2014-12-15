#include "SoundManager.hpp"
#include "Sound.hpp"

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
    mSounds.clear();
}

sf::SoundBuffer* SoundManager::getBuffer(std::string const& filename)
{
    if (hasBuffer(filename))
    {
        return &mBuffers[filename];
    }
    else
    {
        if (loadBuffer(filename))
        {
            return &mBuffers[filename];
        }
    }
    return nullptr;
}

bool SoundManager::loadBuffer(std::string const& filename)
{
    if (hasBuffer(filename))
    {
        return true;
    }
    else
    {
        return mBuffers[filename].loadFromFile(filename);
    }
}

bool SoundManager::hasBuffer(std::string const& filename)
{
    if (mBuffers.find(filename) != mBuffers.end())
    {
        return true;
    }
    return false;
}

bool SoundManager::play(std::string const& filename)
{
    if (!hasBuffer(filename))
    {
        if (!loadBuffer(filename))
        {
            return false;
        }
    }
    else
    {
        std::unique_ptr<Sound> s(new Sound(this));
        s->play(filename);
        mSounds.push_back(std::move(s));
        return true;
    }
    return false;
}

void SoundManager::update()
{
    unsigned int i = 0;
    for (unsigned int j = 0; j < mSounds.size(); j++)
    {
        if (mSounds[j]->getStatus() == sf::Sound::Stopped)
        {
            i++;
        }
    }
    if (i == mSounds.size())
    {
        mSounds.clear();
    }
}
