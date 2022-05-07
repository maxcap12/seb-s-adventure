//
// Created by Maxime on 01/05/2022.
//

#include <SFML/Graphics.hpp>
#include "animation.h"
#include "Collider.h"
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


class Player {
public:
    Player(Texture *texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);
    void onCollision(sf::Vector2f direction);

    sf::Vector2f getPosition() { return player.getPosition(); }
    Collider getCollider() { return Collider(player); }


private:
    sf::RectangleShape player;
    Animation animation;
    unsigned int row;
    float speed;
    bool right;
    sf::Vector2f velocity;
    bool canJump = true;
    float jumHeight;
};


#endif //GAME_PLAYER_H
