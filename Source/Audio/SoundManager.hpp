#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include <string>
#include <map>
#include <memory>
#include <vector>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Sound;

class SoundManager
{
    public:
        SoundManager();
        ~SoundManager();

        sf::SoundBuffer* getBuffer(std::string const& filename);
        bool loadBuffer(std::string const& filename);
        bool hasBuffer(std::string const& filename);

        bool play(std::string const& filename);
        void update();

    protected:
        std::map<std::string,sf::SoundBuffer> mBuffers;
        std::vector<std::unique_ptr<Sound>> mSounds;
};

#endif // SOUNDMANAGER_HPP
