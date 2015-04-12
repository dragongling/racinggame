//
// Created by alexander on 4/8/15.
//

#include "Player.h"

Player::Player(Texture *texture) {
    this->texture = texture;
}

Player::~Player() {
    this->texture = nullptr;
}

void Player::handleEvent(const SDL_Event event) {
    if (event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym){
            case SDLK_RIGHT:
                angle.right = true;
                break;
            case SDLK_LEFT:
                angle.left = true;
                break;
            case SDLK_UP:
                move.forward = true;
                break;
            case SDLK_DOWN:
                move.backward = true;
                break;
            default:
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT:
                angle.right = false;
                break;
            case SDLK_LEFT:
                angle.left = false;
                break;
            case SDLK_UP:
                move.forward = false;
                break;
            case SDLK_DOWN:
                move.backward = false;
                break;
            default:
                break;
        }
    }
}

void Player::handleControl(Map &map) {
    if(move.forward) {
        if (angle.right)
            texture->angle++;
        if (angle.left)
            texture->angle--;
        map.move(Coordinates(static_cast<int>(speed * cos(texture->angle * 0.017453292519)),
                             static_cast<int>(speed * sin(texture->angle * 0.017453292519))));
    }
    if(move.backward) {
        if (angle.right)
            texture->angle--;
        if (angle.left)
            texture->angle++;
        map.move(Coordinates(-static_cast<int>(speed * 0.5 * cos(texture->angle * 0.017453292519)),
                             -static_cast<int>(speed * 0.5 * sin(texture->angle * 0.017453292519))));
    }
}
