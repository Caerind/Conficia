#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <vector>

#include <SFML/Audio/SoundSource.hpp>

#include "Music.hpp"

class Playlist : public sf::SoundSource
{
    public:
        Playlist();

        void addFilename(std::string const& filename);
        void clearFilenames();

        std::string getFilename(unsigned int index) const;
        bool play(unsigned int index);

        bool play(std::string const& filename);
        void play();
        void pause();
        void stop();
        void update();

        void setLoop(bool loop);
        bool isLoop() const;

        void setPitch(float pitch);
        void setVolume(float volume);
        void setPosition(sf::Vector3f position);
        void setRelativeToListener(bool relative);
        void setMinDistance(float distance);
        void setAttenuation(float attenuation);

        float getPitch() const;
        float getVolume() const;
        sf::Vector3f getPosition() const;
        bool isRelativeToListener() const;
        float getMinDistance() const;
        float getAttenuation() const;

        sf::SoundSource::Status getStatus() const;

    protected:
        Music mMusic;
        std::vector<std::string> mFilenames;
        bool mLoop;
        unsigned int mMusicPlayed;
};

#endif // PLAYLIST_HPP
