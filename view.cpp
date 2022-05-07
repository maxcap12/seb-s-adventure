//
// Created by Maxime on 07/05/2022.
//

#define VIEW 1200

#include <SFML/Graphics.hpp>
#include "global.h"

void resizeView(const sf::RenderWindow &window, sf::View &view) {
    /* Resize the view
     * &window: reference to the window
     * &view: reference to the view */
    float ratio =  float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW * ratio, VIEW);
}

void setView(sf::View &view, float x, float y) {
    view.setCenter(x, y);
}