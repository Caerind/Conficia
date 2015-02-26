#include "System.hpp"
#include "EntityManager.hpp"

namespace cf
{

System::System()
{
}

System::System(EntityManager* manager) : mManager(manager)
{
    mManager->addSystem(this);
}

bool System::entityHasRequiredComponents(Entity::Ptr e)
{
    for (unsigned int i = 0; i < mFilter.size(); i++)
    {
        if (!e->hasComponent(mFilter[i]))
        {
            return false;
        }
    }
    return true;
}

void System::addEntity(Entity::Ptr e)
{
    if (entityHasRequiredComponents(e))
    {
        mEntities.push_back(e);
    }
}

void System::removeEntity(Entity::Ptr e)
{
    auto itr = find(mEntities.begin(),mEntities.end(),e);
    if (itr != mEntities.end())
    {
        mEntities.erase(itr);
    }
}

bool System::contains(Entity::Ptr e)
{
    auto itr = find(mEntities.begin(),mEntities.end(),e);
    if (itr != mEntities.end())
    {
        return true;
    }
    return false;
}

std::vector<std::string> System::getFilter()
{
    return mFilter;
}

void System::setManager(EntityManager* manager)
{
    mManager = manager;
}

}
