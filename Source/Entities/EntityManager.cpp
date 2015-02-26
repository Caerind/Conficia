#include "EntityManager.hpp"

namespace cf
{

EntityManager::EntityManager()
{
}

Entity::Ptr EntityManager::createEntity()
{
    Entity::Ptr e = std::shared_ptr<Entity>(new Entity(this));
    mEntities[e->getId()] = e;
    entityAdded(e);
    return e;
}

void EntityManager::addEntity(Entity::Ptr e)
{
    mEntities[e->getId()] = e;
    e->setManager(this);
    entityAdded(e);
}

void EntityManager::removeEntity(Entity::Ptr e)
{
    if (mEntities.find(e->getId()) != mEntities.end())
    {
        mEntities.erase(mEntities.find(e->getId()));
        entityRemoved(e);
    }
}

Entity::Ptr EntityManager::getEntity(std::size_t id)
{
    return mEntities[id];
}

void EntityManager::addSystem(System* system)
{
    mSystems.push_back(system);
    mSystems.back()->setManager(this);
    for (auto itr = mEntities.begin(); itr != mEntities.end(); itr++)
    {
        system->addEntity(itr->second);
    }
}

void EntityManager::removeSystem(System* system)
{
    for (auto itr = mSystems.begin(); itr != mSystems.end(); itr++)
    {
        if (*itr == system)
        {
            mSystems.erase(itr);
        }
    }
}

void EntityManager::entityAdded(Entity::Ptr e)
{
    for (unsigned int i = 0; i < mSystems.size(); i++)
    {
        mSystems[i]->addEntity(e);
    }
}

void EntityManager::entityRemoved(Entity::Ptr e)
{
    for (unsigned int i = 0; i < mSystems.size(); i++)
    {
        mSystems[i]->removeEntity(e);
    }
}

void EntityManager::entityAddComponent(std::size_t id)
{
    if (mEntities.find(id) != mEntities.end())
    {
        for (unsigned int i = 0; i < mSystems.size(); i++)
        {
            if (!mSystems[i]->contains(mEntities[id]) && mSystems[i]->entityHasRequiredComponents(mEntities[id]))
            {
                mSystems[i]->addEntity(mEntities[id]);
            }
        }
    }
}

void EntityManager::entityRemoveComponent(std::size_t id)
{
    if (mEntities.find(id) != mEntities.end())
    {
        for (unsigned int i = 0; i < mSystems.size(); i++)
        {
            if (mSystems[i]->contains(mEntities[id]) && !mSystems[i]->entityHasRequiredComponents(mEntities[id]))
            {
                mSystems[i]->removeEntity(mEntities[id]);
            }
        }
    }
}

}
