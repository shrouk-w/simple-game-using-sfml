#pragma once

#include "Bullet.h"

struct Item3Bullet: Bullet {

    auto behaviour(sf::RenderWindow &window) -> void;

    Item3Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);

};

