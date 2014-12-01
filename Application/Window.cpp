#include "Window.hpp"

namespace app
{

Window::Window()
{
    mVerticalSync = false;
    mVisible = true;
    mKeyRepeat = true;
}

void Window::hideMouseCursor()
{
    sf::RenderWindow::setMouseCursorVisible(false);
    mMouseCursorVisibility = MouseCursor::None;
}

void Window::useDefaultMouseCursor()
{
    sf::RenderWindow::setMouseCursorVisible(true);
    mMouseCursorVisibility = MouseCursor::Default;
}

void Window::useCustomMouseCursor()
{
    sf::RenderWindow::setMouseCursorVisible(false);
    mMouseCursorVisibility = MouseCursor::Custom;
}

Window::MouseCursor Window::getMouseCursorVisibility()
{
    return mMouseCursorVisibility;
}

void Window::setMouseCursorTexture(sf::Texture& texture)
{
    mMouseCursor.setTexture(texture);
}

void Window::setMouseCursorTextureRect(sf::IntRect rect)
{
    mMouseCursor.setTextureRect(rect);
}

void Window::setMouseCursorOrigin(sf::Vector2f origin)
{
    mMouseCursor.setOrigin(origin);
}

void Window::setMouseCursorScale(sf::Vector2f scale)
{
    mMouseCursor.setScale(scale);
}

sf::IntRect Window::getMouseCursorTextureRect()
{
    return mMouseCursor.getTextureRect();
}

sf::Vector2f Window::getMouseCursorOrigin()
{
    return mMouseCursor.getOrigin();
}

sf::Vector2f Window::getMouseCursorScale()
{
    return mMouseCursor.getScale();
}

sf::Vector2i Window::getMousePosition2i()
{
    return sf::Mouse::getPosition(*this);
}

sf::Vector2f Window::getMousePosition()
{
    return static_cast<sf::Vector2f>(getMousePosition2i());
}

sf::Vector2f Window::getMousePositionMap()
{
    return mapPixelToCoords(getMousePosition2i());
}

sf::Vector2f Window::getMousePositionView(sf::View const& view)
{
    return mapPixelToCoords(getMousePosition2i(),view);
}

void Window::setPosition(sf::Vector2i const& position)
{
    sf::RenderWindow::setPosition(position);
}

void Window::setPosition(int x, int y)
{
    setPosition(sf::Vector2i(x,y));
}

void Window::move(sf::Vector2i const& movement)
{
    setPosition(getPosition().x + movement.x, getPosition().y + movement.y);
}

void Window::move(int x, int y)
{
    move(sf::Vector2i(x,y));
}

void Window::setDefaultView()
{
    setView(getDefaultView());
}

void Window::create(sf::VideoMode videoMode, std::string const& title, sf::Uint32 style, const sf::ContextSettings& settings)
{
    sf::RenderWindow::create(videoMode, title, style, settings);
    mTitle = title;
}

void Window::create(int width, int height, std::string const& title, sf::Uint32 style, const sf::ContextSettings& settings)
{
    sf::RenderWindow::create(sf::VideoMode(static_cast<unsigned int>(width),static_cast<unsigned int>(height)),title,style,settings);
    mTitle = title;
}

void Window::display()
{
    update();
    sf::RenderWindow::display();
}

void Window::update()
{
    setDefaultView();
    if(mMouseCursorVisibility == MouseCursor::Custom)
    {
        mMouseCursor.setPosition(getMousePosition());
        draw(mMouseCursor,sf::RenderStates());
    }
}

void Window::setTitle(std::string const& title)
{
    mTitle = title;
}

std::string Window::getTitle()
{
    return mTitle;
}

void Window::setVerticalSyncEnabled(bool enabled)
{
    sf::RenderWindow::setVerticalSyncEnabled(enabled);
    mVerticalSync = enabled;
}

bool Window::isVerticalSyncEnabled()
{
    return mVerticalSync;
}

void Window::setVisible(bool visible)
{
    sf::RenderWindow::setVisible(visible);
    mVisible = visible;
}

bool Window::isVisible()
{
    return mVisible;
}

void Window::setKeyRepeatEnabled(bool enabled)
{
    sf::RenderWindow::setKeyRepeatEnabled(enabled);
    mKeyRepeat = enabled;
}

bool Window::isKeyRepeatEnabled()
{
    return mKeyRepeat;
}

} // namespace app
