//
// Created by Maxime on 01/05/2022.
//

#include <SFML/Graphics.hpp>
#include "animation.h"
#include "Collider.h"
#include <string>
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


class Player {
public:
    Player(Texture *texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow &window);
    void Collision();
    void Damage();
    void DieAnimation();
    void Use(std::string type);
    void SetPosition(sf::Vector2f pos) { player.setPosition(pos); }
    void Go(sf::Vector2f pos) { player.setPosition(pos); }

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
    std::string state = "basic";
};


#endif //GAME_PLAYER_H
