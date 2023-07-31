//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#ifndef SDL2_DEMO_PLAYER_H
#define SDL2_DEMO_PLAYER_H

#include "Entity.h"


class Player : public Entity {
public:
    explicit Player(SDL_Texture *texture, int x, int y) :
            Entity(texture, x, y) {};

    void update(World<Entity*> *world) override;
};


#endif //SDL2_DEMO_PLAYER_H
