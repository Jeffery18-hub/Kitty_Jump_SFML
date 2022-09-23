#include "trunk.hpp"

Trunk::Trunk(){
    texture.loadFromFile("trunk.jpg");
    sTrunk.setTexture(texture);
}

sf::Vector2f Trunk::getPosition(){
    return sTrunk.getPosition();
}

void Trunk::setPosition(float x,float y){
    sTrunk.setPosition(x, y);
}

void Trunk::move(float x, float y){
    sTrunk.move(x, y);
}

void Trunk::draw(sf::RenderWindow &window){
    window.draw(sTrunk);
}
