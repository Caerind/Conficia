#include "System.hpp"

System::System()
{
}

void System::addEntity(Entity::Ptr e)
{
    for (unsigned int i = 0; i < mFilter.size(); i++)
    {
        if (!e->hasComponent(mFilter[i]))
        {
            return;
        }
    }
    mEntities.push_back(e);
}

void System::removeEntity(Entity::Ptr e)
{
    auto itr = find(mEntities.begin(),mEntities.end(),e);

    if (itr != mEntities.end())
    {
        mEntities.erase(itr);
    }
}

std::vector<std::string> System::getFilter()
{
    return mFilter;
}

void System::setManager(EntityManager* manager)
{
    mManager = manager;
}
