
#include "microwaveenemy.h"

#include <cmath>

#include "microvaweEnemyBullet.h"
#include "MultiuseFunctionsLib.h"

microwaveenemy::microwaveenemy(double health): Enemy(health){

    this->setTexture(microwaveenemytex);
    this->setTextureRect(rectSourceSprite);
    this->setScale(sf::Vector2f(2,2)); //1 full size 0.5 half size 2 twice size and so on
    this->setOrigin(this->getLocalBounds().width/2,this->getLocalBounds().height/2);
}

auto microwaveenemy::shooting(Player const& player)->void {
    if (pewpewspeed.getElapsedTime().asSeconds() > Enemypewpewinterval) {
        for(int i=0;i<5;i++) {
            bullets.push_back(std::make_unique<microvaweEnemyBullet>(5,15,1,8,
                std::atan2(player.getPosition().y - getPosition().y, // atan2 gets us angle between mouse and object
                                        player.getPosition().x - getPosition().x) + AddInaccuracy(80)));
            bullets.back()->setPosition(getPosition());
        }
        pewpewspeed.restart();
    }
}
auto microwaveenemy::moving(Player const &player) -> void {
    auto angle =atan2(player.getPosition().y-getPosition().y,
                            player.getPosition().x-getPosition().x);
    this->move(speed*cos(angle),speed*sin(angle));
}


auto microwaveenemy::behaviour(Player const& player)->void {
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
        if(followtimer.getElapsedTime().asSeconds()<1)
            shooting(player);
        else
            moving(player);
    }
    else {
        shooting(player);
        gate=true;
    }
}