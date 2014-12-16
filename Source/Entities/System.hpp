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
        System(EntityManager* manager);

        template<typename T>
        void action(T& param);

        template<typename T>
        virtual void actionEntity(Entity::Ptr e, T& param);

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

template<typename T>
void System::action(T& param)
{
    for (auto itr = mEntities.begin(); itr != mEntities.end(); itr++)
    {
        if (entityHasRequiredComponents(*itr))
        {
            actionEntity<T>(*itr,param);
        }
        else
        {
            mEntities.erase(itr);
        }
    }
}

template<typename T>
void System::actionEntity(Entity::Ptr e, T& param)
{
}

#endif // SYSTEM_HPP