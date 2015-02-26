#include "Container.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
Container::Container() : Widget(), mWidgets()
{
}

////////////////////////////////////////////////////////////
void Container::show()
{
    for(Widget::Ptr w : mWidgets)
        w->show();
    mVisible = true;
}

////////////////////////////////////////////////////////////
void Container::hide()
{
    for(Widget::Ptr w : mWidgets)
        w->hide();
    mVisible = false;
}

////////////////////////////////////////////////////////////
void Container::update()
{
    if(isEnabled())
        for(Widget::Ptr w : mWidgets)
            w->update();
}

////////////////////////////////////////////////////////////
void Container::handleEvent(sf::Event const& event, sf::Window& window)
{
    if(isEnabled())
        for(Widget::Ptr w : mWidgets)
            w->handleEvent(event,window);
}

////////////////////////////////////////////////////////////
void Container::addWidget(Widget::Ptr widget)
{
    mWidgets.push_back(widget);
}

////////////////////////////////////////////////////////////
void Container::addWidget(RadioBox::Ptr widget)
{
    mWidgets.push_back(widget);
    mRadioBox.push_back(widget);
    widget->linkContainer(this);
}

////////////////////////////////////////////////////////////
void Container::addWidget(RadioBoxText::Ptr widget)
{
    mWidgets.push_back(widget);
    mRadioBoxText.push_back(widget);
    widget->linkContainer(this);
}

////////////////////////////////////////////////////////////
void Container::desactiveAllRadios()
{
    for(RadioBox::Ptr r : mRadioBox)
        r->uncheck();
    for(RadioBoxText::Ptr r : mRadioBoxText)
        r->uncheck();
}

////////////////////////////////////////////////////////////
Button::Ptr Container::newButton()
{
    Button::Ptr widget = std::make_shared<cf::Button>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LineEdit::Ptr Container::newLineEdit()
{
    LineEdit::Ptr widget = std::make_shared<cf::LineEdit>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBox::Ptr Container::newCheckBox()
{
    CheckBox::Ptr widget = std::make_shared<cf::CheckBox>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBoxText::Ptr Container::newCheckBoxText()
{
    CheckBoxText::Ptr widget = std::make_shared<cf::CheckBoxText>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBox::Ptr Container::newRadioBox()
{
    RadioBox::Ptr widget = std::make_shared<cf::RadioBox>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBoxText::Ptr Container::newRadioBoxText()
{
    RadioBoxText::Ptr widget = std::make_shared<cf::RadioBoxText>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Label::Ptr Container::newLabel()
{
    Label::Ptr widget = std::make_shared<cf::Label>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LabelBox::Ptr Container::newLabelBox()
{
    LabelBox::Ptr widget = std::make_shared<cf::LabelBox>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Slider::Ptr Container::newSlider()
{
    Slider::Ptr widget = std::make_shared<cf::Slider>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Container::Ptr Container::newContainer()
{
    Container::Ptr widget = std::make_shared<cf::Container>();
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Button::Ptr Container::copyButton(Button::Ptr button)
{
    Button::Ptr widget = std::make_shared<cf::Button>(*button);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LineEdit::Ptr Container::copyLineEdit(LineEdit::Ptr line)
{
    LineEdit::Ptr widget = std::make_shared<cf::LineEdit>(*line);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBox::Ptr Container::copyCheckBox(CheckBox::Ptr checkBox)
{
    CheckBox::Ptr widget = std::make_shared<cf::CheckBox>(*checkBox);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBoxText::Ptr Container::copyCheckBoxText(CheckBoxText::Ptr checkBox)
{
    CheckBoxText::Ptr widget = std::make_shared<cf::CheckBoxText>(*checkBox);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBox::Ptr Container::copyRadioBox(RadioBox::Ptr radioBox)
{
    RadioBox::Ptr widget = std::make_shared<cf::RadioBox>(*radioBox);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBoxText::Ptr Container::copyRadioBoxText(RadioBoxText::Ptr radioBox)
{
    RadioBoxText::Ptr widget = std::make_shared<cf::RadioBoxText>(*radioBox);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Label::Ptr Container::copyLabel(Label::Ptr label)
{
    Label::Ptr widget = std::make_shared<cf::Label>(*label);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LabelBox::Ptr Container::copyLabelBox(LabelBox::Ptr label)
{
    LabelBox::Ptr widget = std::make_shared<cf::LabelBox>(*label);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Slider::Ptr Container::copySlider(Slider::Ptr slider)
{
    Slider::Ptr widget = std::make_shared<cf::Slider>(*slider);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Container::Ptr Container::copyContainer(Container::Ptr container)
{
    Container::Ptr widget = std::make_shared<cf::Container>(*container);
    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(Widget::Ptr w : mWidgets)
        target.draw(*w,states);
}

}

