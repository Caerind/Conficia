#ifndef AM_AUDIOBUFFERMANAGER_HPP
#define AM_AUDIOBUFFERMANAGER_HPP

#include <map>
#include <string>
#include <SFML/Audio/SoundBuffer.hpp>

namespace am
{

class AudioBufferManager
{
    public:
        AudioBufferManager();

        bool load(std::string const& name);

        sf::SoundBuffer& get(std::string const& name);

        bool isLoaded(std::string const& name);

        void unload(std::string const& name);

        void unload();

    private:
        std::map<std::string,sf::SoundBuffer> mBuffers;
};

}

#endif // AM_AUDIOBUFFERMANAGER_HPP
