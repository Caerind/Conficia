#ifndef CONFICIA_SYSTEM_HPP
#define CONFICIA_SYSTEM_HPP

#include <vector>
#include <string>
#include <algorithm>

#include "Entity.hpp"

namespace cf
{

class EntityManager;

class System
{
    public:
        System();
        System(EntityManager* manager);

        template<typename T>
        void action(T& param);

        template<typename T>
        void actionEntity(Entity::Ptr e, T& param);

        bool entityHasRequiredComponents(Entity::Ptr e);

        void addEntity(Entity::Ptr e);
        void removeEntity(Entity::Ptr e);
        bool contains(Entity::Ptr e);

        std::size_t getEntityCount();

        std::vector<std::string> getFilter();

        void setManager(EntityManager* manager);

    protected:
        std::vector<Entity::Ptr> mEntities;
        std::vector<std::string> mFilter;
        EntityManager* mManager;
};

}

#endif // CONFICIA_SYSTEM_HPP
