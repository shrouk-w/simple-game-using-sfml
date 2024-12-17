#include "simpleEnemyBullet.h"

#include <cmath>
#include <memory>

#include "MultiuseFunctionsLib.h"
#include "SFML/Graphics/RenderWindow.hpp"


auto simpleEnemyBullet::behaviour(sf::RenderWindow &window) -> void {
        if(alltexture.getSize().x==0 && alltexture.getSize().y==0 || textureupdate.getElapsedTime().asMilliseconds()>100) { //jezeli nie ma tekstury lub minelo 100mili sek, zrob nowa
                alltexture=generatetex(3,3);
                textureupdate.restart();
        }
        setTexture(&alltexture);
        window.draw(*this);
        if(changedirection.getElapsedTime().asSeconds()>cooldown) {
                angle = std::atan2(player.getPosition().y - getPosition().y, player.getPosition().x - getPosition().x);
                changedirection.restart();
        }
        move(speed* std::cos(angle),speed*sin(angle));

}

simpleEnemyBullet::simpleEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle, Player const& player)
        : Bullet(radius, pointCount, dmg, speed, angle), player(player) {
        setOutlineThickness(6);
        setOutlineColor(sf::Color::Black);
}

