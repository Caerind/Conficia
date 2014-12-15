#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <cassert>

#include "Component.hpp"

class EntityManager;

class Entity
{
    public:
        typedef std::shared_ptr<Entity> Ptr;

        Entity();
        Entity(EntityManager* manager);

        template<typename T>
        T& addComponent(T* component);

        template<typename T>
        bool hasComponent();

        bool hasComponent(std::string const& type);

        template<typename T>
        void removeComponent();

        void removeAllComponents();

        template<typename T>
        T& getComponent();

        std::size_t getId() const;

        ComponentArray& getComponents();

        void setManager(EntityManager* manager);

        void submitAddComponent();
        void submitRemoveComponent();

    protected:
        static std::size_t IdCounter;

        std::size_t mId;
        ComponentArray mComponents;
        EntityManager* mManager;
};


template<typename T>
T& Entity::addComponent(T* component)
{
    mComponents[T::getType()] = component;
    submitAddComponent();
    return *component;
}

template<typename T>
bool Entity::hasComponent()
{
    if (mComponents.find(T::getType()) != mComponents.end())
    {
        return true;
    }
    return false;
}

template<typename T>
void Entity::removeComponent()
{
    if (hasComponent<T>())
    {
        mComponents.erase(mComponents.find(T::getType()));
        submitRemoveComponent();
    }
}

template<typename T>
T& Entity::getComponent()
{
    assert(hasComponent<T>());

    return static_cast<T&>(*mComponents[T::getType()]);
}

#endif // ENTITY_HPP
