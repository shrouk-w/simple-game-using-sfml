#pragma once
#include "Player.h"


struct microvaweEnemyBullet: Bullet {

    auto behaviour(sf::RenderWindow &window) -> void;

    microvaweEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);

};


