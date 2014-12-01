Application
===========

This is my framework using few libs :

- SFML : https://github.com/LaurentGomila/SFML
- Thor : https://github.com/Bromeon/Thor

I've added few others projects in it :

- pugixml : https://github.com/zeux/pugixml
- gzstream : https://github.com/kanedo/gzstream


I got some code & ideas from others projects/authors :

- Group : https://github.com/LaurentGomila/SFML/wiki/Tutorial%3A-Drawable-Group
- SystemInfo : https://github.com/dabbertorres/Swift2/blob/master/src/SystemInfo/SystemInfo.hpp
- SettingsParser : https://github.com/Foaly/SettingsParser/blob/master/SettingsParser/SettingsParser.hpp
- Log : https://github.com/LaurentGomila/SFML/wiki/Source:-Simple-File-Logger-(by-mateandmetal)


Thanks all to help me coding better and faster :)


EXAMPLE :
=========

#include "Application.hpp"
#include "TestState.hpp"

int main()
{
    app::Application app;
    app.registerState<TestState>(TestState::getID());
    app.setState(TestState::getID());
    app.run();
    return EXIT_SUCCESS;
}

#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP

#include "../Sources/State.hpp"

class TestState : public app::State
{
    public:
        static std::string getID();

    public:
        TestState(app::StateManager& manager);

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render();
};

#endif // TESTSTATE_HPP

#include "TestState.hpp"

std::string TestState::getID()
{
    return "Test";
}

TestState::TestState(app::StateManager& manager) : app::State(manager)
{
    app::System::getWindow().create(800,600,"Cool Wind'",sf::Style::Close);
}

bool TestState::handleEvent(sf::Event const& event)
{
    return true;
}

bool TestState::update(sf::Time dt)
{
    return true;
}

void TestState::render()
{
}
