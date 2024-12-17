#include "Enemy.h"

#include <cmath>

#include "Player.h"

#include <iostream>

    Enemy::Enemy(double health_) {
        health = health_;
        if(enemiestex.getSize().x==0&&enemiestex.getSize().y==0) { //only load texture if it isnt loaded
            if(!enemiestex.loadFromFile("Textures/simpleenemytex.png")) {
                std::cout<< "cant find simpleenemy texture";
            }
        }
        if(sniperenemytex.getSize().x==0&&sniperenemytex.getSize().y==0) { //only load texture if it isnt loaded
            if(!sniperenemytex.loadFromFile("Textures/sniperenemytex.png")) {
                std::cout<< "cant find sniperenemy texture";
            }
        }
        if(fatenemytex.getSize().x==0&&fatenemytex.getSize().y==0) { //only load texture if it isnt loaded
            if(!fatenemytex.loadFromFile("Textures/fatenemytex.png")) {
                std::cout<< "cant find fatenemy texture";
            }
        }
        if(microwaveenemytex.getSize().x==0&&microwaveenemytex.getSize().y==0) { //only load texture if it isnt loaded
            if(!microwaveenemytex.loadFromFile("Textures/microvaweenemytex.png")) {
                std::cout<< "cant find microwaveenemy texture";
            }
        }
        if(bossenemytex.getSize().x==0&&bossenemytex.getSize().y==0) { //only load texture if it isnt loaded
            if(!bossenemytex.loadFromFile("Textures/bossenemytext.png")) {
                std::cout<< "cant find bossenemy texture";
            }
        }
    }

    auto Enemy::takedmg(int dmg)->void{
        this->health-=dmg;
    }


    auto Enemy::applyenemybehaviour(Player const& player,sf::RenderWindow &window) -> void {
        if(!enemies.empty()) {
            for(auto const& enemie : enemies) {
                window.draw(*enemie);
                enemie->behaviour(player);
            }
        }
        if(!bosses.empty()) {
            for(auto const& boss: bosses) {
                window.draw(*boss);
                boss->behaviour(player);
            }
        }
    }

    auto Enemy::hitdetection(Player &player) -> void {
        if(!player.isrolling){
        for(int i=bullets.size()-1;i>=0;i--) {
            if(std::hypot(bullets[i]->getPosition().x-player.getPosition().x,
                            bullets[i]->getPosition().y-player.getPosition().y)<Enemy::bullets[i]->getRadius()+player.getGlobalBounds().width/4)
            {
                player.takedmg(bullets[i]->dmg);
                bullets.erase(Enemy::bullets.begin() + i);
                return; //otherwise rarely game crashes because of trying to acces deleted element
            }
        }

        }
    }

    auto Enemy::applybulletsbehaviour(sf::RenderWindow & window)->void{
        for(auto const& bullet : bullets) {
            bullet->behaviour(window);
        }
    }





