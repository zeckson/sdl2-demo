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
    Entity(SDL_Texture *texture, int x, int y): texture(texture), rect{x, y, 0, 0} {
        SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    };

    SDL_Texture *texture;
    SDL_Rect rect;

    virtual void update(World<Entity *> *world) = 0;
    void render(SDL_Renderer *sdlRenderer);
};


#endif //SDL2_DEMO_ENTITY_H
