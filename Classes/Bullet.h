#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


struct Bullet: sf::CircleShape {
    int dmg;
    int speed;
    float angle;
    bool isHit = false;


    Bullet(float radius, std::size_t pointCount, int dmg, int speed, float angle);

    virtual auto behaviour(sf::RenderWindow &window) -> void {
    }
};
