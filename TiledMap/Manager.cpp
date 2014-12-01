#include "Manager.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Manager::Manager()
{
}

////////////////////////////////////////////////////////////
Manager::~Manager()
{
    //TODO : Fix a bug here ...
}

////////////////////////////////////////////////////////////
void Manager::render(int layer, sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect rect)
{
    states.transform *= getTransform();
    if (rect == sf::FloatRect(0,0,0,0))
    {
        for (auto itr = mMaps.begin(); itr != mMaps.end(); itr++)
        {
            itr->second->render(layer,target,states);
        }
    }
    else
    {
        render(layer,target,rect,states);
    }
}

////////////////////////////////////////////////////////////
void Manager::render(int layer, sf::RenderTarget& target, sf::FloatRect rect, sf::RenderStates states)
{
    for (auto itr = mMaps.begin(); itr != mMaps.end(); itr++)
    {
        if (itr->second->getBounds().intersects(rect))
            itr->second->render(layer,target,rect,states);
    }
}

////////////////////////////////////////////////////////////
bool Manager::loadMap(std::string const& filename)
{
    if (mMaps.find(filename) == mMaps.end())
    {
        Map::Ptr map = std::shared_ptr<Map>(new Map(this));
        if (map->loadFromFile(filename))
        {
            mMaps[filename] = map;
            return true;
        }
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////////////
Map::Ptr Manager::getMap(std::string const& filename)
{
    if (mMaps.find(filename) != mMaps.end())
    {
        return mMaps[filename];
    }
    else
    {
        return nullptr;
    }
}

////////////////////////////////////////////////////////////
Image::Ptr Manager::getImage(std::string const& sourceName)
{
    if (mImages.find(sourceName) != mImages.end())
    {
        return mImages[sourceName];
    }
    else
    {
        return nullptr;
    }
}

////////////////////////////////////////////////////////////
void Manager::addImage(Image::Ptr img)
{
    if (img != nullptr)
    {
        mImages[img->getSource()] = img;
    }
}

////////////////////////////////////////////////////////////
std::vector<Object::Ptr> Manager::objectIntersects(sf::FloatRect rect)
{
    std::vector<Object::Ptr> objects;
    for (auto itr = mMaps.begin(); itr != mMaps.end(); itr++)
    {
        if (itr->second->getBounds().intersects(rect))
        {
            std::vector<Object::Ptr> objectsIntersects = itr->second->objectIntersects(rect);
            for (unsigned int i = 0; i < objectsIntersects.size(); i++)
                objects.push_back(objectsIntersects[i]);
        }
    }
    return objects;
}

////////////////////////////////////////////////////////////
std::vector<Object::Ptr> Manager::objectContains(sf::Vector2f dot)
{
    std::vector<Object::Ptr> objects;
    for (auto itr = mMaps.begin(); itr != mMaps.end(); itr++)
    {
        if (itr->second->getBounds().intersects(sf::FloatRect(dot.x-1,dot.y-1,2,2)))
        {
            std::vector<Object::Ptr> objectsContains = itr->second->objectContains(dot);
            for (unsigned int i = 0; i < objectsContains.size(); i++)
                objects.push_back(objectsContains[i]);
        }
    }
    return objects;
}

} // namespace tme
