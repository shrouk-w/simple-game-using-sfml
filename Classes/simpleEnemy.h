#pragma once
#include "Enemy.h"

struct simpleEnemy: Enemy {
    int speed = 4;
    sf::Clock pewpewspeed;
    double Enemypewpewinterval = 1;
    sf::IntRect rectSourceSprite= sf::IntRect(0,0,32,32);
    int range = 500;

    simpleEnemy(double health);

    auto shooting(Player const& player)->void;
    auto moving(Player const& player)->void;

    bool gate = false;
    bool initialspawn = true;
    sf::Clock followtimer;

    auto behaviour(Player const& player)->void;


};