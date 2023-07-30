//
// Created by Evgenii Shchepotev on 27.07.2023.
//

#ifndef SDL2_DEMO_PLAYER_H
#define SDL2_DEMO_PLAYER_H

#include "Entity.h"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 102


class Player : public Entity {
public:
    explicit Player(SDL_Texture *texture, int x, int y) :
            Entity(PLAYER_WIDTH, PLAYER_HEIGHT, x - PLAYER_WIDTH / 2, y - PLAYER_HEIGHT / 2), texture(texture) {};

    void update(World<Entity*> *world) override;
    void render(SDL_Renderer *sdlRenderer) override;

private:
    SDL_Texture *texture;
};


#endif //SDL2_DEMO_PLAYER_H
