#pragma once
#include "Enemy.h"
#include "Player.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Clock.hpp"

struct  bossenemy: Enemy {
    int speed = 10;
    sf::Clock pewpewspeed;
    double Enemypewpewinterval = 1;
    sf::IntRect rectSourceSprite= sf::IntRect(0,0,32,32);
    int range = 800;
    sf::Clock bosschangedirectiontimer;
    float bosschagnedirectioncooldown = 3;

    bossenemy();

    auto shooting(Player const& player)->void;


    auto moving()->void;

    auto behaviour(Player const& player)->void;
};

