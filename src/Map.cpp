//
// Created by alexander on 4/9/15.
//

#include <iostream>
#include "Map.h"

Map::Map(const Coordinates size, SDL_Renderer *renderer, Coordinates *windowScale, const Coordinates textureSize,
         const Coordinates tileOffset, const Coordinates textureOffset){
    this->renderer = renderer;
    this->windowScale = windowScale;
    this->textureSize = textureSize;
    mapArray = new unsigned char*[size.y];
    this->size = size;
    for(size_t i = 0; i < size.y; ++i){
        mapArray[i] = new unsigned char[size.x];
    }
    for(size_t y = 0; y < size.y; ++y)
        for(size_t x = 0; x < size.x; ++x){
            mapArray[y][x] = 0;
        }
    this->tileOffset = tileOffset;
    this->textureOffset = textureOffset;
}

void Map::render() {
    Coordinates startTile, endTile;
    startTile.y = tileOffset.y - 1 >= 0 ? tileOffset.y - 1 : 0;
    startTile.x = tileOffset.x - 1 >= 0 ? tileOffset.x - 1 : 0;
    endTile.y = startTile.y + windowScale->y / textureSize.y + 3;
    if(endTile.y > size.y)
        endTile.y = size.y - 1;
    endTile.x = startTile.x + windowScale->x / textureSize.x + 3;
    if(endTile.x > size.x)
        endTile.x = size.x - 1;
    for(int y = startTile.y; y < endTile.y; ++y)
        for(int x = startTile.x; x < endTile.x; ++x){
            if(mapArray[y][x] + 1 > texturePool.size())
                throw std::logic_error("Invalid tile");
            texturePool[mapArray[y][x]]->position = textureSize * Coordinates(x - tileOffset.x,y - tileOffset.y)
                                                    - textureOffset;
            texturePool[mapArray[y][x]]->render();
        }
}

Map::~Map() {
    for(size_t i = 0; i < size.y; ++i){
        delete mapArray[i];
    }
    delete mapArray;
    for(auto texture : texturePool)
        delete texture;
}

void Map::move(const Coordinates moveCoords) {
    this->textureOffset += moveCoords;
    if(textureOffset.x > textureSize.x || textureOffset.x < 0) {
        tileOffset.x += textureOffset.x / textureSize.x;
        textureOffset.x %= textureSize.x;
    }
    if(textureOffset.y > textureSize.y || textureOffset.y < 0) {
        tileOffset.y += textureOffset.y / textureSize.y;
        textureOffset.y %= textureSize.y;
    }
}

void Map::addTexture(const std::string &filename) {
    texturePool.push_back(nullptr);
    texturePool.back() = new Texture(filename, renderer, Coordinates(0,0), textureSize);
}

unsigned char *Map::operator[](const size_t rvalue) {
    return mapArray[rvalue];
}
