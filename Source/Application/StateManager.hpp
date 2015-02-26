#ifndef CONFICIA_STATEMANAGER_HPP
#define CONFICIA_STATEMANAGER_HPP

#include <functional>
#include <map>
#include <vector>

#include "State.hpp"

namespace cf
{

class StateManager
{
    public:
		enum Action
		{
			Push,
			Pop,
			Clear
		};

	public:
		StateManager();

		template<typename T>
		void registerState(std::string const& id);

		void update(sf::Time dt);
		void render();
		void handleEvent(sf::Event const& event);

		void pushState(std::string const& id);
		void popState();
		void clearStates();

		bool isEmpty() const;
		std::size_t getSize() const;


		void applyPendingChanges();

	protected:
		struct PendingChange
		{
			explicit PendingChange(Action action, std::string const& id = "");
			Action action;
			std::string id;
		};

	protected:
		State::Ptr createState(std::string const& id);

		std::vector<State::Ptr> mStates;
		std::vector<PendingChange> mPendingList;

		std::map<std::string, std::function<State::Ptr()>> mFactories;
};

template<typename T>
void StateManager::registerState(std::string const& id)
{
	mFactories[id] = [this] ()
	{
		return State::Ptr(new T(*this));
	};
}

}

#endif // CONFICIA_STATEMANAGER_HPP
