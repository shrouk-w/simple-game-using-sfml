
#include "RoomBoss.h"

RoomBoss::RoomBoss(sf::RenderWindow const &window) {
    this->setTexture(&roombosstext);
    this->setOutlineThickness(50);
    this->setOutlineColor(sf::Color::White);
    this->setSize(sf::Vector2f(3000,3000));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=sf::Vector2f(getPosition().x ,getPosition().y+getSize().y/2 - 60);
    doorspawnpossition = sf::Vector2f(getPosition().x ,getPosition().y-getSize().y/2 + 60);
    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave =1;
    //waves              1
    SimpleEnemyWaves=   {0};
    SniperEnemyWaves=   {0};
    FatEnemyWaves=      {0};
    MicrovaweEnemyWaves={0};
    BossEnemyWaves =    {1};
}