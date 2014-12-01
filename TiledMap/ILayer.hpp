#ifndef TME_ILAYER_HPP
#define TME_ILAYER_HPP

#include <memory>
#include <string>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Properties.hpp"

namespace tme
{

class ILayer : public Properties, public sf::Transformable
{
    public:
        typedef std::shared_ptr<ILayer> Ptr;

        enum LayerType
        {
            I,
            Layer,
            ImageLayer,
            ObjectGroup,
        };

    public:
        ILayer();

        virtual void render(sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect relativeToMapRect = sf::FloatRect(0,0,0,0));

        virtual LayerType getLayerType() const;

        virtual std::string getName() const;
        virtual void setName(std::string const& name);

        virtual sf::Vector2i getPosition() const;
        virtual void setPosition(sf::Vector2i position);

        virtual sf::Vector2i getSize() const;
        virtual void setSize(sf::Vector2i size);

        virtual float getOpacity() const;
        virtual void setOpacity(float opacity);

        virtual bool isVisible() const;
        virtual void setVisible(bool visible);

        virtual sf::FloatRect getBounds() const;

    protected:
        LayerType mType;
        std::string mName;
        sf::Vector2i mPosition;
        sf::Vector2i mSize;
        float mOpacity;
        bool mVisible;
};

} // namespace tme

#endif // TME_ILAYER_HPP
