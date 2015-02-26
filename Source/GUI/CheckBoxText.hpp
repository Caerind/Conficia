#ifndef CONFICIA_CHECKBOXTEXT_HPP
#define CONFICIA_CHECKBOXTEXT_HPP

#include "Widget.hpp"
#include "TextBox.hpp"
#include "Event.hpp"

namespace cf
{

class CheckBoxText : public Widget, public TextBox
{
    public:
        typedef std::shared_ptr<CheckBoxText> Ptr;

        enum Textures
        {
            Normal = 0,
            Active = 1,
            Disabled = 2,
            Count = 3,
        };

    public:
        CheckBoxText();

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

#endif // CONFICIA_CHECKBOXTEXT_HPP
