#ifndef APP_APPLICATION_HPP
#define APP_APPLICATION_HPP

#include <iostream>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "System.hpp"
#include "StateManager.hpp"

namespace app
{

class Application
{
    public:
        Application();

        template<typename T>
        void registerState(std::string const& id);

        void setState(std::string const& id);

        void run();

    protected:
        void handleEvents();
        void update(sf::Time const dt);
        void render();

    protected:
        StateManager mStates;
};

template<typename T>
void Application::registerState(std::string const& id)
{
    mStates.registerState<T>(id);
    if (mStates.isEmpty())
    {
        setState(id);
    }
}

} // namespace app

#endif // APP_APPLICATION_HPP
