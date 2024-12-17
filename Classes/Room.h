#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "Item.h"
#include "Player.h"
#include "SFML/Graphics/RectangleShape.hpp"

struct Room: sf::RectangleShape {
    static inline  std::unique_ptr<Room> current;
    static inline float left;
    static inline float right;
    static inline float top;
    static inline float bottom;
    static inline sf::CircleShape door = sf::CircleShape(20,6);
    static inline bool done = true;

    static inline bool firstload = true;
    static inline bool cooldowngate;
    static inline sf::Clock wavetimer;
    static inline int waveindex;
    static inline int maxwave;
    static inline double enemyquantitymodifier=0;
    static inline int chooseroomindex=0;
    static inline std::vector<int> avaiblerooms = {1, 2, 3, 4, 5};
    static inline std::vector<int> roomschoosen;
    static inline std::vector<int>SimpleEnemyWaves;
    static inline std::vector<int>SniperEnemyWaves;
    static inline std::vector<int>FatEnemyWaves;
    static inline std::vector<int>MicrovaweEnemyWaves;
    static inline std::vector<int>BossEnemyWaves;

    static inline sf::Texture room1text;
    static inline sf::Texture room2text;
    static inline sf::Texture room3text;
    static inline sf::Texture room4text;
    static inline sf::Texture room5text;
    static inline sf::Texture roombosstext;
    static inline sf::Texture roomupgradetext;

    static inline bool bossalive = true;
    static inline bool win = false;

    static auto UpgradeHandling(Player &player, sf::RenderWindow &window)->void;
    static inline sf::Sprite health;
    static inline sf::Sprite dmg;
    static inline sf::Sprite cooldown;
    sf::Vector2f healthspawnpossition;
    sf::Vector2f dmgspawnpossition;
    sf::Vector2f cooldownspawnpossition;
    static inline bool drawupgrades;

    static inline std::vector<int> weaponschoosen;
    static inline std::unique_ptr<Item> displayItem1;
    static inline std::unique_ptr<Item> displayItem2;
    static inline std::unique_ptr<Item> displayItem3;
    sf::Vector2f item1spawnpossition;
    sf::Vector2f item2spawnpossition;
    sf::Vector2f item3spawnpossition;
    static inline bool drawweapons;



    static inline sf::Texture healthtext;
    static inline sf::Texture dmgtext;
    static inline sf::Texture cooldowntext;

    sf::Vector2f playerspawnpossition;
    sf::Vector2f doorspawnpossition;
    Room();

    static auto restrictPlayer(Player &player)->void;
    static auto restrictBullets(Player &player)->void;
    static auto restrictEnemies()->void;

    static auto loadRoom(int roomnum, sf::RenderWindow & window, Player &player)->void;
    static auto loadwaves() -> void;

    static auto ManageRooms(sf::RenderWindow & window, Player &player)->void;

};

