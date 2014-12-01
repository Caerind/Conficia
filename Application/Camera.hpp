#ifndef APP_CAMERA_HPP
#define APP_CAMERA_HPP

#include <memory>

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace app
{

class Camera : public sf::View
{
    public:
        Camera();

        void follow(std::shared_ptr<sf::Transformable> object);

        void stayInRect(sf::IntRect rect);

        sf::IntRect getBounds() const;

        void update();

        void letterBoxEffect(unsigned int width, unsigned int height);

    protected:
        std::shared_ptr<sf::Transformable> mObject;
        sf::IntRect mRect;
};

} // namespace app

#endif // APP_CAMERA_HPP
