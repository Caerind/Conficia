#include "Statistics.hpp"

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
	mNumFrames++;
	if (mUpdateTime >= sf::seconds(1.0f))
	{
		mText.setString("FPS: " + std::to_string(mNumFrames));

		mUpdateTime -= sf::seconds(1.0f);
		mNumFrames = 0;
	}
}

void Statistics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText,states);
}
