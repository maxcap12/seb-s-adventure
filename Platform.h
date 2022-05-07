//
// Created by Maxime on 03/05/2022.
//

#include <SFML/Graphics.hpp>
#include "Collider.h"
#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H


class Platform {
public:
    Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void Draw(sf::RenderWindow &window) { window.draw(body); }
    Collider getCollider() { return Collider(body); }

private:
    sf::RectangleShape body;
};


#endif //GAME_PLATFORM_H
