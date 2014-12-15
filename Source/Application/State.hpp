#ifndef STATE_HPP
#define STATE_HPP

#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class StateManager;

class State
{
    public:
        static std::string getID();

    public:
        typedef std::unique_ptr<State> Ptr;

    public:
        State(StateManager& manager);
        virtual ~State();

        virtual bool handleEvent(sf::Event const& event);
        virtual bool update(sf::Time dt);
        virtual void render();

        virtual void onActivate();
        virtual void onDestroy();

    protected:
        void requestPush(std::string const& id);
        void requestPop();
        void requestClear();

    protected:
        StateManager& mManager;
};

#endif // STATE_HPP
