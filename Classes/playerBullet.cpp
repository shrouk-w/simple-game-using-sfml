#include "playerBullet.h"

#include <cmath>



playerBullet::playerBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle):Bullet(radius,pointCount,dmg,speed,angle)
{
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(3);
}

auto playerBullet::behaviour(sf::RenderWindow &window) -> void
{
    window.draw(*this);
    move(speed* std::cos(angle),speed*sin(angle));
}




