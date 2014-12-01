#include "Map.hpp"

namespace tme
{

////////////////////////////////////////////////////////////
Map::Map() : mManager(nullptr), mVersion(1.0f), mOrientation(""), mSize(0,0), mTileSize(0,0)
, mBackgroundColor(""), mRenderOrder("")
{
}

////////////////////////////////////////////////////////////
Map::Map(Manager* manager) : mManager(manager), mVersion(1.0f), mOrientation(""), mSize(0,0), mTileSize(0,0)
, mBackgroundColor(""), mRenderOrder("")
{
}

////////////////////////////////////////////////////////////
Map::~Map()
{
    /*
    if (mSaveOnDestroy)
    {
        //
        //
        //
    }
    */
}

////////////////////////////////////////////////////////////
bool Map::loadFromFile(std::string const& filename)
{
    pugi::xml_document tmxFile;
    if (!tmxFile.load_file(filename.c_str()))
        return false;
    mFilename = filename;

    pugi::xml_node node;
    if (!(node = tmxFile.child("map")))
        return false;

    for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute())
    {
        std::string attrName = attr.name();
        if (attrName == "version") mVersion = attr.as_float();
        else if (attrName == "orientation") mOrientation = attr.value();
        else if (attrName == "width") mSize.x = attr.as_int();
        else if (attrName == "height") mSize.y = attr.as_int();
        else if (attrName == "tilewidth") mTileSize.x = attr.as_int();
        else if (attrName == "tileheight") mTileSize.y = attr.as_int();
        else if (attrName == "backgroundcolor") mBackgroundColor = attr.value();
        else if (attrName == "renderorder") mRenderOrder = attr.value();
    }

    for (pugi::xml_node n : node.children())
    {
        std::string nName = n.name();
        if (nName == "properties")
            if (!parseProperties(n,this))
                return false;
        if (nName == "tileset")
            if (!parseTileset(n))
                return false;
        if (nName == "layer")
            if (!parseLayer(n))
                return false;
        if (nName == "imagelayer")
            if (!parseImageLayer(n))
                return false;
        if (nName == "objectgroup")
            if (!parseObjectGroup(n))
                return false;
    }

    return true;
}

////////////////////////////////////////////////////////////
bool Map::saveToFile(std::string const& filename)
{
    std::ofstream file((filename != "") ? filename : mFilename);
    if (!file)
        return false;

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    file << "<map version=\"" << mVersion << "\" orientation=\"" << mOrientation << "\" width=\"" << mSize.x << "\" height=\"" << mSize.y << "\"";
    file << " tilewidth=\"" << mTileSize.x << "\" tileheight=\"" << mTileSize.y;
    if (mBackgroundColor != "")
        file << "\" backgroundcolor=\"" << mBackgroundColor;
    if (mRenderOrder != "")
        file << "\" renderorder=\"" << mRenderOrder;
    file << "\">" << std::endl;

    saveProperties(file,this,1);
    saveTilesets(file);
    saveLayers(file);

    file << "</map>" << std::endl;
    file.close();
    return true;
}

////////////////////////////////////////////////////////////
void Map::render(int layer, sf::RenderTarget& target, sf::RenderStates states, sf::FloatRect rect)
{
    states.transform *= getTransform();

    if (layer == 0 && mBackgroundColor != "")
    {
        sf::RectangleShape background;
        background.setSize(sf::Vector2f(mSize.x * mTileSize.x, mSize.y * mTileSize.y));
        background.setFillColor(Image::getColor(mBackgroundColor));
        target.draw(background,states);
    }

    if (rect == sf::FloatRect(0,0,0,0))
    {
        if (layer >= 0 && layer < getILayerCount() && mILayers[layer] != nullptr)
        {
            // Rect is now relative to map pos
            rect.left -= getPosition().x;
            rect.top -= getPosition().y;
            mILayers[layer]->render(target,states,rect);
        }
    }
    else
        render(layer,target,rect,states);
}

