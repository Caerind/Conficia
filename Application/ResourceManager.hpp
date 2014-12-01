#ifndef APP_RESOURCEMANAGER_HPP
#define APP_RESOURCEMANAGER_HPP

#include <map>
#include <cassert>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace app
{

class ResourceManager
{
    public:
        ResourceManager();

        bool loadTexture(std::string const& name, std::string const& filename);
        sf::Texture& getTexture(std::string const& name);
        void releaseTexture(std::string const& name);

        bool loadFont(std::string const& name, std::string const& filename);
        sf::Font& getFont(std::string const& name);
        void releaseFont(std::string const& name);

    protected:
        std::map<std::string,sf::Texture> mTextures;
        std::map<std::string,sf::Font> mFonts;
};

} // namespace app

#endif // APP_RESOURCEMANAGER_HPP
