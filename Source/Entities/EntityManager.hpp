#ifndef CONFICIA_ENTITYMANAGER_HPP
#define CONFICIA_ENTITYMANAGER_HPP

#include "Entity.hpp"
#include "System.hpp"

namespace cf
{

class EntityManager
{
    public:
        EntityManager();

        Entity::Ptr createEntity();
        void addEntity(Entity::Ptr e);
        void removeEntity(Entity::Ptr e);

        Entity::Ptr getEntity(std::size_t id);

        void addSystem(System* system);
        void removeSystem(System* system);

        void entityAdded(Entity::Ptr e);
        void entityRemoved(Entity::Ptr e);
        void entityAddComponent(std::size_t id);
        void entityRemoveComponent(std::size_t id);

    protected:
        std::map<std::size_t, Entity::Ptr> mEntities;
        std::vector<System*> mSystems;
};

}

#endif // CONFICIA_ENTITYMANAGER_HPP
