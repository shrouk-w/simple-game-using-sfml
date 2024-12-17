#include "RoomFatMicorwave.h"

Room3::Room3(sf::RenderWindow const &window) {
    this->setTexture(&room3text);
    this->setOutlineThickness(10);
    this->setOutlineColor(sf::Color::Cyan);
    this->setSize(sf::Vector2f(3000,500));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=sf::Vector2f(getPosition().x-getSize().x/2+60,getPosition().y);
    doorspawnpossition = sf::Vector2f(getPosition().x+getSize().x/2-60,getPosition().y);
    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave = 3;
    //waves              1 2 3
    SimpleEnemyWaves=   {0,0,0};
    SniperEnemyWaves=   {0,0,0};
    FatEnemyWaves=      {1,1,3};
    MicrovaweEnemyWaves={1,2,1};
    BossEnemyWaves =    {0,0,0};
}