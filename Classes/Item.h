#pragma once
#include <memory>
#include <vector>

#include "Player.h"

struct Item: sf::Sprite {
    static inline std::vector<int> itemsleft ={1,2,3,4,5,6};
    static inline std::vector<std::unique_ptr<Item>> activeitems;

    Item();

    static inline sf::Texture item1text;
    static inline sf::Texture item2text;
    static inline sf::Texture item3text;
    static inline sf::Texture item4text;
    static inline sf::Texture item5text;
    static inline sf::Texture item6text;

    virtual auto behaviour(Player &player, sf::RenderWindow const& window)->void=0;
    static auto applyitemsbehaviour(Player &player,sf::RenderWindow const& window)->void;
    static auto activateitem(int itemnum)->void;
};


