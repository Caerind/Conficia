#ifndef CONFICIA_BUTTON_HPP
#define CONFICIA_BUTTON_HPP

#include "Widget.hpp"
#include "TextBox.hpp"
#include "Callback.hpp"
#include "Event.hpp"

namespace cf
{

class Button : public Widget, public TextBox, public Callback
{
    public:
        typedef std::shared_ptr<Button> Ptr;

    public:
        enum Textures
        {
            Normal = 0,
            Active = 1, // Hover
            Disabled = 2,
            TCount = 3,
        };

        enum Actions
        {
            Click = 0,
            Hover = 1,
            CCount = 2,
        };

    public:
        Button();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

        virtual void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // CONFICIA_BUTTON_HPP
