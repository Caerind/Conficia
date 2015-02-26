#ifndef CONFICIA_LINEEDIT_HPP
#define CONFICIA_LINEEDIT_HPP

#include "Widget.hpp"
#include "TextBox.hpp"
#include "Callback.hpp"
#include "Event.hpp"

namespace cf
{

class LineEdit : public Widget, public TextBox, public Callback
{
    public:
        typedef std::shared_ptr<LineEdit> Ptr;

        enum Textures
        {
            Normal = 0,
            Active = 1,
            Disabled = 2,
            Count = 3,
        };

    public:
        LineEdit();

        void setString(std::string const& string);
        std::string getString() const;

        bool isActive() const;
        void activate();
        void deactivate();

        void setCharacterSize(size_t size);
        virtual void update();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void moveCursorLeft();
        void moveCursorRight();
        void insertCharacter(char c);
        void backspace();
        void adaptTextToBox();

    private:
        bool mActive;
        size_t mCharacterSize;
};

}

#endif // CONFICIA_LINEEDIT_HPP
