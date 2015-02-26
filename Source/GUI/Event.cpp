#include "Event.hpp"

namespace cf
{

bool Event::mouseOut(sf::Vector2f position, sf::Vector2f size, sf::Window& window)
{
    return !sf::FloatRect(position,size).contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

bool Event::mouseIn(sf::Vector2f position, sf::Vector2f size, sf::Window& window)
{
    return sf::FloatRect(position,size).contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

bool Event::mouseIn(sf::FloatRect rect, sf::Window& window)
{
    return rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

bool Event::clickLeft(sf::Event const& event)
{
    return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left);
}

bool Event::keyLeft(sf::Event const& event)
{
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left);
}

bool Event::keyRight(sf::Event const& event)
{
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right);
}

bool Event::returnKey(sf::Event const& event)
{
    return (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return);
}

}
