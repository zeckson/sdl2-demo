//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#include <SDL_keyboard.h>
#include "Player.h"
#include "Fireball.h"

bool Player::update(World<Entity *> &world) {
    //move rect
    rect.y += yVel;
    rect.x += xVel;

    //bounds checking and correction
    if (rect.x < 0) {
        rect.x = 0;
    } else if (rect.x + rect.w - 1 >= world.width) {
        rect.x = world.width - rect.w;
    }
    if (rect.y < 0) {
        rect.y = 0;
    } else if (rect.y + rect.h - 1 >= world.height) {
        rect.y = world.height - rect.h;
    }

    if (fire) {
        fire = false;
        Fireball *pFireball = world.factory.createFireball(rect.x + rect.w / 2, rect.y);
        world.entities.push_back(pFireball);
    }

    return false;
}

void Player::onKeyDown(const SDL_Keysym &key) {
    Entity::onKeyDown(key);
    int speed = rect.w / 4;

    switch (key.scancode) {
        case SDL_SCANCODE_UP:
            yVel = -speed;
            break;
        case SDL_SCANCODE_DOWN:
            yVel = speed;
            break;
        case SDL_SCANCODE_LEFT:
            xVel = -speed;
            break;
        case SDL_SCANCODE_RIGHT:
            xVel = speed;
            break;
        default:
            // do nothing
            break;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                   "Player speed keydown [xVel, yVel]: [%d, %d]", xVel, yVel);

    if (key.scancode == SDL_SCANCODE_SPACE) {
        fire = true;
    }

}

void Player::onKeyUp(const SDL_Keysym &key) {
    Entity::onKeyUp(key);
    switch (key.scancode) {
        case SDL_SCANCODE_UP:
        case SDL_SCANCODE_DOWN:
            yVel = 0;
            break;
        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_RIGHT:
            xVel = 0;
            break;
        default:
            // ignore
            break;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                   "Player speed keyup [xVel, yVel]: [%d, %d]", xVel, yVel);
}
