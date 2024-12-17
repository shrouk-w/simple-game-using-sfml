#pragma once
#include "Bullet.h"

struct playerBullet: Bullet {

    auto behaviour(sf::RenderWindow &window) -> void;

    playerBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);


};



