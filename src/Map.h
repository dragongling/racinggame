//
// Created by alexander on 4/9/15.
//

#ifndef GAME1_MAP_H
#define GAME1_MAP_H

#include <array>
#include <vector>
#include "Coordinates.h"
#include "Texture.h"

class Map {
public:
    Coordinates tileOffset = Coordinates(0,0), textureOffset = Coordinates(0,0), textureSize;
    SDL_Renderer *renderer;
    Coordinates *windowScale;

    Map(const Coordinates _size, SDL_Renderer *renderer, Coordinates *windowScale, const Coordinates textureSize,
        const Coordinates tileOffset, const Coordinates textureOffset);

    void addTexture(const std::string &filename);
    void render();
    void move(const Coordinates moveCoords);
    unsigned char* operator[](const size_t rvalue);

    ~Map();

protected:
    std::vector< Texture* > texturePool;
    Coordinates size;
    unsigned char** mapArray;
};


#endif //GAME1_MAP_H
