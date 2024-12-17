#include "Room.h"

#include <iostream>

#include "bossenemy.h"
#include "Enemy.h"
#include "fatenemy.h"
#include "Item.h"
#include "ItemWand.h"
#include "ItemBigDmg.h"
#include "ItemSpinTrap.h"
#include "Item4Directions.h"
#include "ItemRandomizeDirection.h"
#include "ItemSniperRifle.h"
#include "microwaveenemy.h"
#include "playerBullet.h"
#include "RoomSnipers.h"
#include "RoomSimples.h"
#include "RoomFatMicorwave.h"
#include "RoomMicroWaveRush.h"
#include "RoomFat.h"
#include "RoomBoss.h"
#include "RoomUpgrade.h"
#include "simpleEnemy.h"
#include "sniperEnemy.h"
#include "SFML/Graphics/Texture.hpp"

Room::Room() {
    if (room1text.getSize().x == 0 && room1text.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!room1text.loadFromFile("Textures/room1text.png")) {
            std::cout << "cant find room1 texture";
        }
        room1text.setRepeated(true);
    }
    if (room2text.getSize().x == 0 && room2text.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!room2text.loadFromFile("Textures/room2text.png")) {
            std::cout << "cant find room2 texture";
        }
        room2text.setRepeated(true);
    }
    if (room3text.getSize().x == 0 && room3text.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!room3text.loadFromFile("Textures/room3text.png")) {
            std::cout << "cant find room3 texture";
        }
        room3text.setRepeated(true);
    }
    if (roomupgradetext.getSize().x == 0 && roomupgradetext.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!roomupgradetext.loadFromFile("Textures/roomupgradetext.png")) {
            std::cout << "cant find roomupgrade texture";
        }
        roomupgradetext.setRepeated(true);
    }
    if (room4text.getSize().x == 0 && room4text.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!room4text.loadFromFile("Textures/room4text.png")) {
            std::cout << "cant find room4 texture";
        }
        room4text.setRepeated(true);
    }
    if (room5text.getSize().x == 0 && room5text.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!room5text.loadFromFile("Textures/room5text.png")) {
            std::cout << "cant find room5 texture";
        }
        room5text.setRepeated(true);
    }
    if (roombosstext.getSize().x == 0 && roombosstext.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!roombosstext.loadFromFile("Textures/roombosstext.png")) {
            std::cout << "cant find roomboss texture";
        }
        roombosstext.setRepeated(true);
    }
    if (healthtext.getSize().x == 0 && healthtext.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!healthtext.loadFromFile("Textures/healthtext.png")) {
            std::cout << "cant find health texture";
        }
    }
    if (dmgtext.getSize().x == 0 && dmgtext.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!dmgtext.loadFromFile("Textures/dmgtext.png")) {
            std::cout << "cant find dmg texture";
        }
    }
    if (cooldowntext.getSize().x == 0 && cooldowntext.getSize().y == 0) {
        //only load texture if it isnt loaded
        if (!cooldowntext.loadFromFile("Textures/cooldowntext.png")) {
            std::cout << "cant find cooldown texture";
        }
    }
}

int currentnumb;

