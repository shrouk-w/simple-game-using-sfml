

#include "RandomDirectionBullet.h"

#include <cmath>

#include "MultiuseFunctionsLib.h"


Item5Bullet::Item5Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle):Bullet(radius,pointCount,dmg,speed,angle)
{
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(3);
}

auto Item5Bullet::behaviour(sf::RenderWindow &window) -> void
{
    window.draw(*this);
    if(changedirection.getElapsedTime().asSeconds()>1) {
        angle=AddInaccuracy(360);
        changedirection.restart();
    }
    move(speed* std::cos(angle),speed*sin(angle));
}