#include "Sprite.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
Sprite::Sprite(size_t textureCount) : mSprite(), mTextureRects(textureCount)
{
}

////////////////////////////////////////////////////////////
void Sprite::setTexture(sf::Texture& texture)
{
    mSprite.setTexture(texture);
}

////////////////////////////////////////////////////////////
void Sprite::setTextureRect(sf::IntRect textureRect, size_t index)
{
    if(index >= mTextureRects.size())
        index = 0;
    mTextureRects[index] = textureRect;
    if(index == 0)
        useTextureRect(0);
}

////////////////////////////////////////////////////////////
void Sprite::useTextureRect(size_t index)
{
    if(index >= mTextureRects.size())
        index = 0;
    mSprite.setTextureRect(mTextureRects[index]);
}

////////////////////////////////////////////////////////////
sf::Vector2f Sprite::getSize() const
{
    return sf::Vector2f(mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height);
}

////////////////////////////////////////////////////////////
void Sprite::setSize(sf::Vector2f newSize)
{
    mSprite.setScale(mSprite.getScale().x * newSize.x / getSize().x, mSprite.getScale().y * newSize.y / getSize().y);
}

////////////////////////////////////////////////////////////
void Sprite::setSize(float x, float y)
{
    setSize(sf::Vector2f(x,y));
}

} // namespace SGUI

