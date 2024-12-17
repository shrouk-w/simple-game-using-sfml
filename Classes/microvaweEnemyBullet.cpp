#include "microvaweEnemyBullet.h"

#include <cmath>

auto microvaweEnemyBullet::behaviour(sf::RenderWindow &window) -> void {

    window.draw(*this);
    move(speed* std::cos(angle),speed*sin(angle));

}

microvaweEnemyBullet::microvaweEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle)
        : Bullet(radius, pointCount, dmg, speed, angle) {
    setOutlineThickness(4);
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::Blue);
}