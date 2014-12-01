#ifndef APP_STATISTICS_HPP
#define APP_STATISTICS_HPP

#include <string>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "IO.hpp"

namespace app
{

class Statistics : public sf::Drawable, public sf::Transformable
{
    public:
        Statistics();

        sf::Text& getText();

        void update(sf::Time dt);

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const;

    private:
        sf::Text mText;
        sf::Time mUpdateTime;
        std::size_t mNumFrames;
};

} // namespace app

#endif // APP_STATISTICS_HPP
