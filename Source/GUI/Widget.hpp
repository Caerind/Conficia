#ifndef CONFICIA_WIDGET_HPP
#define CONFICIA_WIDGET_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

namespace cf
{

class Widget : public sf::Drawable, public sf::Transformable
{
    public:
        typedef std::shared_ptr<Widget> Ptr;

    public:
        Widget();

        bool isEnabled() const;
        void enable();
        void disable();

        bool isVisible() const;
        void show();
        void hide();

        virtual sf::Vector2f getSize() const;
        virtual void setSize(sf::Vector2f newSize);
        virtual void setSize(float x, float y);

        virtual void update();

        virtual void handleEvent(sf::Event const& event, sf::Window& window) = 0;

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    protected:
        bool mEnabled;
        bool mVisible;
};

}

#endif // CONFICIA_WIDGET_HPP
