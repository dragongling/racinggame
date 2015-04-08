//
// Created by dragongling on 4/7/15.
//

#include <stdexcept>
#include <iostream>
#include "Texture.h"

Texture::Texture(const std::string &filename, SDL_Renderer *renderer, Coordinates position, Coordinates scale) {
    load(filename, renderer);
    this->position = position;
    this->scale = scale;
    angle = 0.0;
}

void Texture::load(const std::string &filename, SDL_Renderer *renderer){
    this->renderer = renderer;
    texture = IMG_LoadTexture(renderer, filename.c_str());
    if(texture == nullptr)
        throw std::invalid_argument("Texture " + filename + " not loaded");
    SDL_QueryTexture(texture, NULL, NULL, &originalScale.x, &originalScale.y);
}

void Texture::render() {
    SDL_Rect dst;
    dst.x = position.x + positionOffset.x;
    dst.y = position.y + positionOffset.y;
    dst.w = scale.x;
    dst.h = scale.y;
    SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
}


Texture::Texture(const std::string &filename, SDL_Renderer *renderer, Coordinates position){
    load(filename, renderer);
    this->position = position;
    this->scale = originalScale;
    angle = 0.0;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

Coordinates Texture::centerOffset() {
    return Coordinates(scale.x / 2, scale.y / 2);
}
