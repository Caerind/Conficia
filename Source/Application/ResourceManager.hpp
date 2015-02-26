#ifndef CONFICIA_RESOURCEMANAGER_HPP
#define CONFICIA_RESOURCEMANAGER_HPP

#include <map>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace cf
{

class ResourceManager
{
    public:
        ResourceManager();

        sf::Texture& getTexture(std::string const& filename);
        sf::Font& getFont(std::string const& filename);

        bool loadTexture(std::string const& filename);
        bool loadFont(std::string const& filename);

        bool hasTexture(std::string const& filename);
        bool hasFont(std::string const& filename);

        void releaseTexture(std::string const& filename);
        void releaseFont(std::string const& filename);

    protected:
        std::map<std::string,sf::Texture> mTextures;
        std::map<std::string,sf::Font> mFonts;
};

}

#endif // CONFICIA_RESOURCEMANAGER_HPP
