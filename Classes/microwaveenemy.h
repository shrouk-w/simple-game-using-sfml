#pragma once
#include "Enemy.h"
#include "Player.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Clock.hpp"

struct microwaveenemy: Enemy {

    int speed = 5;
    sf::Clock pewpewspeed;
    double Enemypewpewinterval = 2;
    sf::IntRect rectSourceSprite= sf::IntRect(0,0,32,32);
    int range = 350;

    microwaveenemy(double health);

    auto shooting(Player const& player)->void;
    auto moving(Player const& player)->void;

    bool gate = false;
    bool initialspawn = true;
    sf::Clock followtimer;

    auto behaviour(Player const& player)->void;

};


