#ifndef TME_SHAPE_HPP
#define TME_SHAPE_HPP

#include <vector>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace tme
{

class Shape : public sf::Drawable, public sf::Transformable
{
    public:
        Shape();

        bool intersects(sf::FloatRect rect) const;
        bool contains(sf::Vector2f dot) const;
        sf::FloatRect getBounds(sf::Vector2f pos = sf::Vector2f(0,0)) const;
        void setPrimitiveType(sf::PrimitiveType type);
        sf::PrimitiveType getPrimitiveType() const;
        unsigned int getVertexCount() const;

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:
        std::vector<sf::Vertex> mVertices;
        sf::PrimitiveType mType;
};

} // namespace tme

#endif // TME_SHAPE_HPP
