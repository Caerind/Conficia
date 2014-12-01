#ifndef APP_RESOURCEMANAGER_HPP
#define APP_RESOURCEMANAGER_HPP

#include <map>
#include <memory>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <Thor/Resources.hpp>

namespace app
{

class ResourceManager
{
    public:
        ResourceManager();

        template<typename T>
        T& get(std::string const& name);

        template<typename T>
        std::shared_ptr<T> getPtr(std::string const& name);

        template<typename T>
        void release(std::string const& name);

    protected:
        thor::MultiResourceCache mCache;
};

template<typename T>
T& ResourceManager::get(std::string const& name)
{
    return *mCache.acquire(thor::Resources::fromFile<T>(name));
}

template<typename T>
std::shared_ptr<T> ResourceManager::getPtr(std::string const& name)
{
    return mCache.acquire(thor::Resources::fromFile<T>(name));
}

template<typename T>
void ResourceManager::release(std::string const& name)
{
    mCache.release(thor::Resources::fromFile<T>(name));
}

} // namespace app

#endif // APP_RESOURCEMANAGER_HPP
