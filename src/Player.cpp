//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#include <SDL_keyboard.h>
#include "Player.h"

void Player::update() {
    int numPixelsToMovePerFrame = rect.w / 4;

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    //move rect
    if (state[SDL_SCANCODE_UP]) {
        rect.y -= numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        rect.y += numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        rect.x -= numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        rect.x += numPixelsToMovePerFrame;
    }

}
