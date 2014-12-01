#ifndef AM_AUDIOMANAGER_HPP
#define AM_AUDIOMANAGER_HPP

#include <map>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Audio.hpp"
#include "AudioBufferManager.hpp"
#include "AudioFile.hpp"

namespace am
{

typedef std::shared_ptr<AudioFile> AudioFilePtr;

class AudioManager
{
    public:
        AudioManager();

        // mFiles
        AudioFilePtr create(FileType type, std::string const& filename, std::string const& name = "");
        AudioFilePtr createSound(std::string const& filename, std::string const& name = "");
	AudioFilePtr createMusic(std::string const& filename, std::string const& name = "");
	AudioFilePtr createAuto(std::string const& filename, std::string const& name = "");
	bool remove(AudioFilePtr file);
        bool remove(std::string const& name);

        // Audio
        bool play(AudioFilePtr file);
        bool play(std::string const& name);
        bool playSound(std::string const& filename);
        bool playMusic(std::string const& filename);

        void stop();

        void update();

    private:
        std::map<std::string,AudioFilePtr> mFiles;
        std::multimap<std::string,MusicPtr> mMusics;
        std::multimap<std::string,SoundPtr> mSounds;
        AudioBufferManager mBuffers;
};

}

#endif // AM_AUDIOMANAGER_HPP
