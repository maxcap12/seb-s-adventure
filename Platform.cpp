//
// Created by Maxime on 03/05/2022.
//

#include "Platform.h"

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setOrigin(size / 2.f);
    body.setPosition(position);
    body.setTexture(texture);
}

Platform::~Platform() = default;
