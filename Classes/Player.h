#pragma once
#include <memory>

#include "Player.h"

#include "Bullet.h"
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/Sprite.hpp"
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/Texture.hpp"
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/System/Clock.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


struct Player: sf::Sprite {
    int dmg =1;
    double maxhealth=5;
    double health = maxhealth;
    int speed = 5;
    bool isrolling = false;
    bool left=false;
    bool right=false;
    bool up=false;
    bool down=false;
    int radius=5;
    sf::IntRect rectSourceSprite= sf::IntRect(0,0,32,32);
    sf::IntRect rectGunSprite= sf::IntRect(0,0,32,32);
    sf::Texture playertex;
    sf::Texture guntex;
    sf::Clock animationclock;
    sf::Sprite gun;
    int frame=1;

    Player();

    auto takedmg(int dmg)->void;

    static inline std::vector<std::unique_ptr<Bullet>> bullets;
    sf::Clock pewpewspeed;
    double Playerpewpewinterval = 0.5; //lower to shoot faster
    int inaccuracy = 30;

    auto shoot(sf::RenderWindow const& window, sf::Vector2f const& MousePossition) -> void ;

    bool gunanimationgate = false;

    auto moving()->void;

    auto gunanimate(sf::RenderWindow const& window, sf::Vector2f const& MousePossition)->void;

    bool rollLeft=false;
    bool rollRight=false;
    bool rollDown=false;
    bool rollUp=false;
    bool rollStarted=false;

    auto rolling()->void;

    sf::Clock rollcooldownclock;
    double rollcooldown = 0.1;

    auto invokerolling()->void;

    auto behaviour(sf::RenderWindow & window)->void;

    auto applybulletbehaviour(sf::RenderWindow &window)->void;

    auto hitdetection()->void;
};

