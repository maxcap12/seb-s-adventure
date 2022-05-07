//
// Created by Maxime on 30/04/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#ifndef HELLOSFML_ANIMATION_H
#define HELLOSFML_ANIMATION_H

using namespace sf;

class Animation {
public:
    Animation(Texture *texture, Vector2u imageCount, float switchTime);
    ~Animation();

    void update(int row, int column, float deltaTime, bool faceRight);

public:
    IntRect textureRect;

private:
    Vector2u imageCount;
    Vector2u curentImage;
    float totalTime;
    float switchTime;
};


#endif //HELLOSFML_ANIMATION_H
