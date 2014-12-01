#include "Image.hpp"
#include "Manager.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Image::Image(Manager* mgr) : mMgr(mgr), mTexture(nullptr), mTrans("")
{
}

////////////////////////////////////////////////////////////
bool Image::load(std::string const& filename)
{
    mSource = filename;

    // Test if the image is already loaded in the sharing system
    if (!loadFromManager())
    {
        sf::Image img;
        if (!img.loadFromFile(mSource))
            return false;

        mFormat = getFormat(mSource);

        if (mTrans != "")
            img.createMaskFromColor(getColor(mTrans));

        mSize.x = img.getSize().x;
        mSize.y = img.getSize().y;

        mTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
        if (mTexture == nullptr)
            return false;

        if (!mTexture->loadFromImage(img, sf::IntRect(0,0,mSize.x,mSize.y)))
            return false;

        // Add image to sharing system
        if (mMgr != nullptr)
            mMgr->addImage(std::shared_ptr<Image>(this));
    }
    return true;
}

////////////////////////////////////////////////////////////
bool Image::loadFromManager()
{
    if (mMgr != nullptr)
    {
        Image::Ptr img = mMgr->getImage(mSource);
        if (img != nullptr)
        {
            setTexture(img->getTexture());
            setFormat(img->getFormat());
            setSource(img->getSource());
            setTrans(img->getTrans());
            setSize(img->getSize());
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////
Image::TexturePtr Image::getTexture() const
{
    return mTexture;
}

////////////////////////////////////////////////////////////
std::string Image::getFormat() const
{
    return mFormat;
}

////////////////////////////////////////////////////////////
std::string Image::getSource() const
{
    return mSource;
}

////////////////////////////////////////////////////////////
std::string Image::getTrans() const
{
    return mTrans;
}

////////////////////////////////////////////////////////////
sf::Vector2i Image::getSize() const
{
    return mSize;
}

////////////////////////////////////////////////////////////
void Image::setTexture(TexturePtr texture)
{
    mTexture = texture;
}

////////////////////////////////////////////////////////////
void Image::setFormat(std::string const& format)
{
    mFormat = format;
}

////////////////////////////////////////////////////////////
void Image::setSource(std::string const& source)
{
    mSource = source;
}

////////////////////////////////////////////////////////////
void Image::setTrans(std::string const& trans)
{
    mTrans = trans;
}

////////////////////////////////////////////////////////////
void Image::setSize(sf::Vector2i size)
{
    mSize = size;
}

////////////////////////////////////////////////////////////
std::string Image::getFormat(std::string const& filename)
{
    return (filename.rfind(".") != std::string::npos) ? filename.substr(filename.rfind(".")+1,filename.size()) : "";
}

////////////////////////////////////////////////////////////
sf::Color Image::getColor(std::string const& hexColor)
{
    if (hexColor != "")
    {
        sf::Color color;
        std::stringstream ss;
        std::string hex = hexColor;

        // If the value as a # as first char
        if (hex.front() == '#')
            hex.erase(0,1);

        for (unsigned int i = 0; i < hexColor.size() / 2; i++)
        {
            ss << std::hex << hex.substr(0,2);
            hex.erase(0,2);
            switch (i)
            {
                case 0: ss >> color.r; break;
                case 1: ss >> color.g; break;
                case 2: ss >> color.b; break;
                case 3: ss >> color.a; break;
                default: break;
            }
            ss.clear();
        }

        return color;
    }
    else
        return sf::Color::White;
}

////////////////////////////////////////////////////////////
std::string Image::getString(sf::Color rgbColor)
{
    std::stringstream ss;
    ss << std::hex << rgbColor.r;
    ss << std::hex << rgbColor.g;
    ss << std::hex << rgbColor.b;
    return ss.str();
}

} // namespace tme
