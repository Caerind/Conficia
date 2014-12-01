#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
{
}

MusicPlayer::MusicPlayer(std::string const& filename, bool loop)
{
    setLoop(loop);
    play(filename);
}

bool MusicPlayer::play(std::string const& filename)
{
    if (openFromFile(filename))
    {
        sf::Music::play();
        return true;
    }
    return false;
}