auto Room::loadRoom(int roomnum, sf::RenderWindow &window, Player &player) -> void {
    currentnumb = roomnum;
    switch (roomnum) {
        case 0: current = std::make_unique<RoomUpgrade>(window);
            health.setTexture(healthtext);
            dmg.setTexture(dmgtext);
            cooldown.setTexture(cooldowntext);
            health.setTextureRect(sf::IntRect(0, 0, 32, 32));
            dmg.setTextureRect(sf::IntRect(0, 0, 32, 32));
            cooldown.setTextureRect(sf::IntRect(0, 0, 32, 32));
            health.setScale(2, 2);
            dmg.setScale(2, 2);
            cooldown.setScale(2, 2);
            health.setOrigin(health.getGlobalBounds().width / 2, health.getGlobalBounds().height / 2);
            dmg.setOrigin(dmg.getGlobalBounds().width / 2, dmg.getGlobalBounds().height / 2);
            cooldown.setOrigin(cooldown.getGlobalBounds().width / 2, cooldown.getGlobalBounds().height / 2);
            drawupgrades = true;
            drawweapons = true;
            break;
        case 1: current = std::make_unique<Room1>(window);
            break;
        case 2: current = std::make_unique<Room2>(window);
            break;
        case 3: current = std::make_unique<Room3>(window);
            break;
        case 4: current = std::make_unique<Room4>(window);
            break;
        case 5: current = std::make_unique<Room5>(window);
            break;
        case 6: current = std::make_unique<RoomBoss>(window);
            break;
        default: current = nullptr;
            break;
    }
    player.setPosition(current->playerspawnpossition);
    door.setFillColor(sf::Color::Red);
    door.setOutlineThickness(5);
    door.setOutlineColor(sf::Color::Black);
    door.setOrigin(door.getGlobalBounds().width / 2, door.getGlobalBounds().height / 2);
    door.setPosition(current->doorspawnpossition);
    done = false;
    left = current->getGlobalBounds().left;
    right = current->getGlobalBounds().left + current->getSize().x;
    top = current->getGlobalBounds().top;
    bottom = current->getGlobalBounds().top + current->getSize().y;
}

auto Room::restrictPlayer(Player &player) -> void {
    if (player.getPosition().x < left) {
        player.setPosition(left, player.getPosition().y);
    }
    if (player.getPosition().x > right) {
        player.setPosition(right, player.getPosition().y);
    }
    if (player.getPosition().y < top) {
        player.setPosition(player.getPosition().x, top);
    }
    if (player.getPosition().y > bottom) {
        player.setPosition(player.getPosition().x, bottom);;
    }
}

auto Room::restrictEnemies() -> void {
    for (auto &badie: Enemy::enemies) {
        if (badie->getPosition().x < left) {
            badie->setPosition(left, badie->getPosition().y);
        }
        if (badie->getPosition().x > right) {
            badie->setPosition(right, badie->getPosition().y);
        }
        if (badie->getPosition().y < top) {
            badie->setPosition(badie->getPosition().x, top);
        }
        if (badie->getPosition().y > bottom) {
            badie->setPosition(badie->getPosition().x, bottom);;
        }
    }
    for (auto &badie: Enemy::bosses) {
        if (badie->getPosition().x < left) {
            badie->setPosition(left, badie->getPosition().y);
        }
        if (badie->getPosition().x > right) {
            badie->setPosition(right, badie->getPosition().y);
        }
        if (badie->getPosition().y < top) {
            badie->setPosition(badie->getPosition().x, top);
        }
        if (badie->getPosition().y > bottom) {
            badie->setPosition(badie->getPosition().x, bottom);;
        }
    }
}

auto Room::restrictBullets(Player &player) -> void {
    for (int i = 0; i < player.bullets.size(); i++) {
        if (player.bullets[i]->getPosition().x < left) {
            player.bullets.erase(player.bullets.begin() + i);
            return;
        }
        if (player.bullets[i]->getPosition().x > right) {
            player.bullets.erase(player.bullets.begin() + i);
            return;
        }
        if (player.bullets[i]->getPosition().y < top) {
            player.bullets.erase(player.bullets.begin() + i);
            return;
        }
        if (player.bullets[i]->getPosition().y > bottom) {
            player.bullets.erase(player.bullets.begin() + i);
            return;
        }
    }

    for (int i = 0; i < Enemy::bullets.size(); i++) {
        if (Enemy::bullets[i]->getPosition().x < left) {
            Enemy::bullets.erase(Enemy::bullets.begin() + i);
            return;
        }
        if (Enemy::bullets[i]->getPosition().x > right) {
            Enemy::bullets.erase(Enemy::bullets.begin() + i);
            return;
        }
        if (Enemy::bullets[i]->getPosition().y > bottom) {
            Enemy::bullets.erase(Enemy::bullets.begin() + i);
            return;
        }
        if (Enemy::bullets[i]->getPosition().y < top) {
            Enemy::bullets.erase(Enemy::bullets.begin() + i);
            return;
        }
    }
}

