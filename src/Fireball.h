//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#ifndef SDL2_DEMO_FIREBALL_H
#define SDL2_DEMO_FIREBALL_H


#include "Entity.h"

class Fireball: public Entity {
public:
    explicit Fireball(SDL_Texture *texture, int x, int y): Entity(texture, x, y) {}

    void update(World<Entity *> *world) override {

    }
};


#endif //SDL2_DEMO_FIREBALL_H
