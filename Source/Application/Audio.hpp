#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <string>

#include "../Audio/Playlist.hpp"
#include "../Audio/SoundManager.hpp"

class Audio
{
    public:
        Audio();

        void update();

        void playSound(std::string const& filename);
        void playMusic(std::string const& filename);

        Playlist& getPlaylist();
        SoundManager& getSoundManager();

    protected:
        Playlist mPlaylist;
        SoundManager mSounds;
};

#endif // AUDIO_HPP
