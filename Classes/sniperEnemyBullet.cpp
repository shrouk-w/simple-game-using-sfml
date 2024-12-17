
#include "sniperEnemyBullet.h"

#include <cmath>

auto sniperEnemyBullet::behaviour(sf::RenderWindow &window) -> void {

    window.draw(*this);
    move(speed* std::cos(angle),speed*sin(angle));

}

sniperEnemyBullet::sniperEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle)
        : Bullet(radius, pointCount, dmg, speed, angle) {
    setOutlineThickness(1);
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::Red);
}