//
// Created by Evgenii Shchepotev on 25.07.2023.
//

#ifndef SDL2_DEMO_ENTITY_H
#define SDL2_DEMO_ENTITY_H

#include <list>
#include <SDL_render.h>

template<class T>
struct World {
    World(int width, int height) : width(width), height(height) {};

    int width;
    int height;

    std::list<T> entities{};
};

class Entity {
public:
    Entity(short width, short height, int x, int y) :
            rect{x, y, width, height} {};

    SDL_Rect rect;

    virtual void update(World<Entity *> *world) = 0;
    virtual void render(SDL_Renderer *sdlRenderer) = 0;
};


#endif //SDL2_DEMO_ENTITY_H
