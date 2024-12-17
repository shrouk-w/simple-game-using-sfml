#pragma once
#include "Item.h"

struct Item6 : Item{
    Item6();

    auto behaviour(Player &player, sf::RenderWindow const &window) -> void;

    sf::Clock shootingtimer;
};
