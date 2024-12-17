

#include "bossenemy.h"

#include <cmath>


#include "fatenemy.h"
#include "microwaveenemy.h"
#include "MultiuseFunctionsLib.h"
#include "simpleEnemy.h"
#include "sniperEnemy.h"

bossenemy::bossenemy(): Enemy(300){

    this->setTexture(bossenemytex);
    this->setTextureRect(rectSourceSprite);
    this->setScale(sf::Vector2f(6,6)); //1 full size 0.5 half size 2 twice size and so on
    this->setOrigin(this->getLocalBounds().width/2,this->getLocalBounds().height/2);
}

auto bossenemy::shooting(Player const& player)->void {
    if (pewpewspeed.getElapsedTime().asSeconds() > Enemypewpewinterval) {
        int whichenemy = rand()%4;
        switch (whichenemy) {
            case 0: Enemy::enemies.push_back(std::make_unique<simpleEnemy>(4*5));
            break;
            case 1: Enemy::enemies.push_back(std::make_unique<sniperEnemy>(4*5));
            break;
            case 2: Enemy::enemies.push_back(std::make_unique<fatenemy>(8*5));
            break;
            case 3: Enemy::enemies.push_back(std::make_unique<microwaveenemy>(2*5));
            break;
            default:
                return;
        }
        enemies.back()->setPosition((player.getPosition().x + getPosition().x)/2,
                                    (player.getPosition().y + getPosition().y)/2);
        pewpewspeed.restart();
    }
}


auto movingangle=0.1;
auto bossenemy::moving()->void{
    if(bosschangedirectiontimer.getElapsedTime().asSeconds()>bosschagnedirectioncooldown) {
        movingangle = AddInaccuracy(360);
        bosschangedirectiontimer.restart();
    }
    this->move(speed*cos(movingangle),speed*sin(movingangle));
}



auto bossenemy::behaviour(Player const& player)->void {
    moving();
    shooting(player);
}