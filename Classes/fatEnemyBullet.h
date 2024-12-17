#pragma once
#include "Bullet.h"

struct  fatEnemyBullet: Bullet{
    auto behaviour(sf::RenderWindow &window) -> void;

    fatEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);

};


