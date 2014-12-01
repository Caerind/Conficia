#ifndef AM_AUDIO_HPP_INCLUDED
#define AM_AUDIO_HPP_INCLUDED

#include <memory>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundSource.hpp>

namespace am
{

enum FileType
{
    Sound,
    Music,
};

typedef std::unique_ptr<sf::Music> MusicPtr;
typedef std::unique_ptr<sf::Sound> SoundPtr;

}

#endif // AM_AUDIO_HPP_INCLUDED
