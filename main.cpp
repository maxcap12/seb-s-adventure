#include <SFML/Graphics.hpp>
#include "animation.h"
#include "Player.h"
#include "Platform.h"
#include "global.h"

#define FPS 60
#define WINDOW_W 1200.f
#define WINDOW_H 800.f


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "SFML Application", sf::Style::Default); // Creation of the window
    window.setFramerateLimit(FPS); // Set max FPS

    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(WINDOW_W, WINDOW_H)); // Creation of the view

    sf::Texture playerTexture; // Initialisation of the texture of the player
    playerTexture.loadFromFile("../assets/player_texture2.png"); // Load of the texture

    Animation animation(&playerTexture, sf::Vector2u(8, 4), 0.3f); // Set up of the animation

    Player player(&playerTexture, sf::Vector2u(8, 4), 0.2f, 200.f, 200.f); // Set up of the player

    levelTest(window, view, player);
    level1(window, view, player);
}




