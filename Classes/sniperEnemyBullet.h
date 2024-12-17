#pragma once
#include "Bullet.h"


struct sniperEnemyBullet: Bullet {
    auto behaviour(sf::RenderWindow &window) -> void;

    sniperEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);
};



