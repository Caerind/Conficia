#ifndef CONFICIA_LABEL_HPP
#define CONFICIA_LABEL_HPP

#include "Widget.hpp"
#include "Text.hpp"

namespace cf
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

#endif // CONFICIA_LABEL_HPP