////////////////////////////////////////////////////////////
void Map::render(int layer, sf::RenderTarget& target, sf::FloatRect rect, sf::RenderStates states)
{
    if (layer >= 0 && layer < getILayerCount())
    {
        if (mILayers[layer] != nullptr)
        {
            if (mILayers[layer]->getBounds().intersects(rect) || mILayers[layer]->getLayerType() == ILayer::ObjectGroup)
            {
                // Rect is now relative to map pos
                rect.left -= getPosition().x;
                rect.top -= getPosition().y;
                mILayers[layer]->render(target,states,rect);
            }
        }
    }
}

////////////////////////////////////////////////////////////
float Map::getVersion() const
{
    return mVersion;
}

////////////////////////////////////////////////////////////
std::string Map::getOrientation() const
{
    return mOrientation;
}

////////////////////////////////////////////////////////////
sf::Vector2i Map::getSize() const
{
    return mSize;
}

////////////////////////////////////////////////////////////
sf::Vector2i Map::getTileSize() const
{
    return mTileSize;
}

////////////////////////////////////////////////////////////
std::string Map::getBackgroundColor() const
{
    return mBackgroundColor;
}

////////////////////////////////////////////////////////////
std::string Map::getRenderOrder() const
{
    return mRenderOrder;
}

////////////////////////////////////////////////////////////
Tileset::Ptr Map::getTileset(int gid)
{
    for (auto itr = mTilesets.begin(); itr != mTilesets.end(); itr++)
        if (gid >= itr->second->getFirstGid() && gid <= itr->second->getLastGid())
            return itr->second;
    return nullptr;
}

////////////////////////////////////////////////////////////
Tileset::Ptr Map::getTileset(std::string const& name)
{
    return (mTilesets.find(name) != mTilesets.end()) ? mTilesets[name] : nullptr;
}

////////////////////////////////////////////////////////////
Layer::Ptr Map::getLayer(int id)
{
    if (id >= getLayerCount() || id < 0)
        return nullptr;
    int i = 0;
    for (auto itr = mLayers.begin(); itr != mLayers.end(); itr++)
    {
        if (id == i)
            return itr->second;
        i++;
    }
    return nullptr;
}

////////////////////////////////////////////////////////////
Layer::Ptr Map::getLayer(std::string const& name)
{
    return (mLayers.find(name) != mLayers.end()) ? mLayers[name] : nullptr;
}

////////////////////////////////////////////////////////////
ImageLayer::Ptr Map::getImageLayer(int id)
{
    if (id >= getImageLayerCount() || id < 0)
        return nullptr;
    int i = 0;
    for (auto itr = mImageLayers.begin(); itr != mImageLayers.end(); itr++)
    {
        if (id == i)
            return itr->second;
        i++;
    }
    return nullptr;
}

////////////////////////////////////////////////////////////
ImageLayer::Ptr Map::getImageLayer(std::string const& name)
{
    return (mImageLayers.find(name) != mImageLayers.end()) ? mImageLayers[name] : nullptr;
}

////////////////////////////////////////////////////////////
ObjectGroup::Ptr Map::getObjectGroup(int id)
{
    if (id >= getObjectGroupCount() || id < 0)
        return nullptr;
    int i = 0;
    for (auto itr = mObjectGroups.begin(); itr != mObjectGroups.end(); itr++)
    {
        if (id == i)
            return itr->second;
        i++;
    }
    return nullptr;
}

////////////////////////////////////////////////////////////
ObjectGroup::Ptr Map::getObjectGroup(std::string const& name)
{
    return (mObjectGroups.find(name) != mObjectGroups.end()) ? mObjectGroups[name] : nullptr;
}

////////////////////////////////////////////////////////////
int Map::getLayerCount() const
{
    return mLayers.size();
}

////////////////////////////////////////////////////////////
int Map::getTilesetCount() const
{
    return mTilesets.size();
}

////////////////////////////////////////////////////////////
int Map::getImageLayerCount() const
{
    return mImageLayers.size();
}

////////////////////////////////////////////////////////////
int Map::getObjectGroupCount() const
{
    return mObjectGroups.size();
}

////////////////////////////////////////////////////////////
int Map::getILayerCount() const
{
    return mILayers.size();
}

