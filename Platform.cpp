//
// Created by Maxime on 03/05/2022.
//

#include <cmath>
#include "Platform.h"
#include <iostream>

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, GameEvents &GameEvents,
                   std::string Platformtype, float moveSpeed, sf::Vector2f p1, sf::Vector2f p2):
        events(GameEvents)
{
    body.setSize(size);
    body.setOrigin(size / 2.f);
    body.setPosition(position);
    body.setTexture(texture);
    type = Platformtype;
    speed = moveSpeed;
    point1 = p1;
    point2 = p2;
}

void Platform::UpdatePosition(float deltaTime) {
    if (speed) {
        sf::Vector2f vector;
        vector.x = point2.x - point1.x;
        vector.y = point2.y - point1.y;
        sf::Vector2f velocity;
        if (vector.x) vector /= vector.x;
        else vector /= vector.y;

        if (direction == 1)
            velocity = vector * speed;
        else
            velocity = -vector * speed;

        body.move(velocity * deltaTime);
        sf::Vector2f pos = body.getPosition();

        float p1p2 = sqrtf(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)); // distance between point1 and point2
        float p1pos = sqrtf(pow(pos.x - point1.x, 2) + pow(pos.y - point1.y, 2)); // distance between current position and point1
        float p2pos = sqrtf(pow(pos.x - point2.x, 2) + pow(pos.y - point2.y, 2)); // distance between current posiiton and point2

        if (p1pos >= p1p2 || p2pos >= p1p2) direction = 3 - direction;
        }
}



Platform::~Platform() = default;
