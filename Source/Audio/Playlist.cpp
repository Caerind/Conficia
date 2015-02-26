#include "Playlist.hpp"

namespace cf
{

Playlist::Playlist()
{
}

void Playlist::addFilename(std::string const& filename)
{
    mFilenames.push_back(filename);
}

bool Playlist::play(unsigned int index)
{
    if (index < mFilenames.size())
    {
        return play(mFilenames[index]);
    }
    return false;
}

std::string Playlist::getFilename(unsigned int index) const
{
    if (index < mFilenames.size())
    {
        return mFilenames[index];
    }
    return "";
}

bool Playlist::play(std::string const& filename)
{
    return mMusic.play(filename,1);
}

void Playlist::play()
{
    mMusic.play();
}

void Playlist::pause()
{
    mMusic.pause();
}

void Playlist::stop()
{
    mMusic.stop();
}

void Playlist::update()
{
    if (mMusic.getStatus() == sf::Music::Stopped && mFilenames.size() == 0)
    {
        mMusicPlayed++;
        if (mMusicPlayed >= mFilenames.size())
        {
            mMusicPlayed = 0;
            if (mLoop)
            {
                play(mMusicPlayed);
            }
        }
        else
        {
            play(mMusicPlayed);
        }
    }
}

void Playlist::setLoop(bool loop)
{
    mLoop = loop;
}

bool Playlist::isLoop() const
{
    return mLoop;
}

void Playlist::setPitch(float pitch)
{
    mMusic.setPitch(pitch);
}

void Playlist::setVolume(float volume)
{
    mMusic.setVolume(volume);
}

void Playlist::setPosition(sf::Vector3f position)
{
    mMusic.setPosition(position);
}

void Playlist::setRelativeToListener(bool relative)
{
    mMusic.setRelativeToListener(relative);
}

void Playlist::setMinDistance(float distance)
{
    mMusic.setMinDistance(distance);
}

void Playlist::setAttenuation(float attenuation)
{
    mMusic.setAttenuation(attenuation);
}

float Playlist::getPitch() const
{
    return mMusic.getPitch();
}

float Playlist::getVolume() const
{
    return mMusic.getVolume();
}

sf::Vector3f Playlist::getPosition() const
{
    return mMusic.getPosition();
}

bool Playlist::isRelativeToListener() const
{
    return mMusic.isRelativeToListener();
}

float Playlist::getMinDistance() const
{
    return mMusic.getMinDistance();
}

float Playlist::getAttenuation() const
{
    return mMusic.getAttenuation();
}

sf::SoundSource::Status Playlist::getStatus() const
{
    return mMusic.getStatus();
}

}
