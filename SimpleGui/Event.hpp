#ifndef SGUI_EVENT_HPP
#define SGUI_EVENT_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

namespace SGUI
{

class Event
{
    public:
        static bool mouseOut(sf::Vector2f position,sf::Vector2f size,sf::Window& window);
        static bool mouseIn(sf::Vector2f position,sf::Vector2f size,sf::Window& window);
        static bool mouseIn(sf::FloatRect rect,sf::Window& window);
        static bool clickLeft(sf::Event const& event);
        static bool keyLeft(sf::Event const& event);
        static bool keyRight(sf::Event const& event);
        static bool returnKey(sf::Event const& event);
};

}

#endif // SGUI_EVENT_HPP
