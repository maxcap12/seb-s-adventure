//
// Created by Maxime on 09/05/2022.
//

#include "Events.h"
#include "Platform.h"
#include <vector>


GameEvents::GameEvents(unsigned int topEvent, unsigned int rightEvent, unsigned int botEvent, unsigned int leftEvent) {
    top = topEvent;
    right = rightEvent;
    bot = botEvent;
    left = leftEvent;
}

int GameEvents::getEvent(unsigned int direction) const {
    if (direction == 1) { return top; }
    if (direction == 2) { return right; }
    if (direction == 3) { return bot; }
    if (direction == 4) { return left; }
    else return -1;
}

void GameEvents::setEvent(unsigned int direction, unsigned int event) {
    if (direction == 1) { top = event; }
    if (direction == 2) { right = event; }
    if (direction == 3) { bot = event; }
    if (direction == 4) { left = event; }
}
