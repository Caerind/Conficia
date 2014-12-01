TiledMapEngine
==============

Features :

- Support all types of Tiled Map (orthogonnal, isometric & staggered)
- Resource System to easily share Image/Texture
- Loading/Saving .tmx & .tsx files
- Only draw what you want

Example :

#include <SFML/Graphics.hpp>
#include "include/Manager.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"TiledMapEngine - test", sf::Style::Close);
    sf::View v = window.getView();

    tme::Manager mgr;
    mgr.loadMap("temp.tmx");

    sf::RectangleShape s;
    s.setPosition(400,300);
    s.setSize(sf::Vector2f(16,26));
    s.setOrigin(sf::Vector2f(8,13));
    s.setOutlineColor(sf::Color::Red);
    s.setOutlineThickness(1);
    s.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Vector2i pos = sf::Vector2i(s.getPosition().x / mgr.getMap("temp.tmx")->getTileSize().x, s.getPosition().y / mgr.getMap("temp.tmx")->getTileSize().y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            pos.y--;
            if (!mgr.getMap("temp.tmx")->getLayer("1")->getTileData(pos.x,pos.y).getBool("isWater")
             && !mgr.getMap("temp.tmx")->getLayer("2")->getTileData(pos.x,pos.y).getBool("isCollide"))
                s.move(0,-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            pos.x--;
            if (!mgr.getMap("temp.tmx")->getLayer("1")->getTileData(pos.x,pos.y).getBool("isWater")
             && !mgr.getMap("temp.tmx")->getLayer("2")->getTileData(pos.x,pos.y).getBool("isCollide"))
                s.move(-1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            pos.y++;
            if (!mgr.getMap("temp.tmx")->getLayer("1")->getTileData(pos.x,pos.y).getBool("isWater")
             && !mgr.getMap("temp.tmx")->getLayer("2")->getTileData(pos.x,pos.y).getBool("isCollide"))
                s.move(0,1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            pos.x++;
            if (!mgr.getMap("temp.tmx")->getLayer("1")->getTileData(pos.x,pos.y).getBool("isWater")
             && !mgr.getMap("temp.tmx")->getLayer("2")->getTileData(pos.x,pos.y).getBool("isCollide"))
                s.move(1,0);
        }
        v.setCenter(s.getPosition());

        window.clear();

        window.setView(v);

        for (int i = 0; i < 10; i++)
        {
            mgr.render(i,window);
        }

        window.draw(s);

        window.display();
    }


    return EXIT_SUCCESS;
}
