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
            default:
                break;
        }
    }
}

void Player::handleControl() {
    if(angle.right)
        texture->angle++;
    if(angle.left)
        texture->angle--;
}
