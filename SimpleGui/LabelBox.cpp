#include "LabelBox.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
LabelBox::LabelBox() : Widget(), TextBox(Textures::Count)
{
}

////////////////////////////////////////////////////////////
void LabelBox::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isEnabled())
        useTextureRect(Textures::Normal);
    else
        useTextureRect(Textures::Disabled);
}

////////////////////////////////////////////////////////////
void LabelBox::update()
{
    TextBox::update();
    Text::update();
}

////////////////////////////////////////////////////////////
void LabelBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mSprite,states);
        target.draw(mText,states);
    }
}

} // namespace SGUI

