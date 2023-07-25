//
// Created by Evgenii Shchepotev on 25.07.2023.
//

#ifndef SDL2_DEMO_ENTITY_H
#define SDL2_DEMO_ENTITY_H


#include <SDL_render.h>

class Entity{
public:
    Entity(int x, int y): x(x), y(y) {};
    Entity(SDL_Texture *texture, int x, int y): x(x), y(y), texture(texture)  {};
    int x, y;

    SDL_Texture *texture{};

    virtual void update();
};


#endif //SDL2_DEMO_ENTITY_H
