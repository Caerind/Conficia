#ifndef CONFICIA_MUSIC_HPP
#define CONFICIA_MUSIC_HPP

#include <string>
#include <SFML/Audio/Music.hpp>

namespace cf
{

class Music : public sf::Music
{
    public:
        Music();

        bool openFromFile(std::string const& filename);
        bool play(std::string const& filename, unsigned int times = 1);
        bool play(unsigned int times = 1);
        void stop();

        void update();
        unsigned int getTimesLeft() const;

        void setFilename(std::string const& filename);
        std::string getFilename() const;

    protected:
        std::string mFilename;
        unsigned int mTimesLeft;
};

}

#endif // CONFICIA_MUSIC_HPP