bool loadUpgradeRoom = true;

auto Room::ManageRooms(sf::RenderWindow &window, Player &player) -> void {
    if (firstload) {
        std::random_shuffle(avaiblerooms.begin(), avaiblerooms.end());
        for (int i = 0; i < 3; i++)
            roomschoosen.push_back(avaiblerooms[i]);
        firstload = false;
    }

    if (loadUpgradeRoom && done && door.getGlobalBounds().intersects(player.getGlobalBounds())) {
        Enemy::bullets.clear();
        player.bullets.clear();

        std::random_shuffle(Item::itemsleft.begin(),Item::itemsleft.end());
        for(int i=0;i<3;i++) {
            weaponschoosen.push_back(Item::itemsleft[i]);
        }
        switch(Item::itemsleft[0]) {
            case 1:
                displayItem1=(std::make_unique<Item1>());
            break;
            case 2:
                displayItem1=(std::make_unique<Item2>());
            break;
            case 3:
                displayItem1= (std::make_unique<Item3>());
            break;
            case 4:
                displayItem1= (std::make_unique<Item4>());
            break;
            case 5:
                displayItem1= (std::make_unique<Item5>());
            break;
            case 6:
                displayItem1= (std::make_unique<Item6>());
            break;
            default:
                displayItem1= nullptr;
        }
        switch(Item::itemsleft[1]) {
            case 1:
                displayItem2=(std::make_unique<Item1>());
            break;
            case 2:
                displayItem2=(std::make_unique<Item2>());
            break;
            case 3:
                displayItem2= (std::make_unique<Item3>());
            break;
            case 4:
                displayItem2= (std::make_unique<Item4>());
            break;
            case 5:
                displayItem2= (std::make_unique<Item5>());
            break;
            case 6:
                displayItem2= (std::make_unique<Item6>());
            break;
            default:
                displayItem2= nullptr;
        }
        switch(Item::itemsleft[2]) {
            case 1:
                displayItem3=(std::make_unique<Item1>());
            break;
            case 2:
                displayItem3=(std::make_unique<Item2>());
            break;
            case 3:
                displayItem3= (std::make_unique<Item3>());
            break;
            case 4:
                displayItem3= (std::make_unique<Item4>());
            break;
            case 5:
                displayItem3= (std::make_unique<Item5>());
            break;
            case 6:
                displayItem3= (std::make_unique<Item6>());
            break;
            default:
                displayItem3= nullptr;
        }

        loadRoom(0, window, player); //0 for the upgrade room
        loadUpgradeRoom = false;
    }


    if (done && door.getGlobalBounds().intersects(player.getGlobalBounds())) {
        Enemy::bullets.clear();
        player.bullets.clear();
        if (chooseroomindex < roomschoosen.size()) {
            loadRoom(roomschoosen[chooseroomindex++], window, player);
            enemyquantitymodifier ++;
        } else {
            if(bossalive) {
                loadRoom(6, window, player); //6 for boss room
                bossalive=false;
            }
            else {  //if bossroom defeated win and end game in main
                win=true;
            }
        }
        loadUpgradeRoom = true;
    }

    window.draw(*current);
    window.draw(door);
    if (currentnumb == 0) {
        Room::UpgradeHandling(player, window);
    }
}

