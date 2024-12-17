#include "Player.h"
#include "Bullet.h"

#include <cmath>
#include <iostream>


#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Mouse.hpp"
#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Item.h"
#include "MultiuseFunctionsLib.h"
#include "playerBullet.h"

Player::Player() {
    if (!playertex.loadFromFile("Textures/playeranim.png")) {
        std::cout << "cant find player texture";
    }
    if (!guntex.loadFromFile("Textures/gun.png")) {
        std::cout << "cant find gun texture";
    }
    this->setTexture(playertex);
    this->setTextureRect(rectSourceSprite);
    this->setScale(sf::Vector2f(2, 2)); //1 full size 0.5 half size 2 twice size and so on
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    gun = sf::Sprite(guntex);
    gun.setScale(1.2, 1.2);
    gun.setOrigin(-getGlobalBounds().width / 5, 4);
    gun.setTextureRect(rectGunSprite);
}


auto Player::invokerolling() -> void {
    if (rollcooldownclock.getElapsedTime().asSeconds() > rollcooldown) {
        rollcooldownclock.restart();
        isrolling = true;
    }
}

auto Player::takedmg(int dmg) -> void {
    health -= dmg;
}

auto Player::shoot(sf::RenderWindow const &window, sf::Vector2f const &MousePossition) -> void {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pewpewspeed.getElapsedTime().asSeconds() >
        Playerpewpewinterval) {
        bullets.push_back(std::make_unique<playerBullet>(radius, 10, dmg, 8,
                                                         std::atan2(MousePossition.y - gun.getPosition().y,
                                                                    // atan2 gets us angle between mouse and object
                                                                    MousePossition.x - gun.getPosition().x) +
                                                         AddInaccuracy(inaccuracy)));
        bullets.back()->setPosition(getPosition());
        pewpewspeed.restart();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Item::applyitemsbehaviour(*this, window);
    }
}

auto Player::applybulletbehaviour(sf::RenderWindow &window) -> void {
    for (auto const &bullet: bullets) {
        bullet->behaviour(window);
    }
}

auto Player::rolling() -> void {
    if (!rollStarted) {
        rollDown = rollLeft = rollRight = rollUp = false;
        if (left)rollLeft = true;
        if (right)rollRight = true;
        if (up)rollUp = true;
        if (down)rollDown = true;
        rollStarted = true;
        isrolling = true;
    }

    if ((left && right) || (up && down)
        || !rollLeft && !rollRight && !rollDown && !rollUp
        || (rollDown + rollUp + rollLeft + rollRight >= 3)) {
        rollStarted = false; //otherwise it locks player when trying to roll and no direction is choosen
        isrolling = false; //or when 3+ keys are choosen
        return; // or when contradidatory directions are choosen
    }
    if (rollLeft) move(-speed * 1.7, 0);
    if (rollRight) move(speed * 1.7, 0);
    if (rollUp) move(0, -speed * 1.7);
    if (rollDown) move(0, speed * 1.7);

    if (animationclock.getElapsedTime().asSeconds() > 0.2) {
        if (rollRight) {
            if (rectSourceSprite.top != 160)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 160;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            frame++;
            rectSourceSprite.left = (rectSourceSprite.left + 32) % 128;
            if (frame == 4)
                frame = 1;
        }
        if (rollLeft) {
            if (rectSourceSprite.top != 192)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 192;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            frame++;
            rectSourceSprite.left = (rectSourceSprite.left + 32) % 128;
            if (frame == 4)
                frame = 1;
        } else if (rollDown && !rollLeft && !rollRight && !rollUp) {
            if (rectSourceSprite.top != 224)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 224;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            frame++;
            rectSourceSprite.left = (rectSourceSprite.left + 32) % 128;
            if (frame == 4)
                frame = 1;
        } else if (rollUp && !rollLeft && !rollRight && !rollDown) {
            if (rectSourceSprite.top != 256)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 256;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            frame++;
            rectSourceSprite.left = (rectSourceSprite.left + 32) % 128;
            if (frame == 4)
                frame = 1;
        }
        animationclock.restart();
    }
}

