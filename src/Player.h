//
// Created by alexander on 4/8/15.
//

#ifndef GAME1_PLAYER_H
#define GAME1_PLAYER_H

#include <SDL2/SDL.h>
#include "Texture.h"

class Player {
public:
    Player(Texture *texture);

    void handleEvent (const SDL_Event event);

    void handleControl();

    ~Player();

protected:
    Texture *texture;
    struct{ bool left, right; } angle {false, false};
};


#endif //GAME1_PLAYER_H
