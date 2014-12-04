#ifndef SGUI_CONTAINER_HPP
#define SGUI_CONTAINER_HPP

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

namespace SGUI
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

        void loadFromFile(std::string const& filename);

        Button::Ptr         createButton(bool useData = true);
        LineEdit::Ptr       createLineEdit(bool useData = true);
        CheckBox::Ptr       createCheckBox(bool useData = true);
        CheckBoxText::Ptr   createCheckBoxText(bool useData = true);
        RadioBox::Ptr       createRadioBox(bool useData = true);
        RadioBoxText::Ptr   createRadioBoxText(bool useData = true);
        Label::Ptr          createLabel(bool useData = true);
        LabelBox::Ptr       createLabelBox(bool useData = true);
        Slider::Ptr         createSlider(bool useData = true);
        Container::Ptr      createContainer(bool useData = true);

        Button::Ptr         createButton(Button::Ptr button);
        LineEdit::Ptr       createLineEdit(LineEdit::Ptr line);
        CheckBox::Ptr       createCheckBox(CheckBox::Ptr checkBox);
        CheckBoxText::Ptr   createCheckBoxText(CheckBoxText::Ptr checkBox);
        RadioBox::Ptr       createRadioBox(RadioBox::Ptr radioBox);
        RadioBoxText::Ptr   createRadioBoxText(RadioBoxText::Ptr radioBox);
        Label::Ptr          createLabel(Label::Ptr label);
        LabelBox::Ptr       createLabelBox(LabelBox::Ptr label);
        Slider::Ptr         createSlider(Slider::Ptr slider);
        Container::Ptr      createContainer(Container::Ptr container);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        struct DataLoader
        {
            DataLoader();

            void loadFromFile(std::string const& filename);

            static sf::Color loadColor(std::string const& colorStr);
            static sf::IntRect loadRect(std::string const& rectStr);
            static sf::Vector2f loadVector(std::string const& vectorStr);

            std::string filename;
            sf::Texture texture;
            sf::Font font;
            size_t characterSize;
            sf::Uint32 textStyle;
            sf::Color textColor;
            TextBox::Align align;
            sf::Vector2f sliderCursorSize;
            sf::Vector2f fontPositionCorrection;
            std::array<sf::IntRect,Button::Textures::TCount> buttonRects;
            std::array<sf::IntRect,LineEdit::Textures::Count> lineEditRects;
            std::array<sf::IntRect,CheckBox::Textures::Count> checkBoxRects;
            std::array<sf::IntRect,RadioBox::Textures::Count> radioBoxRects;
            std::array<sf::IntRect,LabelBox::Textures::Count> labelBoxRects;
            std::array<sf::IntRect,Slider::Textures::Count> sliderRects;
            std::array<sf::Color,Slider::Textures::Count> sliderColors;
        };

    private:
        bool mLoaded;
        DataLoader mData;
        std::vector<Widget::Ptr> mWidgets;
        std::vector<RadioBox::Ptr> mRadioBox;
        std::vector<RadioBoxText::Ptr> mRadioBoxText;
};

}

#endif // SGUI_CONTAINER_HPP
