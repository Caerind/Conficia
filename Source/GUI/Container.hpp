#ifndef CONFICIA_CONTAINER_HPP
#define CONFICIA_CONTAINER_HPP

#include <vector>
#include "Widget.hpp"
#include "Button.hpp"
#include "LineEdit.hpp"
#include "CheckBox.hpp"
#include "CheckBoxText.hpp"
#include "RadioBox.hpp"
#include "RadioBoxText.hpp"
#include "Label.hpp"
#include "LabelBox.hpp"
#include "Slider.hpp"
#include <fstream>
#include <array>

namespace cf
{

class Container : public Widget
{
    public:
        typedef std::shared_ptr<Container> Ptr;

    public:
        Container();

        void show();
        void hide();

        virtual void update();

        virtual void handleEvent(sf::Event const& event, sf::Window& window);

        void addWidget(Widget::Ptr widget);
        void addWidget(RadioBox::Ptr widget);
        void addWidget(RadioBoxText::Ptr widget);

        void desactiveAllRadios();

        Button::Ptr         newButton();
        LineEdit::Ptr       newLineEdit();
        CheckBox::Ptr       newCheckBox();
        CheckBoxText::Ptr   newCheckBoxText();
        RadioBox::Ptr       newRadioBox();
        RadioBoxText::Ptr   newRadioBoxText();
        Label::Ptr          newLabel();
        LabelBox::Ptr       newLabelBox();
        Slider::Ptr         newSlider();
        Container::Ptr      newContainer();

        Button::Ptr         copyButton(Button::Ptr button);
        LineEdit::Ptr       copyLineEdit(LineEdit::Ptr line);
        CheckBox::Ptr       copyCheckBox(CheckBox::Ptr checkBox);
        CheckBoxText::Ptr   copyCheckBoxText(CheckBoxText::Ptr checkBox);
        RadioBox::Ptr       copyRadioBox(RadioBox::Ptr radioBox);
        RadioBoxText::Ptr   copyRadioBoxText(RadioBoxText::Ptr radioBox);
        Label::Ptr          copyLabel(Label::Ptr label);
        LabelBox::Ptr       copyLabelBox(LabelBox::Ptr label);
        Slider::Ptr         copySlider(Slider::Ptr slider);
        Container::Ptr      copyContainer(Container::Ptr container);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        std::vector<Widget::Ptr> mWidgets;
        std::vector<RadioBox::Ptr> mRadioBox;
        std::vector<RadioBoxText::Ptr> mRadioBoxText;
};

}

#endif // CONFICIA_CONTAINER_HPP
