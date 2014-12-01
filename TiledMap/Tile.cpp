#include "Tile.hpp"
#include "Map.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Tile::Tile() : mId(0), mTileset(nullptr)
{
    mType = sf::Quads;
    mVertices.resize(4);
}

////////////////////////////////////////////////////////////
void Tile::load(Map* map, int id)
{
    setId(id);

    if (map == nullptr)
        return;

    mTileset = map->getTileset(mId);
    if (mTileset != nullptr)
    {
        setPosition(mTileset->getTileOffset().x, mTileset->getTileOffset().y);

        sf::IntRect tRect = mTileset->getTextureRect(mId);

        mVertices[0].texCoords = sf::Vector2f(tRect.left, tRect.top);
        mVertices[1].texCoords = sf::Vector2f(tRect.left + mTileset->getTileSize().x, tRect.top);
        mVertices[2].texCoords = sf::Vector2f(tRect.left + mTileset->getTileSize().x, tRect.top + mTileset->getTileSize().y);
        mVertices[3].texCoords = sf::Vector2f(tRect.left, tRect.top + mTileset->getTileSize().y);
    }
}

////////////////////////////////////////////////////////////
void Tile::setTilePos(int x, int y, int width, int height)
{
    mVertices[0].position = sf::Vector2f(x, y);
    mVertices[1].position = sf::Vector2f(x + width, y);
    mVertices[2].position = sf::Vector2f(x + width, y + height);
    mVertices[3].position = sf::Vector2f(x, y + height);
}

////////////////////////////////////////////////////////////
int Tile::getId() const
{
    return mId;
}

////////////////////////////////////////////////////////////
void Tile::setId(int id)
{
    mId = id;
}

////////////////////////////////////////////////////////////
Tileset::Ptr Tile::getTileset() const
{
    return mTileset;
}

////////////////////////////////////////////////////////////
void Tile::setTileset(Tileset::Ptr tileset)
{
    mTileset = tileset;
}

////////////////////////////////////////////////////////////
void Tile::setOpacity(float opacity)
{
    sf::Color a = sf::Color::White;
    a.a = 255.f * opacity;
    for (int i = 0; i < 4; i++)
        mVertices[i].color = a;
}

////////////////////////////////////////////////////////////
sf::FloatRect Tile::getBounds() const
{
    return sf::FloatRect(getPosition() + mVertices[0].position, mVertices[2].position - mVertices[0].position);
}

////////////////////////////////////////////////////////////
void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mTileset != nullptr)
    {
        states.transform *= getTransform();
        if (mTileset->getTexture() != nullptr)
            states.texture = mTileset->getTexture().get();
        target.draw(&mVertices[0], getVertexCount(), mType, states);
    }
}

}
