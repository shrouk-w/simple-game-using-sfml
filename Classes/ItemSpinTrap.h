#pragma once
#include "Item.h"

struct Item3: Item {
    Item3();
    auto behaviour(Player &player, sf::RenderWindow const &window) -> void override;
    sf::Clock shootingtimer;

};




