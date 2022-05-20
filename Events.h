//
// Created by Maxime on 09/05/2022.
//

#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H

// Events

#define NONE 0
#define BLOCK 1
#define SPAWN 2
#define DISAPEAR 3
#define BOUNCE 4
#define DAMAGE 5
#define USE 6
#define CHECKPOINT 7
#define WIN 8


class GameEvents {
public:
    GameEvents(unsigned int topEvent, unsigned int rightEvent, unsigned int botEvent, unsigned int leftEvent);
    int getEvent(unsigned int direction) const;
    void setEvent(unsigned int direction, unsigned int event);

private:
    unsigned int top;
    unsigned int right;
    unsigned int bot;
    unsigned int left;
};


#endif //GAME_EVENTS_H
