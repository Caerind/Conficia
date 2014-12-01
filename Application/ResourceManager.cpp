#include "ResourceManager.hpp"

namespace app
{

ResourceManager::ResourceManager()
{
}

bool ResourceManager::loadTexture(std::string const& name, std::string const& filename)
{
    sf::Texture tex;
    if (tex.loadFromFile(filename))
    {
        mTextures[name] = tex;
        return true;
    }
    else
    {
        return false;
    }
}

sf::Texture& ResourceManager::getTexture(std::string const& name)
{
    if (mTextures.find(name) == mTextures.end())
    {
        assert(false);
    }
    return mTextures[name];
}

void ResourceManager::releaseTexture(std::string const& name)
{
    mTextures.erase(mTextures.find(name));
}

bool ResourceManager::loadFont(std::string const& name, std::string const& filename)
{
    sf::Font fnt;
    if (fnt.loadFromFile(filename))
    {
        mFonts[name] = fnt;
        return true;
    }
    else
    {
        return false;
    }
}

sf::Font& ResourceManager::getFont(std::string const& name)
{
    if (mFonts.find(name) == mFonts.end())
    {
        assert(false);
    }
    return mFonts[name];
}

void ResourceManager::releaseFont(std::string const& name)
{
    mFonts.erase(mFonts.find(name));
}

} // namespace app
