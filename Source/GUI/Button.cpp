#include "Button.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
Button::Button() : Widget(), TextBox(Textures::TCount), Callback(Actions::CCount)
{
}

////////////////////////////////////////////////////////////
void Button::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isEnabled() && isVisible())
    {
        if(Event::mouseIn(getPosition(),sf::Vector2f(mSprite.getGlobalBounds().width,mSprite.getGlobalBounds().height),window))
        {
            if(!mHoverDone && mCallbacks[Actions::Hover])
            {
                mHoverDone = true;
                mCallbacks[Actions::Hover]();
            }

            useTextureRect(Textures::Active);

            if(Event::clickLeft(event) && mCallbacks[Actions::Click])
                mCallbacks[Actions::Click]();
        }
        else
        {
            useTextureRect(Textures::Normal);
            mHoverDone = false;
        }
    }
    if(!isEnabled())
        useTextureRect(Textures::Disabled);
}

////////////////////////////////////////////////////////////
void Button::update()
{
    TextBox::update();
    Text::update();
}

////////////////////////////////////////////////////////////
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite, states);
        target.draw(mText, states);
    }
}

}

