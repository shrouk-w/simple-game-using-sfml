#include "ItemSniperRifle.h"

#include "MultiuseFunctionsLib.h"
#include "playerBullet.h"

Item6::Item6():Item() {
    setTexture(item6text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item6::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*3) {
        for(int i=0;i<2;i++) {
            player.bullets.push_back(std::make_unique<playerBullet>(player.radius*1,10,player.dmg*2,15,AddInaccuracy(360)));
            player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        }
        shootingtimer.restart();
    }
}