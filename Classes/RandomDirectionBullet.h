#pragma once
#include "Bullet.h"


struct Item5Bullet : Bullet{

    auto behaviour(sf::RenderWindow &window) -> void override;

    Item5Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);

    sf::Clock changedirection;
};