////////////////////////////////////////////////////////////
Manager* Map::getManager() const
{
    return mManager;
}

////////////////////////////////////////////////////////////
void Map::setVersion(float version)
{
    mVersion = version;
}

////////////////////////////////////////////////////////////
void Map::setOrientation(std::string const& orientation)
{
    mOrientation = orientation;
}

////////////////////////////////////////////////////////////
void Map::setSize(sf::Vector2i size)
{
    mSize = size;
}


////////////////////////////////////////////////////////////
void Map::setTileSize(sf::Vector2i tileSize)
{
    mTileSize = tileSize;
}

////////////////////////////////////////////////////////////
void Map::setBackgroundColor(std::string const& backgroundColor)
{
    mBackgroundColor = backgroundColor;
}

////////////////////////////////////////////////////////////
void Map::setRenderOrder(std::string const& renderOrder)
{
    mRenderOrder = renderOrder;
}

////////////////////////////////////////////////////////////
void Map::setTileset(Tileset::Ptr tileset)
{
    if (tileset != nullptr)
        mTilesets[tileset->getName()] = tileset;
}

////////////////////////////////////////////////////////////
void Map::setLayer(Layer::Ptr layer)
{
    if (layer != nullptr)
    {
    	mLayers[layer->getName()] = layer;
    	mILayers.push_back(layer);
    }
}

////////////////////////////////////////////////////////////
void Map::setImageLayer(ImageLayer::Ptr layer)
{
    if (layer != nullptr)
    {
    	mImageLayers[layer->getName()] = layer;
    	mILayers.push_back(layer);
    }
}

////////////////////////////////////////////////////////////
void Map::setObjectGroup(ObjectGroup::Ptr group)
{
    if (group != nullptr)
    {
        mObjectGroups[group->getName()] = group;
    	mILayers.push_back(group);
    }
}

////////////////////////////////////////////////////////////
sf::FloatRect Map::getBounds() const
{
    return sf::FloatRect(getPosition(), sf::Vector2f(getSize().x * getTileSize().x, getSize().y * getTileSize().y));
}

////////////////////////////////////////////////////////////
std::vector<Object::Ptr> Map::objectIntersects(sf::FloatRect rect)
{
    rect.left -= getPosition().x;
    rect.width -= getPosition().y;

    std::vector<Object::Ptr> objects;
    for (auto itr = mObjectGroups.begin(); itr != mObjectGroups.end(); itr++)
    {
        std::vector<Object::Ptr> objectsIntersects = itr->second->objectIntersects(rect);
        for (unsigned int i = 0; i < objectsIntersects.size(); i++)
            objects.push_back(objectsIntersects[i]);
    }
    return objects;
}

////////////////////////////////////////////////////////////
std::vector<Object::Ptr> Map::objectContains(sf::Vector2f dot)
{
    dot -= getPosition();
    std::vector<Object::Ptr> objects;
    for (auto itr = mObjectGroups.begin(); itr != mObjectGroups.end(); itr++)
    {
        std::vector<Object::Ptr> objectsContains = itr->second->objectContains(dot);
        for (unsigned int i = 0; i < objectsContains.size(); i++)
            objects.push_back(objectsContains[i]);
    }
    return objects;
}

////////////////////////////////////////////////////////////
bool Map::parseProperties(pugi::xml_node node, Properties* properties)
{
    if (properties == nullptr)
        return false;

    if (node)
        for (auto property : node.children("property"))
            properties->setProperty(std::string(property.attribute("name").as_string()), std::string(property.attribute("value").as_string()));
    return true;
}

