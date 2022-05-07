//
// Created by Maxime on 02/05/2022.
//

#include "Collider.h"

using namespace std;

Collider::Collider(sf::RectangleShape &body):
    body(body)
    {

}

bool Collider::checkCollision(Collider other, sf::Vector2<float> direction, float push) {
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.f && intersectY < 0.f) {
        push = min(max(push, 0.f), 1.f);

        if (intersectX > intersectY) {

            if (deltaX > 0.f) {
                move(intersectX * (1.f - push), 0.f);
                other.move(-intersectX * push, 0.f);

                direction.x = 1.f;
                direction.y = 0.f;
            }
            else {
                move(-intersectX * (1.f - push), 0.f);
                other.move(intersectX * push, 0.f);

                direction.x = -1.f;
                direction.y = 0.f;
            }
        }
        else {

            if (deltaY > 0.f) {
                move(0.f, intersectY  * (1.f - push));
                other.move(0.f, -intersectY * push);

                direction.x = 0.f;
                direction.y = 1.f;
            }
            else {
                move(0.f, -intersectY * (1.f - push));
                other.move(0.f, intersectY * push);

                direction.x = 0.f;
                direction.y = -1.f;
            }
        }
        return true;
    }



    return false;
}

Collider::~Collider() = default;
