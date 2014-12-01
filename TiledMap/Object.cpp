#include "Object.hpp"
#include "Map.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Object::Object(Map* map) : mMap(map), mName(""), mType(Object::Rectangle), mPosition(0,0), mSize(0,0), mRotation(0.f), mGid(0), mVisible(1), mPoints(""), mTileset(nullptr)
{
}

////////////////////////////////////////////////////////////
std::string Object::getName() const
{
    return mName;
}

////////////////////////////////////////////////////////////
Object::Type Object::getType() const
{
    return mType;
}

////////////////////////////////////////////////////////////
sf::Vector2i Object::getPosition() const
{
    return mPosition;
}

////////////////////////////////////////////////////////////
sf::Vector2i Object::getSize() const
{
    return mSize;
}

////////////////////////////////////////////////////////////
float Object::getRotation() const
{
    return mRotation;
}

////////////////////////////////////////////////////////////
int Object::getGid() const
{
    return mGid;
}

////////////////////////////////////////////////////////////
bool Object::isVisible() const
{
    return mVisible;
}

////////////////////////////////////////////////////////////
std::string Object::getPoints() const
{
    std::ostringstream oss;
    for (unsigned int i = 0; i < getVertexCount(); i++)
    {
        oss << mVertices[i].position.x << "," << mVertices[i].position.y << " ";

        if (i == getVertexCount() - 2 && (mType == Object::Polygon || mType == Object::Rectangle))
        {
            break;
        }
    }
    return oss.str();
}

////////////////////////////////////////////////////////////
sf::Vertex* Object::getVertex(int id)
{
    if (id >= 0 && id < static_cast<int>(mVertices.size()))
    {
        return &mVertices[id];
    }
    return nullptr;
}

////////////////////////////////////////////////////////////
void Object::setName(std::string const& name)
{
    mName = name;
}

////////////////////////////////////////////////////////////
void Object::setType(Object::Type type)
{
    mType = type;

    if (mType == Object::Rectangle)
    {
        mVertices.push_back(sf::Vertex(sf::Vector2f(0, 0)));
        mVertices.push_back(sf::Vertex(sf::Vector2f(mSize.x, 0)));
        mVertices.push_back(sf::Vertex(sf::Vector2f(mSize.x, mSize.y)));
        mVertices.push_back(sf::Vertex(sf::Vector2f(0, mSize.y)));
        mVertices.push_back(sf::Vertex(sf::Vector2f(0, 0)));  // Close the rectangle
    }
    else if (mType == Object::Ellipse)
    {
        sf::Vector2f rad(mSize.x / 2.f, mSize.y / 2.f), pos, center(rad.x,rad.y);
        const float PI = 3.14159265358979f, angle = 360.f / (pow(2.f, 3.f + ceil((rad.x + rad.y) / 30)));
        for (float i = 0; i <= 360.f; i+=angle)
            mVertices.push_back(sf::Vertex(sf::Vector2f(center.x + rad.x * cos((i) * PI / 180.f),center.y + rad.y * sin((i) * PI / 180.f))));
    }
    else if (mType == Object::Polygon || mType == Object::Polyline)
    {
        std::stringstream sstream(mPoints);
        sf::Vector2f pos;
        while (sstream >> pos.x)
        {
            if (sstream.peek() == ',')
                sstream.ignore();
            sstream >> pos.y;
            mVertices.push_back(sf::Vertex(pos));
        }
        if (mType == Object::Polygon)
            mVertices.push_back(mVertices[0]);  // Close the polygon
    }
    else if (mType == Object::Tile)
    {
        mVertices.resize(4);
        if (mGid != 0 && mMap != nullptr)
        {
            mTileset = mMap->getTileset(mGid);
            if (mTileset != nullptr)
            {
                sf::IntRect tRect = mTileset->getTextureRect(mGid);

                mVertices[0].position = sf::Vector2f(mTileset->getTileOffset().x, mTileset->getTileOffset().y);
                mVertices[1].position = sf::Vector2f(mTileset->getTileOffset().x + mTileset->getTileSize().x, mTileset->getTileOffset().y);
                mVertices[2].position = sf::Vector2f(mTileset->getTileOffset().x + mTileset->getTileSize().x, mTileset->getTileOffset().y + mTileset->getTileSize().y);
                mVertices[3].position = sf::Vector2f(mTileset->getTileOffset().x, mTileset->getTileOffset().y + mTileset->getTileSize().y);

                mVertices[0].texCoords = sf::Vector2f(tRect.left, tRect.top);
                mVertices[1].texCoords = sf::Vector2f(tRect.left + mTileset->getTileSize().x, tRect.top);
                mVertices[2].texCoords = sf::Vector2f(tRect.left + mTileset->getTileSize().x, tRect.top + mTileset->getTileSize().y);
                mVertices[3].texCoords = sf::Vector2f(tRect.left, tRect.top + mTileset->getTileSize().y);
            }
        }
    }
}

////////////////////////////////////////////////////////////
void Object::setPosition(sf::Vector2i position)
{
    mPosition = position;
    sf::Transformable::setPosition(mPosition.x,mPosition.y);
}

////////////////////////////////////////////////////////////
void Object::setSize(sf::Vector2i size)
{
    mSize = size;
}

////////////////////////////////////////////////////////////
void Object::setRotation(float rotation)
{
    mRotation = rotation;
    sf::Transformable::setRotation(rotation);
}

////////////////////////////////////////////////////////////
void Object::setGid(int gid)
{
    mGid = gid;
    setType(Object::Tile);
}

////////////////////////////////////////////////////////////
void Object::setVisible(bool visible)
{
    mVisible = visible;
}

////////////////////////////////////////////////////////////
void Object::setPoints(std::string const& points)
{
    mPoints = points;
}

////////////////////////////////////////////////////////////
void Object::setVertex(sf::Vertex vertex, int id)
{
    if (id >= 0 && id < static_cast<int>(mVertices.size()))
    {
        mVertices[id] = vertex;
    }
}

////////////////////////////////////////////////////////////
void Object::applyColor(sf::Color color)
{
    for (int i = 0; i < static_cast<int>(mVertices.size()); i++)
    {
        mVertices[i].color = color;
    }
}

////////////////////////////////////////////////////////////
sf::FloatRect Object::getBounds() const
{
    return Shape::getBounds();
}

////////////////////////////////////////////////////////////
void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mVisible)
    {
        states.transform *= getTransform();

        if (mGid != 0)
        {
            //states.texture = ...
            target.draw(&mVertices[0], mVertices.size(), sf::Quads, states);
        }
        else
            target.draw(&mVertices[0], mVertices.size(), sf::LinesStrip, states);
    }
}

} // namespace tme
