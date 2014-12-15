#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>

#include <SFML/Audio/Sound.hpp>

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

#endif // SOUND_HPP
