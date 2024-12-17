#include "RoomMicroWaveRush.h"

Room4::Room4(sf::RenderWindow const &window) {
    this->setTexture(&room4text);
    this->setOutlineThickness(10);
    this->setOutlineColor(sf::Color::Yellow);
    this->setSize(sf::Vector2f(1400,1400));
    this->setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
    this->setOrigin(getSize().x/2,getSize().y/2);
    this->setPosition(window.getSize().x/2,window.getSize().y/2);
    playerspawnpossition=sf::Vector2f(getPosition().x + getSize().x/2 - 60,getPosition().y-getSize().y/2 + 60);
    doorspawnpossition = sf::Vector2f(getPosition().x - getSize().x/2 + 60,getPosition().y+getSize().y/2 - 60);
    cooldowngate = true;
    wavetimer = sf::Clock();
    waveindex =0;
    maxwave = 2;
    //waves              1 2
    SimpleEnemyWaves=   {0,0};
    SniperEnemyWaves=   {0,0};
    FatEnemyWaves=      {1,0};
    MicrovaweEnemyWaves={4,6};
    BossEnemyWaves =    {0,0};
}