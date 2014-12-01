#ifndef TME_MAP_HPP
#define TME_MAP_HPP

#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "../ExtLibs/pugixml.hpp"

#include "ILayer.hpp"
#include "ImageLayer.hpp"
#include "Layer.hpp"
#include "Object.hpp"
#include "ObjectGroup.hpp"
#include "ParserUtils.hpp"
#include "Properties.hpp"
#include "Tileset.hpp"

namespace tme
{

class Manager;

class Map : public Properties, public sf::Transformable
{
    public:
        typedef std::shared_ptr<Map> Ptr;

    public:
        Map();
        Map(Manager* manager);
        ~Map();

        bool loadFromFile(std::string const& filename);
        bool saveToFile(std::string const& filename = "");

        void render(int layer, sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates(), sf::FloatRect rect = sf::FloatRect(0,0,0,0));
        void render(int layer, sf::RenderTarget& target, sf::FloatRect rect, sf::RenderStates states = sf::RenderStates());

        float getVersion() const;
        std::string getOrientation() const;
        sf::Vector2i getSize() const;
        sf::Vector2i getTileSize() const;
        std::string getBackgroundColor() const;
        std::string getRenderOrder() const;

        Tileset::Ptr getTileset(int gid);
        Tileset::Ptr getTileset(std::string const& name);
        Layer::Ptr getLayer(int id);
        Layer::Ptr getLayer(std::string const& name);
        ImageLayer::Ptr getImageLayer(int id);
        ImageLayer::Ptr getImageLayer(std::string const& name);
        ObjectGroup::Ptr getObjectGroup(int id);
        ObjectGroup::Ptr getObjectGroup(std::string const& name);

        int getLayerCount() const;
        int getTilesetCount() const;
        int getImageLayerCount() const;
        int getObjectGroupCount() const;
        int getILayerCount() const;

        Manager* getManager() const;

        void setVersion(float version);
        void setOrientation(std::string const& orientation);
        void setSize(sf::Vector2i size);
        void setTileSize(sf::Vector2i tileSize);
        void setBackgroundColor(std::string const& backgroundColor);
        void setRenderOrder(std::string const& renderOrder);
        void setTileset(Tileset::Ptr tileset);
        void setLayer(Layer::Ptr layer);
        void setImageLayer(ImageLayer::Ptr image);
        void setObjectGroup(ObjectGroup::Ptr group);

        sf::FloatRect getBounds() const;

        std::vector<Object::Ptr> objectIntersects(sf::FloatRect rect);
        std::vector<Object::Ptr> objectContains(sf::Vector2f dot);

        static void saveProperties(std::ofstream& stream, Properties* properies, int indent);

    private:
        bool parseProperties(pugi::xml_node node, Properties* properties);
        bool parseTileset(pugi::xml_node node); // Including Image
        bool parseILayer(pugi::xml_node node, ILayer::Ptr layer);
        bool parseLayer(pugi::xml_node node); // Including Tiles
        bool parseImageLayer(pugi::xml_node node); // Including Image
        bool parseObjectGroup(pugi::xml_node node); // Including Objects

    private:
        void saveTilesets(std::ofstream& stream);
        void saveLayers(std::ofstream& stream);
        void saveLayer(std::ofstream& stream, std::string const& name);
        void saveImageLayer(std::ofstream& stream, std::string const& name);
        void saveObjectGroup(std::ofstream& stream, std::string const& name);

    private:
        static std::string getDirectory(std::string const& filename);

    private:
        Manager* mManager;
        std::string mFilename;

        float mVersion; // The TMX format version, generally 1.0.
        std::string mOrientation; // Map orientation. Tiled supports "orthogonal", "isometric" and "staggered" (since 0.9) at the moment.
        sf::Vector2i mSize; // Map Size in tiles
        sf::Vector2i mTileSize; // Tile Size in pixels
        std::string mBackgroundColor; // The background color of the map. (since 0.9, optional)
        std::string mRenderOrder; // The order in which tiles on tile layers are rendered. Valid values are right-down (the default), right-up, left-down and left-up. In all cases, the map is drawn row-by-row. (since 0.10, but only supported for orthogonal maps at the moment)

        std::map<std::string,Tileset::Ptr> mTilesets;
        std::map<std::string,Layer::Ptr> mLayers;
        std::map<std::string,ObjectGroup::Ptr> mObjectGroups;
        std::map<std::string,ImageLayer::Ptr> mImageLayers;
        std::vector<ILayer::Ptr> mILayers;
};

} // namespace tme

#endif // TME_MAP_HPP
