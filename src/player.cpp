
#include "player.hpp"

Player::Player(){
    texture.loadFromFile("cat.jpg");
    sPlayer.setTexture(texture);

    sPlayer.setPosition(150, 360);
    velocity = sf::Vector2f( 0.f,0.f);
}

void Player::move(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sPlayer.setPosition(sPlayer.getPosition().x + 3, sPlayer.getPosition().y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sPlayer.setPosition(sPlayer.getPosition().x - 3, sPlayer.getPosition().y);
    }
    //player ->gravity
    velocity.y += 0.15;
    sPlayer.setPosition(sPlayer.getPosition().x, sPlayer.getPosition().y + velocity.y);
}

sf::Vector2f Player::getPosition(){
    return sPlayer.getPosition();
}

void Player::setPosition(float x,float y){
    sPlayer.setPosition(x, y);
}

sf::Vector2f Player::getVelocity(){
    return velocity;
}

void Player::setVelocity(float x,float y){
    velocity = sf::Vector2f(x,y);
}

void Player::draw(sf:: RenderWindow& window) const{
    window.draw(sPlayer);
}
