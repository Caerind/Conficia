#include "Entity.hpp"

std::size_t Entity::IdCounter = 0;

Entity::Entity()
{
    mId = IdCounter++;
    mIsActivated = true;
    mIsRemoved = false;
}

void Entity::activate()
{
    mIsActivated = true;
}

void Entity::deactivate()
{
    mIsActivated = false;
}

bool Entity::isActivated()
{
    return mIsActivated;
}

void Entity::remove()
{
    mIsRemoved = true;
}

bool Entity::isRemoved()
{
    return mIsRemoved;
}

bool Entity::hasComponent(std::string const& type)
{
    return mComponents.find(type) != mComponents.end();
}

void Entity::removeAllComponents()
{
    mComponents.clear();
}

std::size_t Entity::getComponentCount()
{
    return mComponents.size();
}

std::size_t Entity::getId() const
{
    return mId;
}

ComponentArray& Entity::getComponents()
{
    return mComponents;
}
