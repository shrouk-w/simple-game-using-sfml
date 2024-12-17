#pragma once
#include "Item.h"
#include "Player.h"

struct Item1: Item {
    Item1();
    auto behaviour(Player &player, sf::RenderWindow const &window) -> void override;
    sf::Clock shootingtimer;
};
