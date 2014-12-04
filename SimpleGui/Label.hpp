#ifndef SGUI_LABEL_HPP
#define SGUI_LABEL_HPP

#include "Widget.hpp"
#include "Text.hpp"

namespace SGUI
{

class Label : public Widget, public Text
{
    public:
        typedef std::shared_ptr<Label> Ptr;

    public:
        Label();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

        virtual void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // SGUI_LABEL_HPP
