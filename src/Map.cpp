//
// Created by alexander on 4/9/15.
//

#include "Map.h"

Map::Map(const Coordinates size, SDL_Renderer *renderer, const Coordinates textureSize,
         const Coordinates tileOffset, const Coordinates textureOffset){
    this->renderer = renderer;
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
    //TODO: make restrict for end rendered tile dependent of window size
    for(int y = (tileOffset.y - 1 >= 0 ? tileOffset.y - 1 : 0); y < size.y; ++y)
        for(int x = (tileOffset.x - 1 >= 0 ? tileOffset.x - 1 : 0); x < size.x; ++x){
            if(mapArray[y][x] + 1 > texturePool.size())
                throw std::logic_error("Invalid tile");
            texturePool[mapArray[y][x]].position = textureSize * Coordinates(x - tileOffset.x,y - tileOffset.y)
                                                    - textureOffset;
            texturePool[mapArray[y][x]].render();
        }
}

Map::~Map() {
    for(size_t i = 0; i < size.y; ++i){
        delete mapArray[i];
    }
    delete mapArray;
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
    Texture *temp = new Texture(filename, renderer, Coordinates(0,0), textureSize);
    texturePool.push_back(*temp);
}
