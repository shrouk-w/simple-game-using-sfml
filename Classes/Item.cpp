#include "Item.h"

#include <iostream>

#include "ItemWand.h"
#include "ItemBigDmg.h"
#include "ItemSpinTrap.h"
#include "Item4Directions.h"
#include "ItemRandomizeDirection.h"
#include "ItemSniperRifle.h"

Item::Item() {
    if(item1text.getSize().x==0&&item1text.getSize().y==0) {
        if(!item1text.loadFromFile("Textures/item1text.png")) {
            std::cout<< "cant find item1 texture";
        }
    }
    if(item2text.getSize().x==0&&item2text.getSize().y==0) {
        if(!item2text.loadFromFile("Textures/item2text.png")) {
            std::cout<< "cant find item2 texture";
        }
    }
    if(item3text.getSize().x==0&&item3text.getSize().y==0) {
        if(!item3text.loadFromFile("Textures/item3text.png")) {
            std::cout<< "cant find item3 texture";
        }
    }
    if(item4text.getSize().x==0&&item4text.getSize().y==0) {
        if(!item4text.loadFromFile("Textures/item4text.png")) {
            std::cout<< "cant find item4 texture";
        }
    }
    if(item5text.getSize().x==0&&item5text.getSize().y==0) {
        if(!item5text.loadFromFile("Textures/item5text.png")) {
            std::cout<< "cant find item5 texture";
        }
    }
    if(item6text.getSize().x==0&&item6text.getSize().y==0) {
        if(!item6text.loadFromFile("Textures/item6text.png")) {
            std::cout<< "cant find item6 texture";
        }
    }
}
auto Item::applyitemsbehaviour(Player &player, sf::RenderWindow const& window) -> void {
    if(activeitems.size()>0) {
        for(auto &item: activeitems)
            item->behaviour(player, window);
    }
}

auto Item::activateitem(int itemnum) -> void {
    auto it=std::ranges::find(itemsleft.begin(),itemsleft.end(),itemnum);
    if(it==itemsleft.end())
        return;
    switch(itemnum) {
        case 1:
            activeitems.push_back(std::make_unique<Item1>());
            break;
        case 2:
            activeitems.push_back(std::make_unique<Item2>());
            break;
        case 3:
            activeitems.push_back(std::make_unique<Item3>());
            break;
        case 4:
            activeitems.push_back(std::make_unique<Item4>());
            break;
        case 5:
            activeitems.push_back(std::make_unique<Item5>());
            break;
        case 6:
            activeitems.push_back(std::make_unique<Item6>());
        break;
        default:
            return;
    }
    itemsleft.erase(it);
}





