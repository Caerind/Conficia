#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "../Source/Entities/Component.hpp"

class SpriteComponent : public Component
{
    public:
        SpriteComponent()
        {
        }

        static std::string getType()
        {
            return "SpriteComponent";
        }

        sf::Sprite& getSprite()
        {
            return mSprite;
        }

    protected:
        sf::Sprite mSprite;
};

#endif // SPRITECOMPONENT_HPP
