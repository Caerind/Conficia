#include "Statistics.hpp"

namespace app
{

Statistics::Statistics()
{
}

sf::Text& Statistics::getText()
{
    return mText;
}

void Statistics::update(sf::Time dt)
{
    mUpdateTime += dt;
	mNumFrames ++;
	if (mUpdateTime >= sf::seconds(1.0f))
	{
		mText.setString("FPS: " + IO::toString(mNumFrames));

		mUpdateTime -= sf::seconds(1.0f);
		mNumFrames = 0;
	}
}

void Statistics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText,states);
}

} // namespace app
