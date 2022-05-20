//
// Created by Maxime on 02/05/2022.
//

#include <SFML/Graphics.hpp>

#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H


class Collider {
public:
    explicit Collider(sf::RectangleShape &body);
    ~Collider();

    void move(float deltaX, float deltaY) { body.move(deltaX, deltaY); }
    bool checkCollision(Collider other, sf::Vector2<float> directon, float push);
    int getSide(Collider other);
    sf::Vector2f getPosition() { return body.getPosition(); }
    sf::Vector2f getHalfSize() { return body.getSize() / 2.f; }

private:
    sf::RectangleShape &body;
};


#endif //GAME_COLLIDER_H
