#include "Tileset.hpp"
#include "Manager.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Tileset::Tileset(Manager* mgr) : Image(mgr), mFilename(""), mSpacing(0), mMargin(0)
{
}

////////////////////////////////////////////////////////////
bool Tileset::saveToFile(std::string const& filename)
{
    std::ofstream file((filename == "") ? mFilename : filename);
    if (!file)
        return false;

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;

    file << "<tileset name=\"" << mName << "\"";
    file << " tilewidth=\"" << mTileSize.x << "\"";
    file << " tileheight=\"" << mTileSize.y << "\"";
    if (mSpacing != 0)
        file << " spacing=\"" << mSpacing << "\"";
    if (mMargin != 0)
        file << " margin=\"" << mMargin << "\"";
    file << ">" << std::endl;

    if (mTileOffset != sf::Vector2i(0,0))
        file << " <tileoffset x=\"" << mTileOffset.x << "\" y=\"" << mTileOffset.y << "\"/>" << std::endl;

    Map::saveProperties(file,this,1);

    file << " <image source=\"" << mSource;
    file << "\" trans=\"" << mTrans;
    file << "\" width=\"" << mSize.x;
    file << "\" height=\"" << mSize.y;
    file << "\"/>" << std::endl;

    for (auto itr = mTiles.begin(); itr != mTiles.end(); itr++)
    {
        file << " <tile id=\"" << itr->second.getId();
        if (itr->second.getTerrain() != "")
            file << "\" terrain=\"" <<itr->second.getTerrain();
        if (itr->second.getProbability() != 0.0f)
            file << "\" probability=\"" << itr->second.getProbability();
        if(!itr->second.isEmpty())
        {
            file << "\">" << std::endl;
            Map::saveProperties(file,&itr->second,2);
            file << " </tile>" << std::endl;
        }
        else
        {
            file << "\"/>" << std::endl;
        }
    }

    file << "</tileset>" << std::endl;

    return true;
}

////////////////////////////////////////////////////////////
int Tileset::getFirstGid() const
{
    return mFirstGid;
}

////////////////////////////////////////////////////////////
std::string Tileset::getFilename() const
{
    return mFilename;
}

////////////////////////////////////////////////////////////
std::string Tileset::getName() const
{
    return mName;
}

////////////////////////////////////////////////////////////
sf::Vector2i Tileset::getTileSize() const
{
    return mTileSize;
}

////////////////////////////////////////////////////////////
int Tileset::getSpacing() const
{
    return mSpacing;
}

////////////////////////////////////////////////////////////
int Tileset::getMargin() const
{
    return mMargin;
}

////////////////////////////////////////////////////////////
sf::Vector2i Tileset::getTileOffset() const
{
    return mTileOffset;
}

////////////////////////////////////////////////////////////
TileData Tileset::getTile(int id)
{
    return mTiles[id];
}

////////////////////////////////////////////////////////////
int Tileset::getLastGid() const
{
    return mFirstGid + getTilesPerRow() * getTilesPerCol() - 1;
}

////////////////////////////////////////////////////////////
sf::IntRect Tileset::getTextureRect(int id) const
{
    sf::IntRect rect(0,0,mTileSize.x,mTileSize.y);
    id -= mFirstGid;
    if (id >= 0 && id < getTilesPerRow() * getTilesPerCol())
    {
        rect.left = mMargin + (id % getTilesPerRow()) * (mTileSize.x + mSpacing);
        rect.top = mMargin + (id / getTilesPerRow()) * (mTileSize.y + mSpacing);
    }
    return rect;
}

////////////////////////////////////////////////////////////
void Tileset::setFirstGid(int first)
{
    mFirstGid = first;
}

////////////////////////////////////////////////////////////
void Tileset::setFilename(std::string const& filename)
{
    mFilename = filename;
}

////////////////////////////////////////////////////////////
void Tileset::setName(std::string const& name)
{
    mName = name;
}

////////////////////////////////////////////////////////////
void Tileset::setTileSize(sf::Vector2i size)
{
    mTileSize = size;
}

////////////////////////////////////////////////////////////
void Tileset::setSpacing(int spacing)
{
    mSpacing = spacing;
}

////////////////////////////////////////////////////////////
void Tileset::setMargin(int margin)
{
    mMargin = margin;
}

////////////////////////////////////////////////////////////
void Tileset::setTileOffset(sf::Vector2i offset)
{
    mTileOffset = offset;
}

////////////////////////////////////////////////////////////
void Tileset::addTile(TileData const& tile)
{
    mTiles[tile.getId()] = tile;
}

////////////////////////////////////////////////////////////
TileData Tileset::getTileInContainer(int id) const
{
    if (id < 0 || id >= getTileCount())
        return TileData();
    int i = 0;
    for (auto itr = mTiles.begin(); itr != mTiles.end(); itr++)
    {
        if (i == id)
            return itr->second;
        i++;
    }
    return TileData();
}

////////////////////////////////////////////////////////////
int Tileset::getTileCount() const
{
    return static_cast<int>(mTiles.size());
}

////////////////////////////////////////////////////////////
int Tileset::getTilesPerRow() const
{
    if (mTileSize.x == 0)
        return 0;
    int width = mSize.x - (mMargin * 2);
    int finalWidth = 0;
    if (mSpacing != 0)
    {
        for (int i = 0; i <= width;)
        {
            i += mTileSize.x + mSpacing;
            finalWidth += mTileSize.x;
        }
    }
    else
        finalWidth = width;
    return (finalWidth / mTileSize.x);
}

////////////////////////////////////////////////////////////
int Tileset::getTilesPerCol() const
{
    if (mTileSize.y == 0)
        return 0;
    int height = mSize.y - (mMargin * 2);
    int finalHeight = 0;
    if (mSpacing != 0)
    {
        for (int i = 0; i <= height;)
        {
            i += mTileSize.y + mSpacing;
            finalHeight += mTileSize.y;
        }
    }
    else
        finalHeight = height;
    return (finalHeight / mTileSize.y);
}

} // namespace tme
