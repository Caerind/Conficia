#include "StateManager.hpp"

#include <cassert>

namespace cf
{

StateManager::StateManager()
{
}

StateManager::PendingChange::PendingChange(Action action, std::string const& id)
: action(action)
, id(id)
{
}

void StateManager::handleEvent(sf::Event const& event)
{
	for(auto itr = mStates.rbegin(); itr != mStates.rend(); itr++)
	{
		if(!(*itr)->handleEvent(event))
			break;
	}
    applyPendingChanges();
}

void StateManager::update(sf::Time dt)
{
	for(auto itr = mStates.rbegin(); itr != mStates.rend(); itr++)
	{
		if(!(*itr)->update(dt))
			break;
	}
    applyPendingChanges();
}

void StateManager::render()
{
	for(auto itr = mStates.begin(); itr != mStates.end(); itr++)
	{
        (*itr)->render();
	}
}

void StateManager::pushState(std::string const& id)
{
	mPendingList.push_back(PendingChange(Push, id));
}

void StateManager::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateManager::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

std::size_t StateManager::getSize() const
{
	return mStates.size();
}

bool StateManager::isEmpty() const
{
	return mStates.empty();
}

State::Ptr StateManager::createState(std::string const& id)
{
	auto found = mFactories.find(id);
	assert(found != mFactories.end());
	return found->second();
}

void StateManager::applyPendingChanges()
{
	for(PendingChange change : mPendingList)
	{
		switch(change.action)
		{
			case(Push):
				mStates.push_back(createState(change.id));
				mStates.back()->onActivate();
				break;

			case(Pop):
			{
				mStates.back()->onDestroy();
				mStates.pop_back();
				if (!mStates.empty())
					mStates.back()->onActivate();
            } break;

			case(Clear):
			{
				for(auto itr = mStates.begin(); itr != mStates.end(); itr++)
                {
                    (*itr)->onDestroy();
                }
				mStates.clear();
            } break;
		}
	}
	mPendingList.clear();
}

}
