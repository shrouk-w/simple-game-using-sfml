#pragma once
#include "Item.h"

struct Item4: Item {
    Item4();
    auto behaviour(Player &player, sf::RenderWindow const &window) -> void override;
    sf::Clock shootingtimer;
};

