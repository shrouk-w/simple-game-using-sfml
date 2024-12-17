
#include "RoomSimples.h"

Room2::Room2(sf::RenderWindow const &window) {
    this->setTexture(&room2text);
    this->setOutlineThickness(10);
    this->setOutlineColor(sf::Color::Red);
    this->setSize(sf::Vector2f(2000,2000));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=sf::Vector2f(getPosition().x,getPosition().y-getSize().y/2 + 60);
    doorspawnpossition = sf::Vector2f(getPosition().x,getPosition().y+getSize().y/2 - 60);
    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave = 4;
    //waves              1 2 3 4
    SimpleEnemyWaves=   {2,4,6,4};
    SniperEnemyWaves=   {0,0,0,0};
    FatEnemyWaves=      {0,0,0,2};
    MicrovaweEnemyWaves={0,0,0,0};
    BossEnemyWaves =    {0,0,0,0};
}

