#ifndef BASICSTATE_HPP
#define BASICSTATE_HPP

#include "../Application/State.hpp"
#include "../Application/Application.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "EntityManager.hpp"
#include "SpriteSystem.hpp"
#include "MoveSystem.hpp"
#include <SFML/System/Clock.hpp>
#include "Entity.hpp"
#include "MoveComponent.hpp"
#include "SpriteComponent.hpp"

class BasicState : public State
{
    public:
        static std::string getID();

        typedef std::unique_ptr<BasicState> Ptr;

    public:
        BasicState(StateManager& manager);

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render();

    private:
        sf::Texture mTexture;
        EntityManager mEntities;
        SpriteSystem mSpriteSystem;
        MoveSystem mMoveSystem;
        sf::Clock mClock;
};

#endif // BASICSTATE_HPP
