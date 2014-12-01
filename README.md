AudioManager
============

This is the new version of my AudioManager for SFML 2.1 !

See the main.cpp to see how the new version work (lot of major changes !!)

List of actual features :

* File Management : A file can be Music or Sound, and it stored data, filename and name.
* Easy Playing : You have a lot of ways to play your audio, choose the one you want !
* Don't care about ressources : SoundBuffer are managed, you have nothing to do for them !
* Smart Containers : When a Sound/Music is stopped it will automagically be removed if you update the Manager !


EXAMPLE
========

// You only need to include this file
#include <AudioManager.hpp>

#include <SFML/System.hpp>

#include <iostream>

int main()
{
    // Create an instance of AudioManager
    // You will need it to manage Musics and Sounds
    am::AudioManager mgr;

    // Here you create an AudioFile which is also stored in the Manager
    // Notice that you have to choose the type of the file
    // Never create a file yourself, you ALWAYS have to create it from the Manager
    am::AudioFile::Ptr a = mgr.create(am::FileType::Music,"test.ogg","test");


    // Here you want to play the file
    // You have multiple ways to do that (The following lines play the same music) :
    mgr.play("test");   // With the name of the file in the Manager
    mgr.play(a);        // With a pointer of the file
    a->play();          // Directly with the file (The file need to be stored in the Manager, so use Manager::Create)

    sf::Clock clock;
    sf::Time time;
    while(clock.getElapsedTime() < sf::seconds(2))
    {
        // While updating the manager, it removes automatically unused Musics & Sounds
        mgr.update();
    }

    return EXIT_SUCCESS;
}


