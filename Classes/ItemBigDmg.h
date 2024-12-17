#pragma once
#include "Item.h"

struct Item2: Item{
    Item2();
    auto behaviour(Player &player, sf::RenderWindow const &window) -> void override;
    sf::Clock shootingtimer;
};

