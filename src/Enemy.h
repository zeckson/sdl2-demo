//
// Created by Evgenii Shchepotev on 10.08.2023.
//

#ifndef SDL2_DEMO_ENEMY_H
#define SDL2_DEMO_ENEMY_H

#define ENEMY_SPEED (PLAYER_SPEED / 2)

#include "Entity.h"

class Enemy: public Entity {
public:
    Enemy(SDL_Texture& texture, int x, int y): Entity(texture, x, y) {};

    ~Enemy() override = default;

    bool update(World &world) override;

    void onKeyDown(const SDL_Keysym &key) override;

    void onKeyUp(const SDL_Keysym &key) override;

private:
    int xVel = 0, yVel = ENEMY_SPEED;
};


#endif //SDL2_DEMO_ENEMY_H
