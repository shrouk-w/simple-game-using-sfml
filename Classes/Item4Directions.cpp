
#include "Item4Directions.h"

#include "playerBullet.h"

Item4::Item4():Item() {
    setTexture(item4text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item4::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*3) { //angles need to be in radians
        player.bullets.push_back(std::make_unique<playerBullet>(player.radius/2,10,player.dmg,5,3 * 3.14 / 2));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        player.bullets.push_back(std::make_unique<playerBullet>(player.radius/2,10,player.dmg,5,0));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        player.bullets.push_back(std::make_unique<playerBullet>(player.radius/2,10,player.dmg,5,3.14));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);
        player.bullets.push_back(std::make_unique<playerBullet>(player.radius/2,10,player.dmg,5,3.14/2));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);

        shootingtimer.restart();
    }
}