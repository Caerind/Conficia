#include "RadioBoxText.hpp"
#include "Container.hpp"

namespace SGUI
{

RadioBoxText::RadioBoxText() : Widget(), TextBox(Textures::Count), mContainer(nullptr), mChecked(false)
{
}

void RadioBoxText::linkContainer(Container* container)
{
    mContainer = container;
}

bool RadioBoxText::isChecked() const
{
    return mChecked;
}

void RadioBoxText::check()
{
    if(!isChecked() && mContainer != nullptr)
        mContainer->desactiveAllRadios();
    mChecked = !mChecked;
}

void RadioBoxText::uncheck()
{
    mChecked = false;
}

void RadioBoxText::update()
{
    TextBox::update();
    Text::update();
    // Need to handle it here because Radio can be unchecked by others
    if(isVisible() && isEnabled())
    {
        if(isChecked())
            useTextureRect(Textures::Active);
        else
            useTextureRect(Textures::Normal);
    }
    else
        useTextureRect(Textures::Disabled);
}

void RadioBoxText::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isVisible() && isEnabled())
        if(Event::mouseIn(getPosition(),sf::Vector2f(mSprite.getGlobalBounds().width,mSprite.getGlobalBounds().height),window) && Event::clickLeft(event))
            check();
}

void RadioBoxText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite, states);
        target.draw(mText, states);
    }
}

}
