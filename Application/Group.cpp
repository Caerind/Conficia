#include "Group.hpp"

namespace app
{

Group::Group()
: sf::Drawable()
, sf::Transformable()
, std::vector<DrawablePtr>()
{
}

Group::~Group()
{
    clear();
}

void Group::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    for (auto itr = begin(); itr != end(); itr++)
    {
        target.draw(*(*itr),states);
    }
}

} // namespace app
