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

    void onKeyDown(const SDL_Keysym &key) override;

    void onKeyUp(const SDL_Keysym &key) override;

    bool update(World<Entity*> *world) override;
private:
    int xVel = 0, yVel = 0;
    bool fire = false;
};


#endif //SDL2_DEMO_PLAYER_H
