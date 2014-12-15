#include "ResourceManager.hpp"
#include "Application.hpp"

ResourceManager::ResourceManager()
{
}

sf::Texture& ResourceManager::getTexture(std::string const& filename)
{
    if (!hasTexture(filename))
    {
        loadTexture(filename);
    }
    return mTextures[filename];
}

sf::Font& ResourceManager::getFont(std::string const& filename)
{
    if (!hasFont(filename))
    {
        loadFont(filename);
    }
    return mFonts[filename];
}

bool ResourceManager::loadTexture(std::string const& filename)
{
    if (!mTextures[filename].loadFromFile(filename))
    {
        Application::getLog() << Log::ERROR << std::string("Failed to load texture : " + filename);
        return false;
    }
    return true;
}

bool ResourceManager::loadFont(std::string const& filename)
{
    if (!mFonts[filename].loadFromFile(filename))
    {
        Application::getLog() << Log::ERROR << std::string("Failed to load font : " + filename);
        return false;
    }
    return true;
}

bool ResourceManager::hasTexture(std::string const& filename)
{
    return mTextures.find(filename) != mTextures.end();
}

bool ResourceManager::hasFont(std::string const& filename)
{
    return mFonts.find(filename) != mFonts.end();
}

void ResourceManager::releaseTexture(std::string const& filename)
{
    if (hasTexture(filename))
    {
        mTextures.erase(mTextures.find(filename));
    }
}

void ResourceManager::releaseFont(std::string const& filename)
{
    if (hasFont(filename))
    {
        mFonts.erase(mFonts.find(filename));
    }
}
