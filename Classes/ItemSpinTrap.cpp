#include "ItemSpinTrap.h"

#include "SpinTrapBullet.h"

Item3::Item3():Item() {
    setTexture(item3text);
    setScale(2,2);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
}

auto Item3::behaviour(Player &player, sf::RenderWindow const &window) -> void {
    if(shootingtimer.getElapsedTime().asSeconds()>player.Playerpewpewinterval*3) {
        player.bullets.push_back(std::make_unique<Item3Bullet>(player.radius*2,5,player.dmg,5,0));
        player.bullets.back()->setPosition(player.getPosition().x,player.getPosition().y);

        shootingtimer.restart();
    }
}