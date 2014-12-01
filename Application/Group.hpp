#ifndef APP_GROUP_HPP
#define APP_GROUP_HPP

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace app
{

typedef std::shared_ptr<sf::Drawable> DrawablePtr;

class Group : public sf::Drawable, public sf::Transformable, public std::vector<DrawablePtr>
{
    public:
        Group();
        ~Group();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

} // namespace app

#endif // APP_GROUP_HPP
