//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#ifndef SDL2_DEMO_PLAYER_H
#define SDL2_DEMO_PLAYER_H

#include "Entity.h"

#define PLAYER_WIDTH 42
#define PLAYER_HEIGHT 72


class Player : public Entity {
public:
    explicit Player(int x, int y) :
            Entity(PLAYER_WIDTH, PLAYER_HEIGHT, x - PLAYER_WIDTH / 2, y - PLAYER_HEIGHT / 2) {};

    void update(World<Entity*> *world) override;

};


#endif //SDL2_DEMO_PLAYER_H