////////////////////////////////////////////////////////////
bool Map::parseTileset(pugi::xml_node node)
{
    Tileset::Ptr tileset = std::shared_ptr<Tileset>(new Tileset(this->getManager()));
    tileset->setFirstGid(node.attribute("firstgid").as_int());

    pugi::xml_attribute source = node.attribute("source");
    if (source)
    {
        pugi::xml_document tsx;
        if (!tsx.load_file(std::string(getDirectory(mFilename) + source.as_string()).c_str()))
            return false;
        node = tsx.child("tileset");
    }

    tileset->setName(node.attribute("name").as_string());

    sf::Vector2i size = sf::Vector2i(0,0);
    size.x = node.attribute("tilewidth").as_int();
    size.y = node.attribute("tileheight").as_int();
    tileset->setTileSize(size);

    pugi::xml_attribute spacing = node.attribute("spacing");
    if (spacing) tileset->setSpacing(spacing.as_int());

    pugi::xml_attribute margin = node.attribute("margin");
    if (margin) tileset->setMargin(margin.as_int());

    for (const pugi::xml_node& n : node.children())
    {
        std::string nName = n.name();
        if (nName == "tileoffset")
        {
            sf::Vector2i offset;
            offset.x = n.attribute("x").as_int();
            offset.y = n.attribute("y").as_int();
            tileset->setTileOffset(offset);
        }
        else if (nName == "image")
        {
            if (n.attribute("trans"))
                tileset->setTrans(n.attribute("trans").as_string());
            if (n.attribute("source"))
                if (!tileset->load(std::string(getDirectory(mFilename) + n.attribute("source").as_string())))
                    return false;
        }
        else if (nName == "properties")
            if (!parseProperties(n,tileset.get()))
                return false;
    }

    for (const pugi::xml_node& tile_node : node.children("tile"))
    {
        TileData tile;
        if (tile_node.attribute("id")) tile.setId(tile_node.attribute("id").as_int());
        if (tile_node.attribute("terrain")) tile.setTerrain(tile_node.attribute("terrain").as_string());
        if (tile_node.attribute("probability")) tile.setProbability(tile_node.attribute("probability").as_float());

        pugi::xml_node prop = tile_node.child("properties");
        if (prop)
            if (!parseProperties(prop,&tile))
                return false;
        tileset->addTile(tile);
    }

    mTilesets[tileset->getName()] = tileset;
    return true;
}

////////////////////////////////////////////////////////////
bool Map::parseILayer(pugi::xml_node node, ILayer::Ptr layer)
{
    if (layer == nullptr)
        return false;

    pugi::xml_attribute attribute_name = node.attribute("name");
    pugi::xml_attribute attribute_x = node.attribute("x");
    pugi::xml_attribute attribute_y = node.attribute("y");
    pugi::xml_attribute attribute_width = node.attribute("width");
    pugi::xml_attribute attribute_height = node.attribute("height");
    pugi::xml_attribute attribute_opacity = node.attribute("opacity");
    pugi::xml_attribute attribute_visible = node.attribute("visible");

    if (attribute_name)
        layer->setName(attribute_name.as_string());

    sf::Vector2i position = sf::Vector2i(0,0);
    if (attribute_x)
        position.x = attribute_x.as_int();
    if (attribute_y)
        position.y = attribute_y.as_int();
    layer->setPosition(position);

    sf::Vector2i size = sf::Vector2i(0,0);
    if (attribute_width)
        size.x = attribute_width.as_int();
    else
        size.x = getSize().x;
    if (attribute_height)
        size.y = attribute_height.as_int();
    else
        size.y = getSize().y;
    layer->setSize(size);

    if (attribute_opacity)
        layer->setOpacity(attribute_opacity.as_float());

    if (attribute_visible)
        layer->setVisible(attribute_visible.as_bool());

    return true;
}

