#ifndef MOVESYSTEM_HPP
#define MOVESYSTEM_HPP

#include "../Source/Entities/System.hpp"
#include <SFML/System/Time.hpp>
#include "MoveComponent.hpp"
#include "SpriteComponent.hpp"

class MoveSystem : public System
{
    public:
        MoveSystem()
        {
            mFilter.push_back(SpriteComponent::getType());
            mFilter.push_back(MoveComponent::getType());
        }

        MoveSystem(EntityManager* manager) : System(manager)
        {
            mFilter.push_back(SpriteComponent::getType());
            mFilter.push_back(MoveComponent::getType());
        }

        void update(sf::Time dt)
        {
            for (unsigned int i = 0; i < mEntities.size(); i++)
            {
                float s = mEntities[i]->getComponent<MoveComponent>().getSpeed();
                mEntities[i]->getComponent<SpriteComponent>().getSprite().move(sf::Vector2f(s * dt.asSeconds(), s* dt.asSeconds()));
            }
        }
};

#endif // MOVESYSTEM_HPP
