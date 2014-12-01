#include "ImageLayer.hpp"
#include "Manager.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
ImageLayer::ImageLayer(Manager* mgr) : Image(mgr)
{
    mType = LayerType::ImageLayer;
}

////////////////////////////////////////////////////////////
bool ImageLayer::loadFromFile(std::string const& filename)
{
    if (!load(filename))
    {
        return false;
    }

    mVertices[0].position = sf::Vector2f(0, 0);
    mVertices[1].position = sf::Vector2f(Image::mSize.x,0);
    mVertices[2].position = sf::Vector2f(Image::mSize.x,Image::mSize.y);
    mVertices[3].position = sf::Vector2f(0,Image::mSize.y);

    mVertices[0].texCoords = sf::Vector2f(0,0);
    mVertices[1].texCoords = sf::Vector2f(Image::mSize.x,0);
    mVertices[2].texCoords = sf::Vector2f(Image::mSize.x,Image::mSize.y);
    mVertices[3].texCoords = sf::Vector2f(0,Image::mSize.y);

    sf::Color color = sf::Color::White;
    color.a = 255.f * mOpacity;

    mVertices[0].color = color;
    mVertices[1].color = color;
    mVertices[2].color = color;
    mVertices[3].color = color;

    return true;
}

////////////////////////////////////////////////////////////
void ImageLayer::render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMap)
{
    if (mVisible)
    {
        states.transform *= getTransform();
        if (getTexture() != nullptr)
        {
            states.texture = getTexture().get();
        }
        target.draw(mVertices, 4, sf::Quads, states);
    }
}

////////////////////////////////////////////////////////////
sf::FloatRect ImageLayer::getBounds() const
{
    return sf::FloatRect(mPosition.x,mPosition.y,Image::mSize.x,Image::mSize.y);
}

} // namespace tme
