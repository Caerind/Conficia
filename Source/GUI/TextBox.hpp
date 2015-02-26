#ifndef CONFICIA_TEXTBOX_HPP
#define CONFICIA_TEXTBOX_HPP

#include "Sprite.hpp"
#include "Text.hpp"

namespace cf
{

class TextBox : public Sprite, public Text
{
    public:
        TextBox(size_t textureCount);

        enum Align
        {
            Center = 0,
            Left = 1,
            Right = 2,
        };

        void setAlign(Align align);
        Align getAlign() const;

        void update();

        sf::Vector2f getSize() const;
        void setSize(sf::Vector2f newSize);
        void setSize(float x, float y);

    protected:
        void adaptTextToBox();
        void textAlign();

    protected:
        Align mAlign;
};

}

#endif // CONFICIA_TEXTBOX_HPP
