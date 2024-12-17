#include "fatenemy.h"

#include <cmath>

#include "fatEnemyBullet.h"

fatenemy::fatenemy(double health): Enemy(health){
    this->setTexture(fatenemytex);
    this->setTextureRect(rectSourceSprite);
    this->setScale(sf::Vector2f(4,4)); //1 full size 0.5 half size 2 twice size and so on
    this->setOrigin(this->getLocalBounds().width/2,this->getLocalBounds().height/2);
}

auto fatenemy::shooting(Player const& player)->void {
    if (pewpewspeed.getElapsedTime().asSeconds() > Enemypewpewinterval) {
        bullets.push_back(std::make_unique<fatEnemyBullet>(35,10,5,10,
            std::atan2(player.getPosition().y - getPosition().y, // atan2 gets us angle between mouse and object
                                    player.getPosition().x - getPosition().x)));
        bullets.back()->setPosition(getPosition());
        pewpewspeed.restart();
    }
}
auto fatenemy::moving(Player const& player)->void{
    auto angle =atan2(player.getPosition().y-getPosition().y,
                            player.getPosition().x-getPosition().x);
    this->move(speed*cos(angle),speed*sin(angle));
}



auto fatenemy::behaviour(Player const& player)->void {
    //this code makes enemy wait 1 sec before starting the chase
    if(initialspawn && followtimer.getElapsedTime().asSeconds()<1) {
        return;
    }
    else {
        initialspawn=false;
    }
    //above is to prevent immiediet shooting upon spawn

    int distance = std::hypot(getPosition().x-player.getPosition().x, getPosition().y-player.getPosition().y);

    if(distance>range) {
        if(gate) {
            followtimer.restart();
            gate=false;
        }
        if(followtimer.getElapsedTime().asSeconds()<3)
            shooting(player);
        else
            moving(player);
    }
    else {
        shooting(player);
        gate=true;
    }
}