#include "State.hpp"
#include "StateManager.hpp"

namespace cf
{

std::string State::getID()
{
    return "State";
}

State::State(StateManager& manager)
: mManager(manager)
{
}

State::~State()
{
}

bool State::handleEvent(sf::Event const& event)
{
    return true;
}

bool State::update(sf::Time dt)
{
    return true;
}

void State::render()
{
}

void State::onActivate()
{

}

void State::onDestroy()
{

}

void State::requestPush(std::string const& id)
{
    mManager.pushState(id);
}

void State::requestPop()
{
    mManager.popState();
}

void State::requestClear()
{
    mManager.clearStates();
}

}
