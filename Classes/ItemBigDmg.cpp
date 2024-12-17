#include "ItemBigDmg.h"

#include <iostream>

#include "MultiuseFunctionsLib.h"
#include "playerBullet.h"


Item2::Item2():Item() {
    setTexture(item2text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item2::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*5) {
        player.bullets.push_back(std::make_unique<playerBullet>(player.radius*3,15,player.dmg*5,2,AddInaccuracy(360)));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        shootingtimer.restart();
    }
}
