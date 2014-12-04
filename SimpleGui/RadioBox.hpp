#ifndef SGUI_RADIOBOX_HPP
#define SGUI_RADIOBOX_HPP

#include "Widget.hpp"
#include "Sprite.hpp"
#include "Event.hpp"

namespace SGUI
{

class Container;

class RadioBox : public Widget, public Sprite
{
    public:
        typedef std::shared_ptr<RadioBox> Ptr;

        enum Textures
        {
            Normal = 0,
            Active = 1,
            Disabled = 2,
            Count = 3,
        };

    public:
        RadioBox();

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

#endif // SGUI_RADIOBOX_HPP
