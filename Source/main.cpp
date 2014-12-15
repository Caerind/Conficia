#include <SFML/Graphics.hpp>

#include <EntityManager.hpp>
#include <SpriteSystem.hpp>
#include <SpriteComponent.hpp>
#include <MoveComponent.hpp>
#include <MoveSystem.hpp>

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    EntityManager mgr;

    sf::Texture texture;
    texture.loadFromFile("test.png");
    auto e = mgr.createEntity();
    e->addComponent<SpriteComponent>(new SpriteComponent()).getSprite().setTexture(texture);
    e->addComponent<MoveComponent>(new MoveComponent()).setSpeed(10.f);

    SpriteSystem system;
    mgr.addSystem(&system);

    MoveSystem moveS;
    mgr.addSystem(&moveS);

    sf::Clock clock;
    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        moveS.update(clock.restart());

        app.clear();
        system.render(app);
        app.display();
    }

    return EXIT_SUCCESS;
}
