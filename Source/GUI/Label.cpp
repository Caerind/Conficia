#include "Label.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
Label::Label() : Widget(), Text()
{
}

////////////////////////////////////////////////////////////
void Label::handleEvent(sf::Event const& event, sf::Window& window)
{
}

////////////////////////////////////////////////////////////
void Label::update()
{
}

////////////////////////////////////////////////////////////
void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isVisible())
    {
        states.transform *= getTransform();
        target.draw(mText,states);
    }
}

}

