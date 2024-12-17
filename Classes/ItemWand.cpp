
#include "ItemWand.h"

#include "MultiuseFunctionsLib.h"
#include "playerBullet.h"

Item1::Item1():Item() {
    setTexture(item1text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item1::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*3) {
        for(int i=0;i<3;i++) {
            player.bullets.push_back(std::make_unique<playerBullet>(player.radius/2,10,player.dmg,5,AddInaccuracy(360)));
            player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        }
        shootingtimer.restart();
    }
}