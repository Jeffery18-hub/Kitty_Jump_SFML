//The Way To Heaven
//Jun Li, Zidong Fan
//Sep 22, 2022

#include <SFML/Audio.hpp>
#include "player.hpp"
#include "trunk.hpp"
using namespace sf;

int main()
{
    // create a window
    RenderWindow window(VideoMode(1280, 720), "The Way to Heaven");
    window.setFramerateLimit(60);

    // load background
    Texture t1;
    t1.loadFromFile("background.jpg");
    Sprite sBackground(t1);
    
    // load sound
    sf::Music music;
    if (!music.openFromFile("bgm.wav"))
        return -1; // error
    music.play();
    music.setLoop(true);
    sf::SoundBuffer sBuffer;
        if (!sBuffer.loadFromFile("meow.wav"))
            return -1;
    sf::Sound sound(sBuffer);
    
    // create roles
    Player player{};//one player
    Trunk trunks[10];// multiple truncks
    
    
    // create trunks in random location
    for (int i = 0; i < 10; ++i)
    {
        trunks[i].setPosition(rand() % 1280,rand() % 720);
    }
    
    // game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // player move
        player.move();
        
        // loop trunks
        if (player.getPosition().y < 200)
        {
            for (int i = 0; i < 10; ++i)
            {
                player.setPosition(player.getPosition().x, 200);
                trunks[i].move(0, -player.getVelocity().y);// move the trunks
                
                if (trunks[i].getPosition().y > 720)
                {
                    trunks[i].setPosition(rand()% 1280, 0);
                }
            }
        }
        
        
        //Pixel edge detection for player and trunk
        for (int i = 0; i < 10; ++i)
        {
            if ((player.getPosition().x + 80 > trunks[i].getPosition().x)
                && (player.getPosition().x < trunks[i].getPosition().x + 64)
                && (player.getPosition().y + 80 > trunks[i].getPosition().y)
                && (player.getPosition().y + 80 < trunks[i].getPosition().y + 14)
                && (player.getVelocity().y > 0) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                player.setVelocity(player.getVelocity().x, -12);
                sound.play();
            }
            else if((player.getPosition().x + 80 > trunks[i].getPosition().x)
                    && (player.getPosition().x < trunks[i].getPosition().x + 64)
                    && (player.getPosition().y + 80 > trunks[i].getPosition().y)
                    && (player.getPosition().y + 80 < trunks[i].getPosition().y + 14)
                    && (player.getVelocity().y > 0)){
                player.setVelocity(player.getVelocity().x, -0.5);
            }
        }

        // render
        window.clear();
        window.draw(sBackground);
        player.draw(window);

        for (int i = 0; i < 10; ++i)
        {
            trunks[i].draw(window);
        }
        
        window.display();
        
        // if die, return to center
        if (player.getPosition().y > 720) {
            player.setPosition(640, 360);
            player.setVelocity(0, -5);
        }
    }
}
