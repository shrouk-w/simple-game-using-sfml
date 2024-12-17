#pragma once
#include <memory>
#include <vector>

#include "Bullet.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Player.h"

struct Enemy: sf::Sprite {
    static inline std::vector<std::unique_ptr<Enemy>> enemies;
    static inline std::vector<std::unique_ptr<Enemy>> bosses;
    static inline std::vector<std::unique_ptr<Bullet>> bullets;

    static inline sf::Texture enemiestex;
    static inline sf::Texture sniperenemytex;
    static inline sf::Texture fatenemytex;
    static inline sf::Texture microwaveenemytex;
    static inline sf::Texture bossenemytex;
    double health;
    Enemy(double health_) ;
    virtual auto behaviour(Player const& player)->void=0;

    auto takedmg(int dmg) ->void;

    static auto applyenemybehaviour(Player const& player, sf::RenderWindow &window)->void;


    static auto applybulletsbehaviour(sf::RenderWindow & window)->void;

    static auto hitdetection(Player &player)->void;


    };


