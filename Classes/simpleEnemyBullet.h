#pragma once

#include "Bullet.h"
#include "MultiuseFunctionsLib.h"
#include "Player.h"

struct  simpleEnemyBullet: Bullet {
    static inline sf::Texture alltexture = generatetex(3,3);
    static inline sf::Clock textureupdate;
    Player const& player;
    sf::Clock changedirection;
    float cooldown = 1.5;

    auto behaviour(sf::RenderWindow &window) -> void;

    simpleEnemyBullet(float radius, std::size_t pointCount, int dmg, int speed, float angle, Player const &player);



};