////////////////////////////////////////////////////////////
bool Map::parseLayer(pugi::xml_node node)
{
    Layer::Ptr layer = std::shared_ptr<Layer>(new Layer(this));

    parseILayer(node,layer);

    for (const pugi::xml_node& n : node.children())
    {
        std::string nName = n.name();
        if (nName == "properties")
        {
            if (!parseProperties(n,layer.get()))
                return false;
        }
        else if (nName == "data")
        {
            std::string data = n.text().as_string();
            Tile tile;
            int posX = 0;
            int posY = 0;
            pugi::xml_attribute attribute_encoding = n.attribute("encoding");
            if (attribute_encoding)
            {
                std::string encoding = attribute_encoding.as_string();
                if (encoding == "base64") // Base64 encoding
                {
                    std::stringstream ss;
                    ss << data;
                    ss >> data;
                    if (!ParserUtils::base64_decode(data))
                        return false;

                    int expectedSize = layer->getSize().x * layer->getSize().y * 4;  // number of tiles * 4 bytes = 32bits / tile
                    std::vector<unsigned char> byteVector;  // to hold decompressed data as bytes
                    byteVector.reserve(expectedSize);

                    if (n.attribute("compression"))
                    {
                        if (!ParserUtils::decompressString(data))
                            return false;
                        for (std::string::iterator i = data.begin(); i != data.end(); ++i)
                            byteVector.push_back(*i);
                    }
                    else
                        for (std::string::iterator i = data.begin(); i != data.end(); ++i)
                            byteVector.push_back(*i);

                    for (unsigned int i = 0; i < byteVector.size() - 3 ; i += 4)
                    {
                        layer->setTileId(posX,posY,byteVector[i] | byteVector[i + 1] << 8 | byteVector[i + 2] << 16 | byteVector[i + 3] << 24);

                        posX = (posX + 1) % layer->getSize().x;
                        if (posX == 0) posY++;
                    }
                }
                else if (encoding == "csv") // CSV encoding
                {
                    int id;
                    std::stringstream data_stream(data);
                    while (data_stream >> id)
                    {
                        if (data_stream.peek() == ',')
                            data_stream.ignore();

                        layer->setTileId(posX,posY,id);

                        posX = (posX + 1) % layer->getSize().x;
                        if (posX == 0) posY++;
                    }
                }
            }
            else // Unencoded
            {
                for (const pugi::xml_node& tile_node : n.children("tile"))
                {
                    layer->setTileId(posX,posY,tile_node.attribute("gid").as_int());

                    posX = (posX + 1) % layer->getSize().x;
                    if (posX == 0) posY++;
                }
            }
        }
    }

    setLayer(layer);
    return true;
}

////////////////////////////////////////////////////////////
bool Map::parseImageLayer(pugi::xml_node node)
{
    ImageLayer::Ptr layer = std::shared_ptr<ImageLayer>(new ImageLayer(this->getManager()));

    parseILayer(node,layer);

    for (const pugi::xml_node& n : node.children())
    {
        std::string nName = n.name();
        if (nName == "properties")
        {
            if (!parseProperties(n,layer.get()))
                return false;
        }
        else if (nName == "image")
        {
            if (n.attribute("trans"))
                layer->setTrans(n.attribute("trans").as_string());
            if (n.attribute("source"))
                if (!layer->loadFromFile(std::string(getDirectory(mFilename) + n.attribute("source").as_string())))
                    return false;
        }
    }

    setImageLayer(layer);
    return true;
}

////////////////////////////////////////////////////////////
bool Map::parseObjectGroup(pugi::xml_node node)
{
    ObjectGroup::Ptr layer = std::shared_ptr<ObjectGroup>(new ObjectGroup(this));

    pugi::xml_attribute attribute_color = node.attribute("color");
    if (attribute_color)
        layer->setColor(attribute_color.as_string());

    parseILayer(node,layer);

    for (const pugi::xml_node& n : node.children())
    {
        std::string nName = n.name();
        if (nName == "properties")
        {
            if (!parseProperties(n,layer.get()))
                return false;
        }
        else if (nName == "object")
        {
            Object::Ptr obj = std::shared_ptr<Object>(new Object(this));
            Object::Type type = Object::Rectangle;

            if (n.attribute("gid"))
            {
                type = Object::Tile;
                obj->setGid(n.attribute("gid").as_int());
            }
            else
            {
                for (const pugi::xml_node& objSettings : n.children())
                {
                    std::string name = objSettings.name();
                    if (name == "ellipse")
                        type = Object::Ellipse;
                    else if (name == "polygon")
                    {
                        type = Object::Polygon;
                        obj->setPoints(objSettings.attribute("points").as_string());
                    }
                    else if (name == "polyline")
                    {
                        type = Object::Polyline;
                        obj->setPoints(objSettings.attribute("points").as_string());
                    }
                    else if (name == "properties")
                        if (!parseProperties(objSettings,obj.get()))
                            return false;
                }
            }

            pugi::xml_attribute attribute_x = n.attribute("x");
            pugi::xml_attribute attribute_y = n.attribute("y");
            pugi::xml_attribute attribute_width = n.attribute("width");
            pugi::xml_attribute attribute_height = n.attribute("height");
            pugi::xml_attribute attribute_rotation = n.attribute("rotation");
            pugi::xml_attribute attribute_visible = n.attribute("visible");

            sf::Vector2i pos;
            if (attribute_x) pos.x = attribute_x.as_int();
            if (attribute_y) pos.y = attribute_y.as_int();
            obj->setPosition(pos);

            sf::Vector2i size;
            if (attribute_width) size.x = attribute_width.as_int();
            if (attribute_height) size.y = attribute_height.as_int();
            obj->setSize(size);

            if (attribute_rotation)
                obj->setRotation(attribute_rotation.as_float());
            if (attribute_visible)
                obj->setVisible(attribute_visible.as_int());

            obj->setType(type);
            layer->setObject(obj);
        }
    }

    setObjectGroup(layer);
    return true;
}

