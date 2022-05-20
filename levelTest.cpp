//
// Created by Maxime on 18/05/2022.
//

#include "global.h"

using namespace std;

bool levelTest(sf::RenderWindow &window, sf::View &view, Player &player) {
    sf::Vector2f spawnPoint = {350.f, 100.f};
    player.Go(spawnPoint);

    GameEvents ClassicCollisions(BLOCK, BLOCK, BLOCK, BLOCK);

    vector<Platform> platforms; // Vector with all platforms
    platforms.emplace_back(nullptr, sf::Vector2f(1000.f, 200.f), sf::Vector2f(500.f, 500.f), ClassicCollisions, "platform"); // Creation of the ground platform
    platforms.emplace_back(nullptr, sf::Vector2f(10.f, 40.f), sf::Vector2f(100.f, 100.f), ClassicCollisions, "platform");
    platforms.emplace_back(nullptr, sf::Vector2f(10.f, 40.f), sf::Vector2f(350.f, 0.f), ClassicCollisions, "platform");
    platforms.emplace_back(nullptr, sf::Vector2f(10.f, 40.f), sf::Vector2f(100.f, -100.f), ClassicCollisions, "platform");
    platforms.emplace_back(nullptr, sf::Vector2f(10.f, 40.f), sf::Vector2f(350.f, -200.f), ClassicCollisions, "platform");



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

        int index = 0;

        for (Platform &platform: platforms) {// Loop of all platforms
            if (platform.getCollider().checkCollision(player.getCollider(), direction, 1.f)) // Check collisions
                // player.Collision(); // Stop the collision
                onCollision(1, player, platforms, index);
            index += 1;
        }

        // platform.getCollider().getSide(player.getCollider())

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



