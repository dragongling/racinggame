//
// Created by dragongling on 4/7/15.
//

#ifndef GAME1_TEXTURE_H
#define GAME1_TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Coordinates.h"

class Texture {
public:
    //TODO: make correct visibility scopes and constants:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    Coordinates position, originalScale, scale, positionOffset;
    double angle;

    Texture(const std::string &filename, SDL_Renderer *renderer, Coordinates position,
        Coordinates scale);
    Texture(const std::string &filename, SDL_Renderer *renderer, Coordinates position = Coordinates());
    void load(const std::string &filename, SDL_Renderer *renderer);
    void render();
    Coordinates centerOffset();
    ~Texture();
};


#endif //GAME1_TEXTURE_H
