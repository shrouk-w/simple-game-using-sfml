
#include "SpinTrapBullet.h"
Item3Bullet::Item3Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle):Bullet(radius,pointCount,dmg,speed,angle)
{
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(3);
}

auto Item3Bullet::behaviour(sf::RenderWindow &window) -> void
{
    window.draw(*this);
    this->rotate(30);
}
