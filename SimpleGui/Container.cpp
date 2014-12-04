#include "Container.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
Container::Container() : Widget(), mLoaded(false), mWidgets()
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
void Container::loadFromFile(std::string const& filename)
{
    mData.loadFromFile(filename);
    mLoaded = true;
}


////////////////////////////////////////////////////////////
Button::Ptr Container::createButton(bool useData)
{
    Button::Ptr widget = std::make_shared<SGUI::Button>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setAlign(mData.align);
        widget->setFontCorrection(mData.fontPositionCorrection);
        widget->setTextureRect(mData.buttonRects[0],0);
        widget->setTextureRect(mData.buttonRects[1],1);
        widget->setTextureRect(mData.buttonRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LineEdit::Ptr Container::createLineEdit(bool useData)
{
    LineEdit::Ptr widget = std::make_shared<SGUI::LineEdit>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setAlign(mData.align);
        widget->setFontCorrection(mData.fontPositionCorrection);
        widget->setTextureRect(mData.lineEditRects[0],0);
        widget->setTextureRect(mData.lineEditRects[1],1);
        widget->setTextureRect(mData.lineEditRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBox::Ptr Container::createCheckBox(bool useData)
{
    CheckBox::Ptr widget = std::make_shared<SGUI::CheckBox>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setTextureRect(mData.checkBoxRects[0],0);
        widget->setTextureRect(mData.checkBoxRects[1],1);
        widget->setTextureRect(mData.checkBoxRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBoxText::Ptr Container::createCheckBoxText(bool useData)
{
    CheckBoxText::Ptr widget = std::make_shared<SGUI::CheckBoxText>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setAlign(mData.align);
        widget->setFontCorrection(mData.fontPositionCorrection);
        widget->setTextureRect(mData.checkBoxRects[0],0);
        widget->setTextureRect(mData.checkBoxRects[1],1);
        widget->setTextureRect(mData.checkBoxRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBox::Ptr Container::createRadioBox(bool useData)
{
    RadioBox::Ptr widget = std::make_shared<SGUI::RadioBox>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setTextureRect(mData.radioBoxRects[0],0);
        widget->setTextureRect(mData.radioBoxRects[1],1);
        widget->setTextureRect(mData.radioBoxRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBoxText::Ptr Container::createRadioBoxText(bool useData)
{
    RadioBoxText::Ptr widget = std::make_shared<SGUI::RadioBoxText>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setAlign(mData.align);
        widget->setFontCorrection(mData.fontPositionCorrection);
        widget->setTextureRect(mData.radioBoxRects[0],0);
        widget->setTextureRect(mData.radioBoxRects[1],1);
        widget->setTextureRect(mData.radioBoxRects[2],2);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Label::Ptr Container::createLabel(bool useData)
{
    Label::Ptr widget = std::make_shared<SGUI::Label>();

    if(useData && mLoaded)
    {
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setFontCorrection(mData.fontPositionCorrection);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LabelBox::Ptr Container::createLabelBox(bool useData)
{
    LabelBox::Ptr widget = std::make_shared<SGUI::LabelBox>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setFont(mData.font);
        widget->setCharacterSize(mData.characterSize);
        widget->setStyle(mData.textStyle);
        widget->setColor(mData.textColor);
        widget->setAlign(mData.align);
        widget->setFontCorrection(mData.fontPositionCorrection);
        widget->setTextureRect(mData.labelBoxRects[0],0);
        widget->setTextureRect(mData.labelBoxRects[1],1);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Slider::Ptr Container::createSlider(bool useData)
{
    Slider::Ptr widget = std::make_shared<SGUI::Slider>();

    if(useData && mLoaded)
    {
        widget->setTexture(mData.texture);
        widget->setTextureRect(mData.radioBoxRects[0],0);
        widget->setTextureRect(mData.radioBoxRects[1],1);
        widget->setTextureRect(mData.radioBoxRects[2],2);
        widget->setCursorSize(mData.sliderCursorSize);
        widget->setCursorColor(0,mData.sliderColors[0]);
        widget->setCursorColor(1,mData.sliderColors[1]);
        widget->setCursorColor(2,mData.sliderColors[2]);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Container::Ptr Container::createContainer(bool useData)
{
    Container::Ptr widget = std::make_shared<SGUI::Container>();

    if(useData && mLoaded)
    {
        widget->loadFromFile(mData.filename);
    }

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Button::Ptr Container::createButton(Button::Ptr button)
{
    Button::Ptr widget = std::make_shared<SGUI::Button>(*button);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LineEdit::Ptr Container::createLineEdit(LineEdit::Ptr line)
{
    LineEdit::Ptr widget = std::make_shared<SGUI::LineEdit>(*line);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBox::Ptr Container::createCheckBox(CheckBox::Ptr checkBox)
{
    CheckBox::Ptr widget = std::make_shared<SGUI::CheckBox>(*checkBox);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
CheckBoxText::Ptr Container::createCheckBoxText(CheckBoxText::Ptr checkBox)
{
    CheckBoxText::Ptr widget = std::make_shared<SGUI::CheckBoxText>(*checkBox);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBox::Ptr Container::createRadioBox(RadioBox::Ptr radioBox)
{
    RadioBox::Ptr widget = std::make_shared<SGUI::RadioBox>(*radioBox);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
RadioBoxText::Ptr Container::createRadioBoxText(RadioBoxText::Ptr radioBox)
{
    RadioBoxText::Ptr widget = std::make_shared<SGUI::RadioBoxText>(*radioBox);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Label::Ptr Container::createLabel(Label::Ptr label)
{
    Label::Ptr widget = std::make_shared<SGUI::Label>(*label);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
LabelBox::Ptr Container::createLabelBox(LabelBox::Ptr label)
{
    LabelBox::Ptr widget = std::make_shared<SGUI::LabelBox>(*label);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Slider::Ptr Container::createSlider(Slider::Ptr slider)
{
    Slider::Ptr widget = std::make_shared<SGUI::Slider>(*slider);

    addWidget(widget);
    return widget;
}

////////////////////////////////////////////////////////////
Container::Ptr Container::createContainer(Container::Ptr container)
{
    Container::Ptr widget = std::make_shared<SGUI::Container>(*container);

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

////////////////////////////////////////////////////////////
Container::DataLoader::DataLoader() : filename("")
{
}

////////////////////////////////////////////////////////////
void Container::DataLoader::loadFromFile(std::string const& filename)
{
    DataLoader::filename = filename;
    std::ifstream file(filename);
    size_t lineCount = 0;
    std::string line;
    while(std::getline(file,line))
    {
        if(line.find(" "))
            line.erase(line.find(" "),line.size());
		lineCount++;
        std::istringstream ss(line);
        size_t a;
        switch(lineCount)
        {
            case 1: texture.loadFromFile(line); break;
            case 2: font.loadFromFile(line); break;
            case 3: ss >> characterSize; break;
            case 4: ss >> textStyle; break;
            case 5: textColor = loadColor(line); break;
            case 6: ss >> a; if(a==0){align=TextBox::Align::Center;} else if(a==1){align=TextBox::Align::Left;} else if(a==2){align=TextBox::Align::Right;} break;
            case 7: sliderCursorSize = loadVector(line); break;
            case 8: fontPositionCorrection = loadVector(line); break;
            case 9: buttonRects[0] = loadRect(line); break;
            case 10: buttonRects[1] = loadRect(line); break;
            case 11: buttonRects[2] = loadRect(line); break;
            case 12: lineEditRects[0] = loadRect(line); break;
            case 13: lineEditRects[1] = loadRect(line); break;
            case 14: lineEditRects[2] = loadRect(line); break;
            case 15: checkBoxRects[0] = loadRect(line); break;
            case 16: checkBoxRects[1] = loadRect(line); break;
            case 17: checkBoxRects[2] = loadRect(line); break;
            case 18: radioBoxRects[0] = loadRect(line); break;
            case 19: radioBoxRects[1] = loadRect(line); break;
            case 20: radioBoxRects[2] = loadRect(line); break;
            case 21: labelBoxRects[0] = loadRect(line); break;
            case 22: labelBoxRects[1] = loadRect(line); break;
            case 23: sliderRects[0] = loadRect(line); break;
            case 24: sliderRects[1] = loadRect(line); break;
            case 25: sliderRects[2] = loadRect(line); break;
            case 26: sliderColors[0] = loadColor(line); break;
            case 27: sliderColors[1] = loadColor(line); break;
            case 28: sliderColors[2] = loadColor(line); break;
            default: file.close(); break;
        }
    }
    file.close();
}

////////////////////////////////////////////////////////////
sf::Color Container::DataLoader::loadColor(std::string const& colorStr)
{
    sf::Color color;
    std::stringstream ss(colorStr);
    std::string temp;
    size_t a = 0;
    while(std::getline(ss,temp,';'))
    {
        std::istringstream si(temp);
        float value;
        si >> value;
        if(a == 0) color.r = value;
        if(a == 1) color.g = value;
        if(a == 2) color.b = value;
        if(a == 3) color.a = value;
        a++;
    }
    return color;
}

////////////////////////////////////////////////////////////
sf::IntRect Container::DataLoader::loadRect(std::string const& rectStr)
{
    sf::IntRect rect;
    std::stringstream ss(rectStr);
    std::string temp;
    size_t a = 0;
    while(std::getline(ss,temp,';'))
    {
        std::istringstream si(temp);
        if(a == 0) si >> rect.left;
        if(a == 1) si >> rect.top;
        if(a == 2) si >> rect.width;
        if(a == 3) si >> rect.height;
        a++;
    }
    return rect;
}

////////////////////////////////////////////////////////////
sf::Vector2f Container::DataLoader::loadVector(std::string const& vectorStr)
{
    sf::Vector2f vector;
    std::stringstream ss(vectorStr);
    std::string temp;
    size_t a = 0;
    while(std::getline(ss,temp,';'))
    {
        std::istringstream si(temp);
        if(a == 0) si >> vector.x;
        if(a == 1) si >> vector.y;
        a++;
    }
    return vector;
}

} // namespace SGUI

