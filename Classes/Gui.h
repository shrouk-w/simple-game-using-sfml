#pragma once
#include <vector>

#include "Player.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

struct Gui {
    std::vector<sf::RectangleShape> slots;
    Gui();
    sf::RectangleShape playerhp;
    sf::RectangleShape playerhpbackground;
    auto displaygui(sf::RenderWindow &window, Player const& player)->void;
};

