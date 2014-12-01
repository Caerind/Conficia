#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer()
{
    //ctor
}

SoundPlayer::SoundPtr SoundPlayer::play(std::string const& filename)
{
    if(!mBuffers.isLoaded(filename))
    {
        if(!mBuffers.load(filename))
        {
            return nullptr;
        }
    }
    SoundPtr sound(new sf::Sound);
    auto itr = mSounds.emplace(filename,std::move(sound));
    itr->second->setBuffer(mBuffers.get(filename));
    itr->second->play();
    return itr->second;
}

void SoundPlayer::stop()
{
    mSounds.clear();
}

void SoundPlayer::update()
{
    for(auto itr = mSounds.begin(); itr != mSounds.end(); ++itr)
    {
        if(itr->second->getStatus() == sf::Sound::Stopped)
        {
            mSounds.erase(itr);
        }
    }
}
