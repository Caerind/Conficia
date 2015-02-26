#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "../Source/Entities/Component.hpp"

class SpriteComponent : public cf::Component, public sf::Sprite
{
    public:
        SpriteComponent()
        {
        }

        static std::string getType()
        {
            return "SpriteComponent";
        }
};

#endif // SPRITECOMPONENT_HPP
