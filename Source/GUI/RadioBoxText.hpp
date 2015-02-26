#ifndef CONFICIA_RADIOBOXTEXT_HPP
#define CONFICIA_RADIOBOXTEXT_HPP

#include "Widget.hpp"
#include "TextBox.hpp"

namespace cf
{

class Container;

class RadioBoxText : public Widget, public TextBox
{
    public:
        typedef std::shared_ptr<RadioBoxText> Ptr;

        enum Textures
        {
            Normal = 0,
            Active = 1,
            Disabled = 2,
            Count = 3,
        };

    public:
        RadioBoxText();

        void linkContainer(Container* container);

        bool isChecked() const;
        void check();
        void uncheck();

        virtual void update();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Container* mContainer;
        bool mChecked;
};

}

#endif // CONFICIA_RADIOBOXTEXT_HPP
