//
// Created by Maxime on 10/05/2022.
//

#include "global.h"
#include "Platform.h"
#include "Player.h"

void onCollision(int direction, Player &player, std::vector<Platform> platforms, int index) {
    Platform platform = platforms[index];

    switch (platform.events.getEvent(direction)) {

        case NONE:
            std::cout << "colision issue" << std::endl;
            break;

        case BLOCK:
            player.Collision();
            break;

        case SPAWN:
            std::cout << "spawn an object" << std::endl;
            break;

        case DISAPEAR:
            std::cout << "an ennemi/object disapear" << std::endl;
            break;

        case BOUNCE:
            std::cout << "the player bounce back" << std::endl;
            break;

        case DAMAGE:
            player.Damage();
            break;

        case USE:
            player.Use(platform.getType());
            break;

        case CHECKPOINT:
            std::cout << "checkpoint" << std::endl;
            break;

        case WIN:
            std::cout << "win" << std::endl;
            break;
    }

}
