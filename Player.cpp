//
// Created by Maxime on 01/05/2022.
//

#include <cmath>
#include <iostream>
#include "Player.h"

Player::Player(Texture *texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
        animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumHeight = jumpHeight;
    row = 0;
    right = true;

    player.setSize(sf::Vector2f(100.f, 120.f));
    player.setOrigin(player.getSize() / 2.f);
    player.setPosition(350.f, 100.f);
    player.setTexture(texture);
}

Player::~Player() = default;

void Player::Update(float deltaTime) {

    velocity.x = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        velocity.x -= speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
        canJump = false;
        velocity.y = -sqrtf(2.f * 981.f * jumHeight);
    }

    velocity.y += 981.f * deltaTime;

    if (velocity.x == 0.f)
        row = 0;
    else {
        row = 2;

        if (velocity.x > 0.f)
            right = true;
        else
            right = false;
    }

    animation.update(row, 6, deltaTime, right);
    player.setTextureRect(animation.textureRect);
    player.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow &window) {
    /* Draw the player
     * &window: reference to the window */

    window.draw(player);
}

void Player::onCollision(sf::Vector2f direction) {
    /* Reset the speed
     *  direction: direction of the player */

    if (velocity.x != 0.f) // Collision on right or left
        velocity.x = 0.f;

    if (velocity.y > 0.f) { // Collision on bottom
        velocity.y = 0.f;
        canJump = true; // reset of the jump
    }
    else if (velocity.y < 0.f) // Collision on top
        velocity.y = 0.f;
}
