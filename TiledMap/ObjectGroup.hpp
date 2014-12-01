#ifndef TME_OBJECTGROUP_HPP
#define TME_OBJECTGROUP_HPP

#include <vector>

#include "ILayer.hpp"
#include "Image.hpp"
#include "Object.hpp"

namespace tme
{

class Map;

class ObjectGroup : public ILayer
{
    public:
        typedef std::shared_ptr<ObjectGroup> Ptr;

    public:
        ObjectGroup(Map* map);

        void render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMap);

        std::string getColor() const;
        void setColor(std::string const& color);
        void setOpacity(float opacity);

        int getObjectCount() const;
        Object::Ptr getObject(std::string const& name);
        Object::Ptr getObject(int id);
        void setObject(Object::Ptr object);

        std::vector<Object::Ptr> objectIntersects(sf::FloatRect rect);
        std::vector<Object::Ptr> objectContains(sf::Vector2f dot);

    private:
        Map* mMap;

        std::string mColor; // The color used to display the objects in this group.

        std::vector<Object::Ptr> mObjects;
};

} // namespace tme

#endif // TME_OBJECTGROUP_HPP
