//
// Created by Evgenii Shchepotev on 10.08.2023.
//

#ifndef SDL2_DEMO_ENEMY_H
#define SDL2_DEMO_ENEMY_H

#include "Entity.h"


class Enemy: public Entity {
public:
    ~Enemy() override = default;

    bool update(World<Entity *> &world) override;

    void onKeyDown(const SDL_Keysym &key) override;

    void onKeyUp(const SDL_Keysym &key) override;
};


#endif //SDL2_DEMO_ENEMY_H
