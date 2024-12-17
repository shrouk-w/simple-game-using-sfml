#include "Gui.h"

#include "Item.h"

Gui::Gui() {
    for(int i=0;i<4;i++) {
        slots.push_back(sf::RectangleShape());
        slots.back().setSize(sf::Vector2f(100,100));
        slots.back().setOrigin(slots.back().getSize().x/2,slots.back().getSize().y/2);
        slots.back().setFillColor(sf::Color(128,128,128,200));
        slots.back().setOutlineThickness(2);
        slots.back().setOutlineColor(sf::Color(50,50,50,200));
    }
    playerhpbackground=sf::RectangleShape();
    playerhp=sf::RectangleShape();
    playerhp.setFillColor(sf::Color(200,0,0,200));
    playerhpbackground.setFillColor(sf::Color(120,120,120,200));
    playerhpbackground.setOutlineThickness(3);
    playerhpbackground.setOutlineColor(sf::Color(200,200,200,255));
}

auto Gui::displaygui(sf::RenderWindow &window, Player const &player) -> void {
    sf::View view = window.getView();
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f position = sf::Vector2f(viewCenter.x-viewSize.x/8,viewCenter.y+viewSize.y/3 + 60);
    for(int i=0;i<slots.size(); i++) {
        slots[i].setPosition(position);
        window.draw(slots[i]);
        if(Item::activeitems.size()>i) {
            Item::activeitems[i]->setPosition(position.x+41,position.y+40);
            Item::activeitems[i]->setScale(2.5,2.5);
            window.draw(*Item::activeitems[i]);
        }
        position.x+=(viewSize.x/12);
    }

    playerhpbackground.setPosition(viewCenter.x-viewSize.x/2+60,viewCenter.y-viewSize.y/2+60);
    playerhp.setPosition(viewCenter.x-viewSize.x/2+60,viewCenter.y-viewSize.y/2+60);
    playerhpbackground.setSize(sf::Vector2f(player.maxhealth*70,30));
    playerhp.setSize(sf::Vector2f(player.health*70,30));
    window.draw(playerhpbackground);
    window.draw(playerhp);

}




