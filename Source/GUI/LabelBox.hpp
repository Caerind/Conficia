#ifndef CONFICIA_LABELBOX_HPP
#define CONFICIA_LABELBOX_HPP

#include "Widget.hpp"
#include "TextBox.hpp"

namespace cf
{

class LabelBox : public Widget, public TextBox
{
    public:
        typedef std::shared_ptr<LabelBox> Ptr;

        enum Textures
        {
            Normal = 0,
            Disabled = 1,
            Count = 2,
        };

    public:
        LabelBox();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

        virtual void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // CONFICIA_LABELBOX_HPP
