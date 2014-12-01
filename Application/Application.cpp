#include "Application.hpp"

namespace app
{

Application::Application()
{
}

void Application::setState(std::string const& id)
{
    mStates.clearStates();
    mStates.pushState(id);
    mStates.update(sf::Time::Zero);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	while (System::getWindow().isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			handleEvents();
			update(TimePerFrame);

			if (mStates.isEmpty())
                System::getWindow().close();

			std::cout << std::flush; // Need to flush if we want to see something on the console :  http://stackoverflow.com/questions/5437643/strange-behaviour-of-stdcout-in-linux
		}
		render();
	}
}

void Application::handleEvents()
{
    sf::Event event;
    while (System::getWindow().pollEvent(event))
    {
        mStates.handleEvent(event);

        if(event.type == sf::Event::Closed)
        {
            System::getWindow().close();
        }
    }
}

void Application::update(sf::Time const dt)
{
    mStates.update(dt);
}

void Application::render()
{
    System::getWindow().clear();
    mStates.render();
    System::getWindow().display();
}

} // namespace app
