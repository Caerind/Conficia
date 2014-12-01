#ifndef AM_AUDIOFILE_HPP
#define AM_AUDIOFILE_HPP

#include <SFML/Audio/SoundSource.hpp>
#include "Audio.hpp"

namespace am
{

class AudioManager;

class AudioFile : public sf::SoundSource
{
    public:
        typedef std::shared_ptr<AudioFile> Ptr;

    public:
        AudioFile(AudioManager* audioMgr, FileType type, std::string const& filename, std::string const& name = "");

        FileType getType() const;
        std::string getFilename() const;
        std::string getName() const;

        void play();

    private:
        AudioManager* mAudioManager;
        FileType mType;
        std::string mFilename;
        std::string mName;
};

}

#endif // AM_AUDIOFILE_HPP
