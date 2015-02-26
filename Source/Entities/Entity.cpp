#include "Entity.hpp"
#include "EntityManager.hpp"

namespace cf
{

std::size_t Entity::IdCounter = 0;

Entity::Entity() : mManager(nullptr)
{
    mId = IdCounter++;
}

Entity::Entity(EntityManager* manager) : mManager(manager)
{
    mId = IdCounter++;
}

bool Entity::hasComponent(std::string const& type)
{
    return mComponents.find(type) != mComponents.end();
}

void Entity::removeAllComponents()
{
    mComponents.clear();
}

std::size_t Entity::getId() const
{
    return mId;
}

ComponentArray& Entity::getComponents()
{
    return mComponents;
}

void Entity::setManager(EntityManager* manager)
{
    mManager = manager;
}

void Entity::submitAddComponent()
{
    if (mManager != nullptr)
    {
        mManager->entityAddComponent(mId);
    }
}

void Entity::submitRemoveComponent()
{
    if (mManager != nullptr)
    {
        mManager->entityRemoveComponent(mId);
    }
}

}