auto Player::gunanimate(sf::RenderWindow const &window, sf::Vector2f const &MousePossition) -> void {
    gun.setPosition(this->getPosition().x, this->getPosition().y);


    gun.setRotation(atan2(MousePossition.y - gun.getPosition().y,
                          MousePossition.x - gun.getPosition().x) * 180 / 3.14);

    if (!gunanimationgate && gun.getRotation() < 270 && gun.getRotation() > 90) {
        gun.scale(1.f, -1.f); // reverse texture vertically
        gunanimationgate = true;
    } else if (gunanimationgate && !(gun.getRotation() < 270 && gun.getRotation() > 90)) {
        gun.scale(1.f, -1.f);
        gunanimationgate = false;
    }
}

auto Player::moving() -> void {
    if (left) move(-speed, 0);
    if (right) move(speed, 0);
    if (up) move(0, -speed);
    if (down) move(0, speed);

    //everything below is player animation
    if (animationclock.getElapsedTime().asSeconds() > 0.25) {
        if ((right) && !left) {
            if (rectSourceSprite.top != 32)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 32;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            if (rectSourceSprite.left == 32)
                frame = 1;
            else
                frame++;
            rectSourceSprite.left += 32;
        } else if ((left) && !right) {
            if (rectSourceSprite.top != 64)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 64;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            if (rectSourceSprite.left == 32) {
                frame = 1;
            } else
                frame++;
            rectSourceSprite.left += 32;
        } else if (up && !down) {
            if (rectSourceSprite.top != 96)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 96;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            if (rectSourceSprite.left == 32) {
                frame = 1;
            } else
                frame++;
            rectSourceSprite.left += 32;
        } else if (down && !up) {
            if (rectSourceSprite.top != 128)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 128;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            if (rectSourceSprite.left == 32) {
                frame = 1;
            } else
                frame++;
            rectSourceSprite.left += 32;
        } else {
            if (rectSourceSprite.top != 0)
                frame = 1;
            if (frame == 1) {
                rectSourceSprite.top = 0;
                rectSourceSprite.left = 0;
            }
            this->setTextureRect(rectSourceSprite);
            if (rectSourceSprite.left == 32) {
                frame = 1;
            } else
                frame++;
            rectSourceSprite.left += 32;
        }
        animationclock.restart();
    }
}

auto Player::behaviour(sf::RenderWindow &window) -> void {
    if (isrolling) {
        rolling();
        if (frame == 1) {
            isrolling = false;
            rollDown = false;
            rollLeft = false;
            rollRight = false;
            rollUp = false;
            rollStarted = false;
        }
    }
    if (!isrolling) {
        moving();
    }
    sf::Vector2i MouseWindowPossition = sf::Mouse::getPosition(window);
    sf::Vector2f MouseViewPossition = window.mapPixelToCoords(MouseWindowPossition);

    gunanimate(window, MouseViewPossition);
    shoot(window, MouseViewPossition);
}

auto Player::hitdetection() -> void {
    for (int i = bullets.size() - 1; i >= 0; i--) {
        for (int j = Enemy::enemies.size() - 1; j >= 0; j--) {
            if (bullets[i]->getGlobalBounds().intersects(Enemy::enemies[j]->getGlobalBounds())) {
                Enemy::enemies[j]->takedmg(bullets[i]->dmg);
                bullets.erase(bullets.begin() + i);
                if (Enemy::enemies[j]->health <= 0)
                    Enemy::enemies.erase(Enemy::enemies.begin() + j);
                return; //otherwise rarely game crashes because of trying to acces deleted element
            }
        }

        for (int j = Enemy::bosses.size() - 1; j >= 0; j--) {
            if (bullets[i]->getGlobalBounds().intersects(Enemy::bosses[j]->getGlobalBounds())) {
                Enemy::bosses[j]->takedmg(bullets[i]->dmg);
                bullets.erase(bullets.begin() + i);
                if (Enemy::bosses[j]->health <= 0)
                    Enemy::bosses.erase(Enemy::bosses.begin() + j);
                return;
            }
        }
    }
}
