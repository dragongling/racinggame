//
// Created by alexander on 4/8/15.
//

#ifndef GAME1_PLAYER_H
#define GAME1_PLAYER_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Map.h"

class Player {
public:
    Player(Texture *texture);

    void handleEvent (const SDL_Event event);

    void handleControl(Map &map);

    ~Player();

protected:
    Texture *texture;
    struct{ bool left, right; } angle {false, false};
    struct{ bool forward, backward; } move{false, false};
    unsigned int speed = 10;
};


#endif //GAME1_PLAYER_H
