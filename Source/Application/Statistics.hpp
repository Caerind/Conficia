#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <string>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Statistics : public sf::Drawable, public sf::Transformable
{
    public:
        Statistics();

        sf::Text& getText();

        void update(sf::Time dt);

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const;

    protected:
        sf::Text mText;
        sf::Time mUpdateTime;
        std::size_t mNumFrames;
};

#endif // STATISTICS_HPP
