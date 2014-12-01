#ifndef SOUNDPLAYER_HPP
#define SOUNDPLAYER_HPP

#include <memory>
#include <map>
#include <SFML/Audio/Sound.hpp>
#include "SoundBufferManager.hpp"

class SoundPlayer
{
    public:
        typedef std::shared_ptr<sf::Sound> SoundPtr;

    public:
        SoundPlayer();

        SoundPtr play(std::string const& filename);

        void stop();

        void update();

    private:
        std::multimap<std::string,SoundPtr> mSounds;
        SoundBufferManager mBuffers;
};

#endif // SOUNDPLAYER_HPP
