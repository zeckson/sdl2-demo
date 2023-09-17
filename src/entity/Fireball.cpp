//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#include "Fireball.h"

bool Fireball::update(World &world) {
    int velocity = rect.h;

    rect.y -= velocity;

    for (const auto enemy: world.enemies) {
        if (SDL_HasIntersection(&enemy->rect, &this->rect)) {
            enemy->state = State::DEAD;
        }
    }


    return rect.y + rect.h < 0;
}
