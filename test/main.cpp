#include "../Source/Application/Application.hpp"
#include "BasicState.hpp"

int main()
{
    cf::Application app;
    app.getWindow().create(800,600,sf::Style::Close);
    app.getStates().registerState<BasicState>(BasicState::getID());
    app.getStates().pushState(BasicState::getID());
    app.run();

    return EXIT_SUCCESS;
}
