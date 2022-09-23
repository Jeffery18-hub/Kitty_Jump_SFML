#pragma once
#include <SFML/Graphics.hpp>

class Trunk {
private:
    sf::Sprite sTrunk;
    sf::Texture texture;
public:
    Trunk();
    sf::Vector2f getPosition();
    void setPosition(float x,float y);
    void move(float x, float y);
    void draw(sf::RenderWindow& window); 
};


