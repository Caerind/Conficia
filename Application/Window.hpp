#ifndef APP_WINDOW_HPP
#define APP_WINDOW_HPP

#include <memory>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>

namespace app
{

class Window : public sf::RenderWindow
{
    public:
        // Ctor
        Window();

        // Mouse Cursor
        enum MouseCursor
        {
            Default,
            None,
            Custom,
        };

        void hideMouseCursor();
        void useDefaultMouseCursor();
        void useCustomMouseCursor();
        MouseCursor getMouseCursorVisibility();

        void setMouseCursorTexture(sf::Texture& texture);
        void setMouseCursorTextureRect(sf::IntRect rect);
        void setMouseCursorOrigin(sf::Vector2f origin);
        void setMouseCursorScale(sf::Vector2f scale);
        sf::IntRect getMouseCursorTextureRect();
        sf::Vector2f getMouseCursorOrigin();
        sf::Vector2f getMouseCursorScale();

        // Mouse
        sf::Vector2i getMousePosition2i();
        sf::Vector2f getMousePosition();
        sf::Vector2f getMousePositionMap();
        sf::Vector2f getMousePositionView(sf::View const& view);

        // Position
        void setPosition(sf::Vector2i const& position);
        void setPosition(int x, int y);
        void move(sf::Vector2i const& movement);
        void move(int x, int y);

        // View
        void setDefaultView();

        // Others
        void create(sf::VideoMode videoMode, std::string const& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
        void create(int width, int height, std::string const& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
        void display(); // Do update() before rendering everythings
        void update();

        // Title
        void setTitle(std::string const& title);
        std::string getTitle();

        // VerticalSync
        void setVerticalSyncEnabled(bool enabled);
        bool isVerticalSyncEnabled();

        // Visible
        void setVisible(bool visible);
        bool isVisible();

        // KeyRepeat
        void setKeyRepeatEnabled(bool enabled);
        bool isKeyRepeatEnabled();


    protected:
        MouseCursor mMouseCursorVisibility;
        sf::Texture mMouseCursorTexture;
        sf::Sprite mMouseCursor;

        std::string mTitle;
        bool mVerticalSync;
        bool mVisible;
        bool mKeyRepeat;
};

} // namespace app

#endif // APP_WINDOW_HPP
