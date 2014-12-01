#ifndef TME_TILE_HPP
#define TME_TILE_HPP

#include "Tileset.hpp"
#include "Shape.hpp"

namespace tme
{

class Map;

class Tile: public Shape
{
    public:
        Tile();

        void load(Map* map, int id);
        void setTilePos(int x, int y, int width, int height);

        int getId() const;
        void setId(int id);

        Tileset::Ptr getTileset() const;
        void setTileset(Tileset::Ptr tileset);

        void setOpacity(float opacity);

        sf::FloatRect getBounds() const;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        int mId; // The global tile ID.

        Tileset::Ptr mTileset;
};

} // namespace tme

#endif // TME_TILE_HPP
