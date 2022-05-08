//
// Created by Maxime on 07/05/2022.
//

#include "global.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

bool level1(sf::RenderWindow &window, sf::View &view, Player &player) {
    vector<Platform> platforms; // Vector with all platforms
    platforms.emplace_back(nullptr, sf::Vector2f(1000.f, 200.f), sf::Vector2f(500.f, 500.f)); // Creation of the ground platform
    platforms.emplace_back(nullptr, sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 100.f), 100.f, sf::Vector2f(100.f, 100.f), sf::Vector2f(1000.f, 100.f));

    float deltaTime; // Initialisation of the time
    sf::Clock clock;


    while (window.isOpen()) // Global loop
    {
        deltaTime = clock.restart().asSeconds(); // Set deltatime at all loops
        if (deltaTime > 1.f / 20.f)
            deltaTime = 1.f / 20.f;

        sf::Event event{};

        while (window.pollEvent(event))
        {
            switch (event.type) {

                case sf::Event::Closed: // Close the window
                    window.close();
                    break;

                case sf::Event::Resized: // Resize the window
                    resizeView(window, view);
                    break;

                default:
                    break;
            }

        }

        player.Update(deltaTime); // Update the position of the player

        for (Platform &platform: platforms) {
            platform.UpdatePosition(deltaTime);
        }

        sf::Vector2f direction; // Initialise direction

        // !! ISSUE WITH DIRECTION VAR fix akhy si t'as le temps !! //
        // (j'ai plus de bug mtn donc ca a l'air d'etre ok) //
        for (Platform &platform: platforms) // Loop of all platforms
            if (platform.getCollider().checkCollision(player.getCollider(), direction, 1.f)) // Check collisions
                player.onCollision(direction); // Stop the collision

        setView(view, player.getPosition().x); // Set the view on the player

        window.clear(); // Clear all

        window.setView(view); // Set the view
        player.Draw(window); // Draw the player

        for (Platform &platform: platforms) // Draw all platforms
            platform.Draw(window);

        window.display();
    }

    return true;

}