////////////////////////////////////////////////////////////
void Map::saveProperties(std::ofstream& stream, Properties* properties, int indent)
{
    if (properties != nullptr)
    {
        if (!properties->isEmpty())
        {
            for (int i = 0; i < indent; i++)
                stream << " ";
            stream << "<properties>" << std::endl;
            for (int i = 0; i < properties->getPropertyCount(); i++)
            {
                Properties::Property p = properties->getProperty(i);
                if (p.first != "")
                {
                    for (int i = 0; i < indent + 1; i++)
                        stream << " ";
                    stream << "<property name=\"" << p.first << "\" value=\"" << p.second << "\"/>" << std::endl;
                }
            }
            for (int i = 0; i < indent; i++)
                stream << " ";
            stream << "</properties>" << std::endl;
        }
    }
}

////////////////////////////////////////////////////////////
void Map::saveTilesets(std::ofstream& stream)
{
    for (auto itr = mTilesets.begin(); itr != mTilesets.end(); itr++)
    {
        if (itr->second != nullptr && mFilename == "")
        {
            stream << " <tileset firstgid=\"" << itr->second->getFirstGid() << "\"";
            stream << " name=\"" << itr->second->getName() << "\"";
            stream << " tilewidth=\"" << itr->second->getTileSize().x << "\"";
            stream << " tileheight=\"" << itr->second->getTileSize().y << "\"";
            if (itr->second->getSpacing() != 0)
                stream << " spacing=\"" << itr->second->getSpacing() << "\"";
            if (itr->second->getMargin() != 0)
                stream << " margin=\"" << itr->second->getMargin() << "\"";
            stream << ">" << std::endl;

            if (itr->second->getTileOffset().x != 0 || itr->second->getTileOffset().y != 0)
            {
                stream << "  <tileoffset x=\"" << itr->second->getTileOffset().x;
                stream << "\" y=\"" << itr->second->getTileOffset().y;
                stream << "\"/>" << std::endl;
            }

            saveProperties(stream,itr->second.get(),2);

            stream << "  <image source=\"" << itr->second->getSource();
            stream << "\" trans=\"" << itr->second->getTrans();
            stream << "\" width=\"" << itr->second->getSize().x;
            stream << "\" height=\"" << itr->second->getSize().y;
            stream << "\"/>" << std::endl;

            for (int i = 0; i < itr->second->getTileCount(); i++)
            {
                TileData tile = itr->second->getTileInContainer(i);
                stream << "  <tile id=\"" << tile.getId();
                if (tile.getTerrain() != "")
                    stream << "\" terrain=\"" << tile.getTerrain();
                if (tile.getProbability() != 0.0f)
                    stream << "\" probability=\"" << tile.getProbability();
                if(!tile.isEmpty())
                {
                    stream << "\">" << std::endl;
                    saveProperties(stream,&tile,3);
                    stream << "  </tile>" << std::endl;
                }
                else
                    stream << "\"/>" << std::endl;
            }

            stream << " </tileset>" << std::endl;
        }
        else if (itr->second != nullptr && mFilename != "")
            itr->second->saveToFile(itr->second->getFilename());
    }
}

