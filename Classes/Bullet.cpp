#include "Bullet.h"

Bullet::Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle)
:CircleShape(radius,pointCount),
dmg(dmg),
speed(speed),
angle(angle) {
    setOrigin(getRadius()/2,getRadius()/2);
};




