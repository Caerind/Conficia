#ifndef TME_TILEDATA_HPP
#define TME_TILEDATA_HPP

#include <memory>
#include <string>

#include "Properties.hpp"

namespace tme
{

class TileData : public Properties
{
    public:
        typedef std::shared_ptr<TileData> Ptr;

    public:
        TileData();

        int getId() const;
        std::string getTerrain() const;
        float getProbability() const;

        void setId(int id);
        void setTerrain(std::string const& terrain);
        void setProbability(float probability);

    private:
        int mId; // The local tile ID within its tileset.
        std::string mTerrain; // Defines the terrain type of each corner of the tile, given as comma-separated indexes in the terrain types array in the order top-left, top-right, bottom-left, bottom-right. Leaving out a value means that corner has no terrain. (optional) (since 0.9.0)
        float mProbability; // A percentage indicating the probability that this tile is chosen when it competes with others while editing with the terrain tool. (optional) (since 0.9.0)
};

} // namespace tme

#endif // TME_TILEDATA_HPP
