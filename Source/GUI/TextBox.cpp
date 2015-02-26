#include "TextBox.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
TextBox::TextBox(size_t textureCount) : Sprite(textureCount), Text(), mAlign(Align::Center)
{
}

////////////////////////////////////////////////////////////
void TextBox::setAlign(TextBox::Align align)
{
    mAlign = align;
}

////////////////////////////////////////////////////////////
TextBox::Align TextBox::getAlign() const
{
    return mAlign;
}

////////////////////////////////////////////////////////////
void TextBox::update()
{
    textAlign();
    adaptTextToBox();
}

////////////////////////////////////////////////////////////
void TextBox::adaptTextToBox()
{
    while(mText.getGlobalBounds().width > mSprite.getGlobalBounds().width + 16) // + 16 correspond to  padding
    {
        mText.setCharacterSize(mText.getCharacterSize()-1);
        textAlign();
    }
}

////////////////////////////////////////////////////////////
void TextBox::textAlign()
{
    switch(mAlign)
    {
        case Align::Center:
            mText.setOrigin(mText.getGlobalBounds().width * 0.5f,mText.getGlobalBounds().height * 0.5);
            mText.setPosition(mSprite.getGlobalBounds().width * 0.5, mSprite.getGlobalBounds().height * 0.5);
            break;

        case Align::Left:
            mText.setOrigin(0, mText.getGlobalBounds().height / 2.f);
            mText.setPosition(16, mSprite.getGlobalBounds().height * 0.5); // 16 is a padding
            break;

        case Align::Right:
            mText.setOrigin(mText.getGlobalBounds().width, mText.getGlobalBounds().height/ 2.f);
            mText.setPosition(mSprite.getGlobalBounds().width - 16, mSprite.getGlobalBounds().height * 0.5); // - 16 is padding
            break;

        default:
            break;
    }
}

////////////////////////////////////////////////////////////
sf::Vector2f TextBox::getSize() const
{
    return Sprite::getSize();
}

////////////////////////////////////////////////////////////
void TextBox::setSize(sf::Vector2f newSize)
{
    Sprite::setSize(newSize);
    mText.setScale(mSprite.getScale());
}

////////////////////////////////////////////////////////////
void TextBox::setSize(float x, float y)
{
    Sprite::setSize(x,y);
}

}

