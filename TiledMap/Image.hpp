#ifndef TME_IMAGE_HPP
#define TME_IMAGE_HPP

#include <memory>
#include <sstream>
#include <string>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace tme
{

class Manager;

class Image
{
    public:
        typedef std::shared_ptr<Image> Ptr;
        typedef std::shared_ptr<sf::Texture> TexturePtr;

    public:
        Image(Manager* manager);

        bool load(std::string const& filename = "");
        bool loadFromManager();

        TexturePtr getTexture() const;
        std::string getFormat() const;
        std::string getSource() const;
        std::string getTrans() const;
        sf::Vector2i getSize() const;

        void setTexture(TexturePtr texture);
        void setFormat(std::string const& format);
        void setSource(std::string const& source);
        void setTrans(std::string const& trans);
        void setSize(sf::Vector2i size);

    public:
        static std::string getFormat(std::string const& filename);
        static sf::Color getColor(std::string const& hexColor);
        static std::string getString(sf::Color rgbColor);

    protected:
        Manager* mMgr;

        TexturePtr mTexture;

        std::string mFormat; // Used for embedded images, in combination with a data child element. Valid values are file extensions like png, gif, jpg, bmp, etc. (since 0.9.0)
        std::string mSource; // The reference to the tileset image file (Tiled supports most common image formats).
        std::string mTrans; // Defines a specific color that is treated as transparent (example value: "#FF00FF" for magenta). Up until Tiled 0.10, this value is written out without a # but this is planned to change.
        sf::Vector2i mSize; // Image size in pixels
};

} // namespace tme

#endif // TME_IMAGE_HPP
