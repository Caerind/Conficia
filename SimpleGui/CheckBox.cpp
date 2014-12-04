#include "CheckBox.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
CheckBox::CheckBox() : Widget(), Sprite(Textures::Count), mChecked(false)
{
}

////////////////////////////////////////////////////////////
bool CheckBox::isChecked() const
{
    return mChecked;
}

////////////////////////////////////////////////////////////
void CheckBox::check()
{
    mChecked = !mChecked;
}

////////////////////////////////////////////////////////////
void CheckBox::handleEvent(sf::Event const& event, sf::Window& window)
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
void CheckBox::update()
{
}

////////////////////////////////////////////////////////////
void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite, states);
    }
}

} // namespace SGUI

