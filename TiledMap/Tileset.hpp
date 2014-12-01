#ifndef TME_TILESET_HPP
#define TME_TILESET_HPP

#include <fstream>
#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "Image.hpp"
#include "Properties.hpp"
#include "TileData.hpp"

namespace tme
{

class Manager;

class Tileset : public Image, public Properties
{
    public:
        typedef std::shared_ptr<Tileset> Ptr;

    public:
        Tileset(Manager* manager);

        bool saveToFile(std::string const& filename = "");

        int getFirstGid() const;
        std::string getFilename() const;
        std::string getName() const;
        sf::Vector2i getTileSize() const;
        int getSpacing() const;
        int getMargin() const;
        sf::Vector2i getTileOffset() const;
        TileData getTile(int id);

        int getLastGid() const;
        sf::IntRect getTextureRect(int id) const;

        void setFirstGid(int first);
        void setFilename(std::string const& filename);
        void setName(std::string const& name);
        void setTileSize(sf::Vector2i size);
        void setSpacing(int spacing);
        void setMargin(int margin);
        void setTileOffset(sf::Vector2i offset);
        void addTile(TileData const& tile);

        // Only used by Map in Saving
        TileData getTileInContainer(int id) const;
        int getTileCount() const;

    private:
        int getTilesPerRow() const;
        int getTilesPerCol() const;

    private:
        int mFirstGid; // The first global tile ID of this tileset (this global ID maps to the first tile in this tileset).
        std::string mFilename; // If this tileset is stored in an external TSX (Tile Set XML) file, this attribute refers to that file. That TSX file has the same structure as the <tileset> element described here. (There is the firstgid attribute missing and this source attribute is also not there. These two attributes are kept in the TMX map, since they are map specific.)
        std::string mName; // The name of this tileset.
        sf::Vector2i mTileSize; // The maximum size of the tiles in this tileset.
        int mSpacing; // The spacing in pixels between the tiles in this tileset (applies to the tileset image).
        int mMargin; // The margin around the tiles in this tileset (applies to the tileset image).
        sf::Vector2i mTileOffset; // Tile Offset
        std::map<int, TileData> mTiles;
};

} // namespace tme

#endif // TME_TILESET_HPP
