#ifndef MUSICPLAYER_HPP
#define MUSICPLAYER_HPP

#include <SFML/Audio/Music.hpp>

class MusicPlayer : public sf::Music
{
    public:
        MusicPlayer();
        MusicPlayer(std::string const& filename, bool loop = true);

        bool play(std::string const& filename);
};

#endif // MUSICPLAYER_HPP
