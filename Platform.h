//
// Created by Maxime on 03/05/2022.
//

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Events.h"
#include "Player.h"
#include <string>

#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H


class Platform {
public:
    Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, GameEvents &GameEvents,
             std::string Platformtype, float moveSpeed = 0.f, sf::Vector2f point1 = {}, sf::Vector2f point2 = {});
    ~Platform();

    void Draw(sf::RenderWindow &window) { window.draw(body); }
    void UpdatePath(sf::Vector2f p1, sf::Vector2f p2) { point1 = p1; point2 = p2; }
    void UpdateSpeed(float newSpeed) { speed = newSpeed; }
    void UpdatePosition(float deltaTime);

    Collider getCollider() { return Collider(body); }
    std::string getType() { return type; }

    GameEvents &events;

private:
    sf::RectangleShape body;
    float speed;
    sf::Vector2f point1;
    sf::Vector2f point2;
    unsigned int direction = 2;
    std::string type;
};


#endif //GAME_PLATFORM_H
