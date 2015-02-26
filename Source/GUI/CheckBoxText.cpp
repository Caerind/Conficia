#include "CheckBoxText.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
CheckBoxText::CheckBoxText() : Widget(), TextBox(Textures::Count), mChecked(false)
{
}

////////////////////////////////////////////////////////////
bool CheckBoxText::isChecked() const
{
    return mChecked;
}

////////////////////////////////////////////////////////////
void CheckBoxText::check()
{
    mChecked = !mChecked;
}

////////////////////////////////////////////////////////////
void CheckBoxText::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isEnabled() && isVisible())
    {
        if(Event::mouseIn(getPosition(),sf::Vector2f(mSprite.getGlobalBounds().width,mSprite.getGlobalBounds().height),window) && Event::clickLeft(event))
            check();
        if(isChecked())
            useTextureRect(Textures::Active);
        else
            useTextureRect(Textures::Normal);
    }
    if(!isEnabled())
        useTextureRect(Textures::Disabled);
}

////////////////////////////////////////////////////////////
void CheckBoxText::update()
{
    TextBox::update();
    Text::update();
}

////////////////////////////////////////////////////////////
void CheckBoxText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite, states);
        target.draw(mText, states);
    }
}

}

