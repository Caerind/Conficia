#include "RadioBox.hpp"
#include "Container.hpp"

namespace cf
{

RadioBox::RadioBox() : Widget(), Sprite(Textures::Count), mContainer(nullptr), mChecked(false)
{
}

void RadioBox::linkContainer(Container* container)
{
    mContainer = container;
}

bool RadioBox::isChecked() const
{
    return mChecked;
}

void RadioBox::check()
{
    if(!isChecked() && mContainer != nullptr)
        mContainer->desactiveAllRadios();
    mChecked = !mChecked;
}

void RadioBox::uncheck()
{
    mChecked = false;
}

void RadioBox::update()
{
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

void RadioBox::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isVisible() && isEnabled())
        if(Event::mouseIn(getPosition(),sf::Vector2f(mSprite.getGlobalBounds().width,mSprite.getGlobalBounds().height),window) && Event::clickLeft(event))
            check();
}

void RadioBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite,states);
    }
}

}
