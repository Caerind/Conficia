#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>
#include <algorithm>

#include "Entity.hpp"

class EntityManager;

class System
{
    public:
        System();

        static std::string getType()
        {
            return "System";
        }

        void addEntity(Entity::Ptr e);
        void removeEntity(Entity::Ptr e);

        std::size_t getEntityCount();

        std::vector<std::string> getFilter();

        void setManager(EntityManager* manager);

    protected:
        std::vector<Entity::Ptr> mEntities;
        std::vector<std::string> mFilter;
        EntityManager* mManager;
};

#endif // SYSTEM_HPP
