#include "../include/AudioBufferManager.hpp"

namespace am
{

AudioBufferManager::AudioBufferManager()
{
    //ctor
}

bool AudioBufferManager::load(std::string const& name)
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

sf::SoundBuffer& AudioBufferManager::get(std::string const& name)
{
    if(!isLoaded(name))
    {
        load(name);
    }
    return mBuffers[name];
}

bool AudioBufferManager::isLoaded(std::string const& name)
{
    return mBuffers.find(name) != mBuffers.end();
}

void AudioBufferManager::unload(std::string const& name)
{
    if(isLoaded(name))
    {
        mBuffers.erase(mBuffers.find(name));
    }
}

void AudioBufferManager::unload()
{
    mBuffers.clear();
}

}
