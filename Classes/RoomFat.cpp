#include "RoomFat.h"

Room5::Room5(sf::RenderWindow const &window) {
    this->setTexture(&room5text);
    this->setOutlineThickness(10);
    this->setOutlineColor(sf::Color::White);
    this->setSize(sf::Vector2f(1000,3000));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=sf::Vector2f(getPosition().x ,getPosition().y-getSize().y/2 + 60);
    doorspawnpossition = sf::Vector2f(getPosition().x ,getPosition().y+getSize().y/2 - 60);
    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave = 3;
    //waves              1 2 3
    SimpleEnemyWaves=   {0,0,2};
    SniperEnemyWaves=   {1,2,0};
    FatEnemyWaves=      {2,3,4};
    MicrovaweEnemyWaves={0,0,0};
    BossEnemyWaves =    {0,0,0};
}