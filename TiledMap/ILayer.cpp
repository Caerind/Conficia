#include "ILayer.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
ILayer::ILayer() : mType(ILayer::I), mName(""), mPosition(0,0), mSize(0,0), mOpacity(1.f), mVisible(true)
{
}

////////////////////////////////////////////////////////////
void ILayer::render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMapRect)
{
    if (mVisible)
    {
        states.transform *= getTransform();
    }
}

////////////////////////////////////////////////////////////
ILayer::LayerType ILayer::getLayerType() const
{
    return mType;
}

////////////////////////////////////////////////////////////
std::string ILayer::getName() const
{
    return mName;
}

////////////////////////////////////////////////////////////
void ILayer::setName(std::string const& name)
{
    mName = name;
}

////////////////////////////////////////////////////////////
sf::Vector2i ILayer::getPosition() const
{
    return mPosition;
}

////////////////////////////////////////////////////////////
void ILayer::setPosition(sf::Vector2i position)
{
    mPosition = position;
    sf::Transformable::setPosition(mPosition.x, mPosition.y);
}

////////////////////////////////////////////////////////////
sf::Vector2i ILayer::getSize() const
{
    return mSize;
}

////////////////////////////////////////////////////////////
void ILayer::setSize(sf::Vector2i size)
{
    mSize = size;
}

////////////////////////////////////////////////////////////
float ILayer::getOpacity() const
{
    return mOpacity;
}

////////////////////////////////////////////////////////////
void ILayer::setOpacity(float opacity)
{
    mOpacity = opacity;
}

////////////////////////////////////////////////////////////
bool ILayer::isVisible() const
{
    return mVisible;
}

////////////////////////////////////////////////////////////
void ILayer::setVisible(bool visible)
{
    mVisible = visible;
}

////////////////////////////////////////////////////////////
sf::FloatRect ILayer::getBounds() const
{
    return sf::FloatRect(static_cast<sf::Vector2f>(getPosition() + mPosition), static_cast<sf::Vector2f>(mSize));
}

} // namespace tme
