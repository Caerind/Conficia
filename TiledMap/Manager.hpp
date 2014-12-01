#ifndef TME_MANAGER_HPP
#define TME_MANAGER_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Map.hpp"

namespace tme
{

class Manager : public sf::Transformable
{
    public:
        Manager();
        ~Manager();

        void render(int layer, sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates(), sf::FloatRect rect = sf::FloatRect(0,0,0,0));
        void render(int layer, sf::RenderTarget& target, sf::FloatRect rect, sf::RenderStates states = sf::RenderStates());

        bool loadMap(std::string const& filename);
        Map::Ptr getMap(std::string const& filename);

        Image::Ptr getImage(std::string const& sourceName);
        void addImage(Image::Ptr img);

        std::vector<Object::Ptr> objectIntersects(sf::FloatRect rect);
        std::vector<Object::Ptr> objectContains(sf::Vector2f dot);

    private:
        std::map<std::string,Map::Ptr> mMaps;
        std::map<std::string,Image::Ptr> mImages; // Source/Image
};

} // namespace tme

#endif // TME_MANAGER_HPP
