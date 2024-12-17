#include <iostream>
#include <SFML/Graphics.hpp>
#include "Classes/Player.h"
#include "Classes/Room.h"
#include "Classes/simpleEnemy.h"
#include <windows.h>
#include "Classes/Gui.h"
#include <fstream>


auto main() -> int {

    Gui gui = Gui();

    Player player;

    auto window = sf::RenderWindow(
            sf::VideoMode(1800, 1000),
            "TotallyNotIsacClone",
            sf::Style::Default,
            sf::ContextSettings(0, 0, 16)
    );

    sf::View view(sf::FloatRect(0, 0, 1800, 1000));

    window.setFramerateLimit(60);

    bool start=true;

    sf::Sprite startscreen;
    startscreen = sf::Sprite();
    sf::Texture GameStartScreen;
    GameStartScreen = sf::Texture();
    if(!GameStartScreen.loadFromFile("Textures/GameStartScreen.png"))
        std::cout<<"cant find start screen texture";
    startscreen.setTexture(GameStartScreen);

    sf::Sprite losescreen;
    losescreen = sf::Sprite();
    sf::Texture GameLostScreen;
    GameLostScreen = sf::Texture();
    if(!GameLostScreen.loadFromFile("Textures/GameLostScreen.png"))
        std::cout<<"cant find lose screen texture";
    losescreen.setTexture(GameLostScreen);
    losescreen.setOrigin(losescreen.getGlobalBounds().width/2,losescreen.getGlobalBounds().height/2);

    sf::Sprite winscreen;
    winscreen = sf::Sprite();
    sf::Texture GameWinScreen;
    GameWinScreen = sf::Texture();
    if(!GameWinScreen.loadFromFile("Textures/GameWinScreen.png"))
        std::cout<<"cant find win screen texture";
    winscreen.setTexture(GameWinScreen);
    winscreen.setOrigin(winscreen.getGlobalBounds().width/2,winscreen.getGlobalBounds().height/2);

    while(start) {
        window.clear();
        window.draw(startscreen);
        window.display();
        for (auto event = sf::Event(); window.pollEvent(event); ) {
            if (event.type == sf::Event::KeyPressed)
                start=false;
        }
    }

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        for (auto event = sf::Event(); window.pollEvent(event); ) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) player.left = true;
                if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) player.right = true;
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) player.up = true;
                if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) player.down = true;
                if (event.key.code == sf::Keyboard::Space ) player.invokerolling();

            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) player.left = false;
                if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) player.right = false;
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) player.up = false;
                if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) player.down = false;
            }
        }

        Room::ManageRooms(window,player);
        Room::restrictPlayer(player);
        Room::restrictEnemies();
        Room::restrictBullets(player);
        Room::loadwaves();

        player.behaviour(window);
        player.hitdetection();
        player.applybulletbehaviour(window);

        Enemy::applyenemybehaviour(player,window);
        Enemy::hitdetection(player);
        Enemy::applybulletsbehaviour(window);


        if(player.health<=0) {
            Sleep(1000);
            losescreen.setPosition(window.getView().getCenter());
            while(true) {
                window.clear();
                window.draw(losescreen);
                window.display();
                for (auto event = sf::Event(); window.pollEvent(event); ) {
                    if (event.type == sf::Event::KeyPressed) {
                        window.close();
                        return 0;
                    }
                }
            }
        }

        if(Room::win) {
            Sleep(1000);
            winscreen.setPosition(window.getView().getCenter());
            while(true) {
                window.clear();
                window.draw(winscreen);
                window.display();
                for (auto event = sf::Event(); window.pollEvent(event); ) {
                    if (event.type == sf::Event::KeyPressed) {
                        window.close();
                        return 0;
                    }
                }
            }
        }

        view.setCenter(player.getPosition());
        window.setView(view);

        window.draw(player);
        window.draw(player.gun);

        gui.displaygui(window, player);
        window.display();

        }

    }
