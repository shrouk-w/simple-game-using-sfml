#include "RoomUpgrade.h"

RoomUpgrade::RoomUpgrade(sf::RenderWindow const &window) {
    this->setTexture(&roomupgradetext);
    this->setSize(sf::Vector2f(700,700));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setOutlineThickness(10);
    this->setOutlineColor(sf::Color::Green);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=  sf::Vector2f(getPosition().x,getPosition().y+getSize().y/2 - 60);
    doorspawnpossition =   sf::Vector2f(getPosition().x,getPosition().y-getSize().y/2 + 60);
    healthspawnpossition=  sf::Vector2f(getPosition().x-getSize().x/2+90,getPosition().y+getSize().y/2 - 200);
    dmgspawnpossition=     sf::Vector2f(getPosition().x+30,getPosition().y+getSize().y/2 - 200);
    cooldownspawnpossition=sf::Vector2f(getPosition().x+getSize().x/2-30,getPosition().y+getSize().y/2 - 200);

    item1spawnpossition=  sf::Vector2f(getPosition().x-getSize().x/2+90,getPosition().y+getSize().y/2 - 400);
    item2spawnpossition=     sf::Vector2f(getPosition().x+30,getPosition().y+getSize().y/2 - 400);
    item3spawnpossition=sf::Vector2f(getPosition().x+getSize().x/2-30,getPosition().y+getSize().y/2 - 400);

    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave = 0;
}

