#ifndef SOUNDBUFFERMANAGER_HPP
#define SOUNDBUFFERMANAGER_HPP

#include <map>
#include <string>
#include <SFML/Audio/SoundBuffer.hpp>

class SoundBufferManager
{
    public:
        SoundBufferManager();

        bool load(std::string const& name);

        sf::SoundBuffer& get(std::string const& name);

        bool isLoaded(std::string const& name);

        void unload(std::string const& name);

        void unload();

    private:
        std::map<std::string,sf::SoundBuffer> mBuffers;
};

#endif // SOUNDBUFFERMANAGER_HPP