////////////////////////////////////////////////////////////
void Map::saveLayers(std::ofstream& stream)
{
    for (auto itr = mILayers.begin(); itr != mILayers.end(); itr++)
    {
        if ((*itr)->getLayerType() == ILayer::Layer)
            saveLayer(stream,(*itr)->getName());
        else if ((*itr)->getLayerType() == ILayer::ImageLayer)
            saveImageLayer(stream,(*itr)->getName());
        else if ((*itr)->getLayerType() == ILayer::ObjectGroup)
            saveObjectGroup(stream,(*itr)->getName());
    }
}

////////////////////////////////////////////////////////////
void Map::saveLayer(std::ofstream& stream, std::string const& name)
{
    Layer::Ptr layer = getLayer(name);
    if (layer != nullptr)
    {
        stream << " <layer name=\"" << layer->getName() << "\"";
        if (layer->getPosition().x != 0)
            stream << " x=\"" << layer->getPosition().x << "\"";
        if (layer->getPosition().y != 0)
            stream << " y=\"" << layer->getPosition().y << "\"";
        stream << " width=\"" << layer->getSize().x << "\"";
        stream << " height=\"" << layer->getSize().y << "\"";
        if (layer->getOpacity() != 1.f)
            stream << " opacity=\"" << layer->getOpacity() << "\"";
        if (!layer->isVisible())
            stream << " visible=\"" << layer->isVisible() << "\"";
        stream << ">" << std::endl;

        saveProperties(stream,layer.get(),2);

        stream << "  <data encoding=\"base64\" compression=\"zlib\">" << std::endl;

        std::string data;
        data.reserve(layer->getSize().x * layer->getSize().y * 4);
        for (int y = 0; y < layer->getSize().y; y++)
        {
            for (int x = 0; x < layer->getSize().x; x++)
            {
                const unsigned gid = layer->getTileId(x,y);
                data.push_back((char) (gid));
                data.push_back((char) (gid >> 8));
                data.push_back((char) (gid >> 16));
                data.push_back((char) (gid >> 24));
            }
        }

        ParserUtils::compressString(data);
        ParserUtils::base64_encode(data);

        stream << "   " << data << std::endl << "  </data>" << std::endl << " </layer>" << std::endl;
    }
}

////////////////////////////////////////////////////////////
void Map::saveImageLayer(std::ofstream& stream, std::string const& name)
{
    ImageLayer::Ptr layer = getImageLayer(name);
    if (layer != nullptr)
    {
        stream << " <imagelayer name=\"" << layer->getName() << "\"";
        if (layer->getPosition().x != 0)
            stream << " x=\"" << layer->getPosition().x << "\"";
        if (layer->getPosition().y != 0)
            stream << " y=\"" << layer->getPosition().y << "\"";
        stream << " width=\"" << layer->ILayer::getSize().x << "\"";
        stream << " height=\"" << layer->ILayer::getSize().y << "\"";
        if (layer->getOpacity() != 1.f)
            stream << " opacity=\"" << layer->getOpacity() << "\"";
        if (!layer->isVisible())
            stream << " visible=\"" << layer->isVisible() << "\"";
        stream << ">" << std::endl;

        stream << "  <image source=\"" << layer->getSource();
        stream << "\" trans=\"" << layer->getTrans();
        stream << "\" width=\"" << layer->Image::getSize().x;
        stream << "\" height=\"" << layer->Image::getSize().y;
        stream << "\"/>" << std::endl;

        saveProperties(stream,layer.get(),2);

        stream << " </imagelayer>" << std::endl;
    }
}

