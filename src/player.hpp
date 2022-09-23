#pragma once
#include <SFML/Graphics.hpp>
#include "trunk.hpp"

class Player{
private:
    sf::Sprite sPlayer; // sprite of player
    sf::Vector2f velocity; // speed of player
    sf::Texture texture;
public:
    Player(); 
    void move();
    sf::Vector2f getPosition();
    void setPosition(float x,float y);
    sf::Vector2f getVelocity();
    void setVelocity(float x,float y);
    void draw(sf:: RenderWindow& window) const;
};

