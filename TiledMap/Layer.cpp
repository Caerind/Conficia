#include "Layer.hpp"
#include "Map.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Layer::Layer(Map* map) : mMap(map)
{
    mType = LayerType::Layer;
}

////////////////////////////////////////////////////////////
void Layer::render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMapRect)
{
    if (mVisible)
    {
        states.transform *= getTransform();
        if (relativeToMapRect == sf::FloatRect(0,0,0,0))
        {
            for (int j = 0; j < mSize.y; j++)
                for (int i = 0; i < mSize.x; i++)
                    target.draw(mTiles[Layer::Pos(i,j)]);
        }
        else
        {
           for (int j = 0; j < mSize.y; j++)
                for (int i = 0; i < mSize.x; i++)
                    if (mTiles[Layer::Pos(i,j)].getBounds().intersects(relativeToMapRect))
                        target.draw(mTiles[Layer::Pos(i,j)]);
        }
    }
}

////////////////////////////////////////////////////////////
int Layer::getTileId(int x, int y)
{
    return (x >= 0 && x < mSize.x && y >= 0 && y < mSize.y) ? mTiles[Layer::Pos(x,y)].getId() : 0;
}

////////////////////////////////////////////////////////////
void Layer::setTileId(int x, int y, int id)
{
    Tile tile;
    if (mMap != nullptr)
    {
        tile.load(mMap,id);
        if (x >= 0 && x < mSize.x && y >= 0 && y < mSize.y)
        {
            if(tile.getTileset() != nullptr && mMap != nullptr)
            {
                int mapTileWidth = mMap->getTileSize().x;
                int mapTileHeight = mMap->getTileSize().y;
                int width = tile.getTileset()->getTileSize().x;
                int height = tile.getTileset()->getTileSize().y;

                if (mMap->getOrientation() == "orthogonal")
                    tile.setTilePos(x * mapTileWidth, y * mapTileHeight, width, height);
                else if (mMap->getOrientation() == "isometric")
                    tile.setTilePos((x-y) * mapTileWidth * 0.5,(x+y) * mapTileHeight * 0.5,width,height);
                else if (mMap->getOrientation() == "staggered")
                {
                    int posX;
                    if ((y % 2) == 0)
                        posX = x * mapTileWidth;
                    else
                        posX = x * mapTileWidth + mapTileWidth / 2;
                    tile.setTilePos(posX,y * mapTileHeight / 2,width,height);
                }
                mTiles[Layer::Pos(x,y)] = tile;
            }
        }
    }
}

////////////////////////////////////////////////////////////
TileData Layer::getTileData(int x, int y)
{
    int id = getTileId(x,y);
    if (mMap != nullptr)
    {
        Tileset::Ptr tileset = mMap->getTileset(id);
        if (tileset != nullptr)
        {
            return tileset->getTile(id-1);
        }
    }
    return TileData();
}

////////////////////////////////////////////////////////////
void Layer::setOpacity(float opacity)
{
    mOpacity = opacity;
    for (auto itr = mTiles.begin(); itr != mTiles.end(); itr++)
        itr->second.setOpacity(opacity);
}

////////////////////////////////////////////////////////////
sf::FloatRect Layer::getBounds() const
{
    sf::FloatRect r = ILayer::getBounds();
    if (mMap != nullptr)
    {
        r.width *= mMap->getTileSize().x;
        r.height *= mMap->getTileSize().y;
    }
    return r;
}

} // namespace tme
