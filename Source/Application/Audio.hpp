#ifndef CONFICIA_AUDIO_HPP
#define CONFICIA_AUDIO_HPP

#include <string>

#include "../Audio/Playlist.hpp"
#include "../Audio/SoundManager.hpp"

namespace cf
{

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

}

#endif // CONFICIA_AUDIO_HPP
