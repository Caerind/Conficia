#include "SoundBufferManager.hpp"

SoundBufferManager::SoundBufferManager()
{
    //ctor
}

bool SoundBufferManager::load(std::string const& name)
{
    if(!isLoaded(name))
    {
        if(!mBuffers[name].loadFromFile(name))
        {
            return false;
        }
    }
    return true;
}

sf::SoundBuffer& SoundBufferManager::get(std::string const& name)
{
    if(!isLoaded(name))
    {
        load(name);
    }
    return mBuffers[name];
}

bool SoundBufferManager::isLoaded(std::string const& name)
{
    return mBuffers.find(name) != mBuffers.end();
}

void SoundBufferManager::unload(std::string const& name)
{
    if(isLoaded(name))
    {
        mBuffers.erase(mBuffers.find(name));
    }
}

void SoundBufferManager::unload()
{
    mBuffers.clear();
}
