//
// Created by Maxime on 07/05/2022.
//

#ifndef GAME_GLOBAL_H
#define GAME_GLOBAL_H

#define VIEW 1200.f

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.h"
#include "Player.h"
#include "Collider.h"
#include "animation.h"
#include "Events.h"


// Enlever l'effet de glissement contre les murs

bool level1(sf::RenderWindow &window, sf::View &view, Player &player);
bool levelTest(sf::RenderWindow &window, sf::View &view, Player &player);

void resizeView(const sf::RenderWindow &window, sf::View &view);
void setView(sf::View &view, float x, float y = 150.f);
void onCollision(int direction, Player &player, std::vector<Platform> platforms, int index);


#endif //GAME_GLOBAL_H
