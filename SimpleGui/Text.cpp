#include "Text.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
Text::Text() : mText()
{
}

////////////////////////////////////////////////////////////
void Text::setFont(sf::Font& font)
{
    mText.setFont(font);
}

////////////////////////////////////////////////////////////
void Text::setString(std::string const& string)
{
    mText.setString(string);
}

////////////////////////////////////////////////////////////
void Text::setCharacterSize(size_t size)
{
    mText.setCharacterSize(size);
}

////////////////////////////////////////////////////////////
void Text::setStyle(sf::Uint32 style)
{
    mText.setStyle(style);
}

////////////////////////////////////////////////////////////
void Text::setColor(sf::Color color)
{
    mText.setColor(color);
}

////////////////////////////////////////////////////////////
std::string Text::getString() const
{
    return mText.getString();
}

////////////////////////////////////////////////////////////
size_t Text::getCharacterSize() const
{
    return mText.getCharacterSize();
}

////////////////////////////////////////////////////////////
sf::Uint32 Text::getStyle() const
{
    return mText.getStyle();
}

////////////////////////////////////////////////////////////
sf::Color Text::getColor() const
{
    return mText.getColor();
}

////////////////////////////////////////////////////////////
sf::Vector2f Text::getSize() const
{
    return sf::Vector2f(mText.getGlobalBounds().width, mText.getGlobalBounds().height);
}

////////////////////////////////////////////////////////////
void Text::setSize(sf::Vector2f newSize)
{
    mText.setScale(mText.getScale().x * newSize.x / getSize().x, mText.getScale().y * newSize.y / getSize().y);
}

////////////////////////////////////////////////////////////
void Text::setSize(float x, float y)
{
    setSize(sf::Vector2f(x,y));
}

////////////////////////////////////////////////////////////
sf::Vector2f Text::getFontCorrection() const
{
    return mFontCorrection;
}

////////////////////////////////////////////////////////////
void Text::setFontCorrection(sf::Vector2f fontCorrection)
{
    mFontCorrection = fontCorrection;
}

////////////////////////////////////////////////////////////
void Text::update()
{
    mText.setPosition(mText.getPosition() - mFontCorrection);
}

} // namespace SGUI

