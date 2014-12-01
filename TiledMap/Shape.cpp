#include "Shape.hpp"

namespace tme
{

Shape::Shape()
{
}

bool Shape::intersects(sf::FloatRect rect) const
{
    for (float x = rect.left; x <= rect.left + rect.width; x++)
    {
        if (contains(sf::Vector2f(x,rect.top)) || contains(sf::Vector2f(x,rect.top + rect.height)))
            return true;
    }
    for (float y = rect.top; y <= rect.top + rect.height; y++)
    {
        if (contains(sf::Vector2f(rect.left,y)) || contains(sf::Vector2f(rect.left + rect.width,y)))
            return true;
    }
    return false;
}

bool Shape::contains(sf::Vector2f dot) const
{
    dot -= getPosition();
    for (unsigned int i = 0; i < mVertices.size(); i++)
    {
        sf::Vector2f a = mVertices[i].position, b;
        if (i == mVertices.size() - 1)
            b = mVertices[0].position - a;
        else
            b = mVertices[i + 1].position - a;
        if (b.x * (dot.y - a.y) - b.y * (dot.x - a.x) < 0)
            return false;
    }
    return true;
}

sf::FloatRect Shape::getBounds(sf::Vector2f pos) const
{
    sf::FloatRect rect;
    for (unsigned int i = 0; i < mVertices.size(); i++)
    {
        sf::Vector2f vertice = mVertices[i].position;
        if (vertice.x < rect.left)
            rect.left = vertice.x;
        if (vertice.y < rect.top)
            rect.top = vertice.y;
        if (vertice.x - pos.x > rect.width)
            rect.width = vertice.x - pos.x;
        if (vertice.y - pos.y > rect.height)
            rect.height = vertice.y - pos.y;
    }
    return rect;
}

void Shape::setPrimitiveType(sf::PrimitiveType type)
{
    mType = type;
}

sf::PrimitiveType Shape::getPrimitiveType() const
{
    return mType;
}

unsigned int Shape::getVertexCount() const
{
    return mVertices.size();
}

void Shape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(&mVertices[0],mVertices.size(),mType,states);
}

} // namespace tme
