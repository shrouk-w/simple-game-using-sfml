
#include "fatEnemyBullet.h"

#include <cmath>

auto fatEnemyBullet::behaviour(sf::RenderWindow &window) -> void {

    window.draw(*this);
    move((rand()%speed)* std::cos(angle),(rand()%speed)*sin(angle));

}

fatEnemyBullet::fatEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle):
Bullet(radius, pointCount, dmg, speed, angle) {
    setOutlineThickness(4);
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::Red);

}
