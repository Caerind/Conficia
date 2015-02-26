#ifndef SOUND_HPP
#define CONFICIA_SOUND_HPP

#include <string>

#include <SFML/Audio/Sound.hpp>

namespace cf
{

class SoundManager;

class Sound : public sf::Sound
{
    public:
        Sound();
        Sound(SoundManager* manager);
        ~Sound();

        bool play(std::string const& filename);

        void setManager(SoundManager* manager);
        SoundManager* getManager() const;

    protected:
        SoundManager* mManager;
};

}

#endif // CONFICIA_SOUND_HPP
