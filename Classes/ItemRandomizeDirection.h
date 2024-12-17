#pragma once
#include "Item.h"

struct  Item5: Item {

    Item5();
    auto behaviour(Player &player, sf::RenderWindow const &window) -> void;
    sf::Clock shootingtimer;
};

