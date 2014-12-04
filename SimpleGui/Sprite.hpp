#ifndef SGUI_SPRITE_H
#define SGUI_SPRITE_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace SGUI
{

class Sprite
{
    public:
        Sprite(size_t textureCount);

        void setTexture(sf::Texture& texture);

        void setTextureRect(sf::IntRect textureRect, size_t index = 0);
        void useTextureRect(size_t index);

        sf::Vector2f getSize() const;
        void setSize(sf::Vector2f newSize);
        void setSize(float x, float y);

    protected:
        sf::Sprite mSprite;
        std::vector<sf::IntRect> mTextureRects;
};

}

#endif // SGUI_SPRITE_H