////////////////////////////////////////////////////////////
void Map::saveObjectGroup(std::ofstream& stream, std::string const& name)
{
    ObjectGroup::Ptr layer = getObjectGroup(name);
    if (layer != nullptr)
    {
        stream << " <objectgroup";
        if (layer->getColor() != "")
            stream << " color=\"" << layer->getColor() << "\"";
        stream << " name=\"" << layer->getName() << "\"";
        if (layer->getPosition().x != 0)
            stream << " x=\"" << layer->getPosition().x << "\"";
        if (layer->getPosition().y != 0)
            stream << " y=\"" << layer->getPosition().y << "\"";
        stream << " width=\"" << layer->getSize().x << "\"";
        stream << " height=\"" << layer->getSize().y << "\"";
        if (layer->getOpacity() != 1.f)
            stream << " opacity=\"" << layer->getOpacity() << "\"";
        if (!layer->isVisible())
            stream << " visible=\"" << layer->isVisible() << "\"";
        stream << ">" << std::endl;

        saveProperties(stream,layer.get(),2);

        for (int i = 0; i < layer->getObjectCount(); i++)
        {
            Object::Ptr obj = layer->getObject(i);
            if (obj != nullptr)
            {
                stream << "  <object";
                switch (obj->getType())
                {
                    case Object::Rectangle:
                    {
                        stream << " x=\"" << obj->getPosition().x << "\"";
                        stream << " y=\"" << obj->getPosition().y << "\"";
                        stream << " width=\"" << obj->getSize().x << "\"";
                        stream << " height=\"" << obj->getSize().y << "\"";
                        if (obj->getRotation() != 0.f)
                            stream << " rotation=\"" << obj->getRotation() << "\"";
                        if (!obj->isVisible())
                            stream << " visible=\"" << obj->isVisible() << "\"";
                        stream << "/>" << std::endl;
                    } break;

                    case Object::Ellipse:
                    {
                        stream << " x=\"" << obj->getPosition().x << "\"";
                        stream << " y=\"" << obj->getPosition().y << "\"";
                        stream << " width=\"" << obj->getSize().x << "\"";
                        stream << " height=\"" << obj->getSize().y << "\"";
                        if (obj->getRotation() != 0.f)
                            stream << " rotation=\"" << obj->getRotation() << "\"";
                        if (!obj->isVisible())
                            stream << " visible=\"" << obj->isVisible() << "\"";
                        stream << ">" << std::endl << "   <ellipse/>" << std::endl << "  </object>" << std::endl;
                    } break;

                    case Object::Polygon:
                    {
                        stream << " x=\"" << obj->getPosition().x << "\"";
                        stream << " y=\"" << obj->getPosition().y << "\"";
                        if (obj->getRotation() != 0.f)
                            stream << " rotation=\"" << obj->getRotation() << "\"";
                        if (!obj->isVisible())
                            stream << " visible=\"" << obj->isVisible() << "\"";
                        stream << ">" << std::endl << "   <polygon points=\"" << obj->getPoints() << "\"/>" << std::endl;
                        stream << "  </object>" << std::endl;
                    } break;

                    case Object::Polyline:
                    {
                        stream << " x=\"" << obj->getPosition().x << "\"";
                        stream << " y=\"" << obj->getPosition().y << "\"";
                        if (obj->getRotation() != 0.f)
                            stream << " rotation=\"" << obj->getRotation() << "\"";
                        if (!obj->isVisible())
                            stream << " visible=\"" << obj->isVisible() << "\"";
                        stream << ">" << std::endl;
                        stream << "   <polyline points=\"" << obj->getPoints() << "\"/>" << std::endl;
                        stream << "  </object>" << std::endl;
                    } break;

                    case Object::Tile:
                    {
                        stream << " gid=\"" << obj->getGid() << "\"";
                        stream << " x=\"" << obj->getPosition().x << "\"";
                        stream << " y=\"" << obj->getPosition().y << "\"";
                        if (obj->getRotation() != 0.f)
                            stream << " rotation=\"" << obj->getRotation() << "\"";
                        if (!obj->isVisible())
                            stream << " visible=\"" << obj->isVisible() << "\"";
                        stream << "/>" << std::endl;
                    } break;

                    default: break;
                }
            }
        }
        stream << " </objectgroup>" << std::endl;
    }
}

////////////////////////////////////////////////////////////
std::string Map::getDirectory(std::string const& filename)
{
    return filename.substr(0, filename.find_last_of('/') + 1);
}

} // namespace tme
