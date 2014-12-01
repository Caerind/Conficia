#include "../include/AudioManager.hpp"
#include "../include/AudioFile.hpp"

namespace am
{

AudioManager::AudioManager()
{
    //ctor
}

AudioFile::Ptr AudioManager::create(FileType type, std::string const& filename, std::string const& name)
{
    AudioFile::Ptr audioFile = std::make_shared<AudioFile>(this,type,filename,name);
    mFiles[audioFile->getName()] = audioFile;
    return audioFile;
}

AudioFile::Ptr AudioManager::createSound(std::string const& filename, std::string const& name)
{
    AudioFile::Ptr audioFile = std::make_shared<AudioFile>(this,FileType::Sound,filename, name);
    mFiles[audioFile->getName()] = audioFile;
    return audioFile;
}

AudioFile::Ptr AudioManager::createMusic(std::string const& filename, std::string const& name)
{
    AudioFile::Ptr audioFile = std::make_shared<AudioFile>(this,FileType::Music,filename,name);
    mFiles[audioFile->getName()] = audioFile;
    return audioFile;
}

AudioFile::Ptr AudioManager::createAuto(std::string const& filename, std::string const& name)
{
    sf::Music musicDuration;
    if (!music.openFromFile(filename))
        return nullptr;
    if (music.getDuration() < sf::seconds(10))
        return createSound(filename,name);
    else
        return createMusic(filename,name);
}

bool AudioManager::remove(AudioFile::Ptr file)
{
    for(auto itr = mFiles.begin(); itr != mFiles.end(); itr++)
    {
        if(file == itr->second)
        {
            mFiles.erase(itr);
            return true;
        }
    }
    return false;
}

bool AudioManager::remove(std::string const& name)
{
    for(auto itr = mFiles.begin(); itr != mFiles.end(); itr++)
    {
        if(name == itr->first)
        {
            mFiles.erase(itr);
            return true;
        }
    }
    return false;
}

bool AudioManager::play(AudioFile::Ptr file)
{
    if(file->getType() == FileType::Sound)
    {
        if(!mBuffers.isLoaded(file->getFilename()))
        {
            if(!mBuffers.load(file->getFilename()))
            {
                return false;
            }
        }
        SoundPtr sound(new sf::Sound);
        auto itr = mSounds.emplace(file->getName(),std::move(sound));
        itr->second->setBuffer(mBuffers.get(file->getFilename()));

        itr->second->setPitch(file->getPitch());
        itr->second->setVolume(file->getVolume());
        itr->second->setPosition(file->getPosition());
        itr->second->setMinDistance(file->getMinDistance());
        itr->second->setAttenuation(file->getAttenuation());
        itr->second->setRelativeToListener(file->isRelativeToListener());

        itr->second->play();
    }
    else if(file->getType() == FileType::Music)
    {
        MusicPtr music(new sf::Music);
        auto itr = mMusics.emplace(file->getName(),std::move(music));
        if(!itr->second->openFromFile(file->getFilename()))
            return false;

        itr->second->setPitch(file->getPitch());
        itr->second->setVolume(file->getVolume());
        itr->second->setPosition(file->getPosition());
        itr->second->setMinDistance(file->getMinDistance());
        itr->second->setAttenuation(file->getAttenuation());
        itr->second->setRelativeToListener(file->isRelativeToListener());

        itr->second->play();
    }
    else
    {
        return false;
    }
    return true;
}

bool AudioManager::play(std::string const& name)
{
    for(auto f : mFiles)
    {
        if(f.first == name)
        {
            return play(f.second);
        }
    }
    return false;
}

bool AudioManager::playSound(std::string const& filename)
{
    if(!mBuffers.isLoaded(filename))
    {
        if(!mBuffers.load(filename))
        {
            return false;
        }
    }
    SoundPtr sound(new sf::Sound);
    auto itr = mSounds.emplace(filename,std::move(sound));
    itr->second->setBuffer(mBuffers.get(filename));
    itr->second->play();
    return true;
}

bool AudioManager::playMusic(std::string const& filename)
{
    MusicPtr music(new sf::Music);
    auto itr = mMusics.emplace(filename,std::move(music));
    if(!itr->second->openFromFile(filename))
        return false;
    itr->second->play();
    return true;
}

void AudioManager::stop()
{
    mMusics.clear();
    mSounds.clear();
}

void AudioManager::update()
{
    for(auto itr = mMusics.begin(); itr != mMusics.end(); ++itr)
    {
        if(itr->second->getStatus() == sf::Music::Stopped)
        {
            mMusics.erase(itr);
        }
    }

    for(auto itr = mSounds.begin(); itr != mSounds.end(); ++itr)
    {
        if(itr->second->getStatus() == sf::Sound::Stopped)
        {
            mSounds.erase(itr);
        }
    }
}

}
