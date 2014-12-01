#include "../include/AudioFile.hpp"
#include "../include/AudioManager.hpp"

namespace am
{

AudioFile::AudioFile(AudioManager* audioMgr, FileType type, std::string const& filename, std::string const& name)
: mAudioManager(audioMgr)
, mType(type)
, mFilename(filename)
, mName(name)
{
    if(name == "")
    {
        mName = filename;
    }
}

FileType AudioFile::getType() const
{
    return mType;
}

std::string AudioFile::getFilename() const
{
    return mFilename;
}

std::string AudioFile::getName() const
{
    return mName;
}

void AudioFile::play()
{
    mAudioManager->play(std::make_shared<AudioFile>(*this));
}

}
