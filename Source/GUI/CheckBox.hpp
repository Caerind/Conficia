#ifndef CONFICIA_CHECKBOX_HPP
#define CONFICIA_CHECKBOX_HPP

#include "Widget.hpp"
#include "Sprite.hpp"
#include "Event.hpp"

namespace cf
{

class CheckBox : public Widget, public Sprite
{
    public:
        typedef std::shared_ptr<CheckBox> Ptr;

        enum Textures
        {
            Normal = 0,
            Active = 1,
            Disabled = 2,
            Count = 3,
        };

    public:
        CheckBox();

        bool isChecked() const;
        void check();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

        virtual void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        bool mChecked;
};

}

#endif // CONFICIA_CHECKBOX_HPP
