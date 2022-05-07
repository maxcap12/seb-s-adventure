//
// Created by Maxime on 30/04/2022.
//

#include "animation.h"


Animation::Animation(Texture *texture, Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    curentImage.x = 0;

    textureRect.width = texture->getSize().x / float(imageCount.x);
    textureRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::update(int row, int column, float deltaTime, bool faceRight) {
    curentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        curentImage.x++;

        if (curentImage.x >= column)
            curentImage.x = 0;
    }

    textureRect.top = curentImage.y * textureRect.height;

    if (faceRight) {
        textureRect.left = curentImage.x * textureRect.width;
        textureRect.width = abs(textureRect.width);
    }
    else {
        textureRect.left = (curentImage.x + 1) * abs(textureRect.width);
        textureRect.width = -abs(textureRect.width);
    }
}



Animation::~Animation() = default;