auto Room::UpgradeHandling(Player &player, sf::RenderWindow &window) -> void {
    health.setPosition(current->healthspawnpossition);
    dmg.setPosition(current->dmgspawnpossition);
    cooldown.setPosition(current->cooldownspawnpossition);
    if (drawupgrades) {
        window.draw(health);
        window.draw(dmg);
        window.draw(cooldown);
    }
    if (drawupgrades && health.getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawupgrades = false;
        player.maxhealth+=2;
        player.health = player.maxhealth;
        player.inaccuracy -= 7;
    } else if (drawupgrades && dmg.getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawupgrades = false;
        player.dmg+=3;
        player.radius += 3;
    } else if (drawupgrades && cooldown.getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawupgrades = false;
        player.Playerpewpewinterval -= 0.11;
    }
    displayItem1->setPosition(current->item1spawnpossition);
    displayItem2->setPosition(current->item2spawnpossition);
    displayItem3->setPosition(current->item3spawnpossition);
    if(drawweapons && displayItem1->getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawweapons=false;
        Item::activateitem(weaponschoosen[0]);
        weaponschoosen.clear();

    }
    else if(drawweapons && displayItem2->getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawweapons=false;
        Item::activateitem(weaponschoosen[1]);
        weaponschoosen.clear();

    }
    else if(drawweapons && displayItem3->getGlobalBounds().intersects(player.getGlobalBounds())) {
        drawweapons=false;
        Item::activateitem(weaponschoosen[2]);
        weaponschoosen.clear();

    }
    if(drawweapons)
    {
        window.draw(*displayItem1);
        window.draw(*displayItem2);
        window.draw(*displayItem3);
    }

}

auto Room::loadwaves() -> void {
    if (Enemy::enemies.size() == 0 && cooldowngate) {
        current->wavetimer.restart();
        cooldowngate = false;
        Enemy::bullets.clear();
        Player::bullets.clear();
    }

    if (waveindex < maxwave && Enemy::enemies.size() == 0 && wavetimer.getElapsedTime().asSeconds() > 2) {
        for (int i = 0; i < SimpleEnemyWaves[waveindex] * enemyquantitymodifier; i++) {
            Enemy::enemies.push_back(std::make_unique<simpleEnemy>(4*enemyquantitymodifier));
            Enemy::enemies.back()->setPosition(rand() % int(current->getSize().x) + left,
                                               rand() % int(current->getSize().y) + top);
        }
        for (int i = 0; i < SniperEnemyWaves[waveindex] * enemyquantitymodifier; i++) {
            Enemy::enemies.push_back(std::make_unique<sniperEnemy>(4*enemyquantitymodifier));
            Enemy::enemies.back()->setPosition(rand() % int(current->getSize().x) + left,
                                               rand() % int(current->getSize().y) + top);
        }
        for (int i = 0; i < FatEnemyWaves[waveindex] * enemyquantitymodifier; i++) {
            Enemy::enemies.push_back(std::make_unique<fatenemy>(8*enemyquantitymodifier));
            Enemy::enemies.back()->setPosition(rand() % int(current->getSize().x) + left,
                                               rand() % int(current->getSize().y) + top);
        }
        for (int i = 0; i < MicrovaweEnemyWaves[waveindex] * enemyquantitymodifier; i++) {
            Enemy::enemies.push_back(std::make_unique<microwaveenemy>(2*enemyquantitymodifier));
            Enemy::enemies.back()->setPosition(rand() % int(current->getSize().x) + left,
                                               rand() % int(current->getSize().y) + top);
        }
        for (int i = 0; i < BossEnemyWaves[waveindex]; i++) {
            Enemy::bosses.push_back(std::make_unique<bossenemy>());
            Enemy::bosses.back()->setPosition(rand() % int(current->getSize().x) + left,
                                              rand() % int(current->getSize().y) + top);
        }
        ++waveindex;
        cooldowngate = true;
    }

    if (waveindex >= maxwave && Enemy::enemies.size() == 0 && Enemy::bosses.size() == 0) {
        done = true;
        door.setFillColor(sf::Color::Green);
    }
}
