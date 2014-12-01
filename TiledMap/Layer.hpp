#ifndef TME_LAYER_HPP
#define TME_LAYER_HPP

#include <map>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "ILayer.hpp"
#include "Tileset.hpp"
#include "Tile.hpp"

namespace tme
{

class Map;

class Layer : public ILayer
{
    public:
        typedef std::shared_ptr<Layer> Ptr;
        typedef std::pair<int,int> Pos;

    public:
        Layer(Map* map);

        void render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMapRect = sf::FloatRect(0,0,0,0));

        int getTileId(int x, int y);
        void setTileId(int x, int y, int id);
        TileData getTileData(int x, int y);

        void setOpacity(float opacity);

        sf::FloatRect getBounds() const;

    private:
        Map* mMap;

        std::map<Pos,Tile> mTiles;
};

} // namespace tme

#endif // TME_LAYER_HPP
