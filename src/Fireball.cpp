//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#include "Fireball.h"

void Fireball::update(World<Entity *> *world) {
    int velocity = rect.h;

    rect.y -= velocity;

    if (rect.y < 0) {
        rect.y = world->height;
    }
}
