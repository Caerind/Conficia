#include "Camera.hpp"

namespace app
{

Camera::Camera() : sf::View(), mObject(nullptr), mRect(sf::IntRect(0,0,0,0))
{
}

void Camera::follow(std::shared_ptr<sf::Transformable> object)
{
    mObject = object;
}

void Camera::stayInRect(sf::IntRect rect)
{
    mRect = rect;
}

sf::IntRect Camera::getBounds() const
{
    return sf::IntRect(getCenter().x - getSize().x * 0.5, getCenter().y - getSize().y * 0.5, getSize().x, getSize().y);
}

void Camera::update()
{
    if (mObject != nullptr)
    {
        setCenter(mObject->getPosition());
    }
    if (mRect != sf::IntRect(0,0,0,0))
    {
        sf::Vector2i pos = static_cast<sf::Vector2i>(getCenter());
        sf::IntRect viewBounds(mRect.left + getSize().x/2,mRect.top + getSize().y/2, mRect.width - getSize().x, mRect.height - getSize().y);
        if(!viewBounds.contains(pos))
        {
            while(pos.x < viewBounds.left)
            {
                pos.x++;
            }
            while(pos.x >= viewBounds.left + viewBounds.width)
            {
                pos.x--;
            }
            while(pos.y < viewBounds.top)
            {
                pos.y++;
            }
            while(pos.y >= viewBounds.top + viewBounds.height)
            {
                pos.y--;
            }
            setCenter(pos.x,pos.y);
        }
    }
}

void Camera::letterBoxEffect(unsigned int width, unsigned int height)
{
    // Thanks to : https://github.com/LaurentGomila/SFML/wiki/Source%3A-Letterbox-effect-using-a-view

    float windowRatio = width / (float) height;
    float viewRatio = getSize().x / (float) getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
    {
        horizontalSpacing = false;
    }
    if (horizontalSpacing)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.0;
    }
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.0;
    }
    setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
}

} // namespace app
