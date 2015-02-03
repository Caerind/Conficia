#ifndef SPRITESYSTEM_HPP
#define SPRITESYSTEM_HPP

#include "../Source/Entities/System.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SpriteComponent.hpp"

class SpriteSystem : public System
{
    public:
        SpriteSystem()
        {
            mFilter.push_back(SpriteComponent::getType());
        }

        SpriteSystem(EntityManager* manager) : System(manager)
        {
            mFilter.push_back(SpriteComponent::getType());
        }

        void render(sf::RenderWindow& window)
        {
            for (unsigned int i = 0; i < mEntities.size(); i++)
            {
                if (entityHasRequiredComponents(mEntities[i]))
                {
                    window.draw(mEntities[i]->getComponent<SpriteComponent>().getSprite());
                }
            }
        }
};

#endif // SPRITESYSTEM_HPP
