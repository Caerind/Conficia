#include "Audio.hpp"
#include "Application.hpp"

Audio::Audio()
{
}

void Audio::update()
{
    mPlaylist.update();
    mSounds.update();
}

void Audio::playSound(std::string const& filename)
{
    if (!mSounds.play(filename))
    {
        Application::getLog() << Log::ERROR << std::string("Failed to play Sound : " + filename);
    }
}

void Audio::playMusic(std::string const& filename)
{
    if (!mPlaylist.play(filename))
    {
        Application::getLog() << Log::ERROR << std::string("Failed to play Music : " + filename);
    }
}

Playlist& Audio::getPlaylist()
{
    return mPlaylist;
}

SoundManager& Audio::getSoundManager()
{
    return mSounds;
}
