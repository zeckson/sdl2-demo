//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#include <SDL_keyboard.h>
#include "Player.h"
#include "Fireball.h"

void Player::update(World<Entity*> *world) {
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

    //bounds checking and correction
    if (rect.x < 0) {
        rect.x = 0;
    } else if (rect.x + rect.w - 1 >= world->width) {
        rect.x = world->width - rect.w;
    }
    if (rect.y < 0) {
        rect.y = 0;
    } else if (rect.y + rect.h - 1 >= world->height) {
        rect.y = world->height - rect.h;
    }

    if (state[SDL_SCANCODE_SPACE]) {
        Fireball *pFireball = world->factory->createFireball(rect.x, rect.y);
        world->entities.push_back(pFireball);
    }

}
