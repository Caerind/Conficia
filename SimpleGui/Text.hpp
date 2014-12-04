#ifndef SGUI_TEXT_HPP
#define SGUI_TEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include <string>

namespace SGUI
{

class Text
{
    public:
        Text();

        void setFont(sf::Font& font);
        void setString(std::string const& string);
        void setCharacterSize(size_t size);
        void setStyle(sf::Uint32 style);
        void setColor(sf::Color color);

        std::string getString() const;
        size_t getCharacterSize() const;
        sf::Uint32 getStyle() const;
        sf::Color getColor() const;

        sf::Vector2f getSize() const;
        void setSize(sf::Vector2f newSize);
        void setSize(float x, float y);

        sf::Vector2f getFontCorrection() const;
        void setFontCorrection(sf::Vector2f fontCorrection);

        virtual void update();

    protected:
        sf::Text mText;
        sf::Vector2f mFontCorrection;
};

}

#endif // SGUI_TEXT_HPP
