

#include "ItemRandomizeDirection.h"

#include "RandomDirectionBullet.h"
#include "MultiuseFunctionsLib.h"

Item5::Item5():Item() {
    setTexture(item5text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item5::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*5) {
        for(int i=0;i<4;i++) {
            player.bullets.push_back(std::make_unique<Item5Bullet>(player.radius*1.5,10,player.dmg,3,AddInaccuracy(360)));
            player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        }
        shootingtimer.restart();
    }
}