//
// Created by Evgenii Shchepotev on 25.07.2023.
//

#ifndef SDL2_DEMO_ENTITY_H
#define SDL2_DEMO_ENTITY_H

#include "../World.h"
#include <SDL_render.h>

class Entity {
public:
    Entity(SDL_Texture &texture, int x, int y) : texture(texture), rect{x, y, 0, 0} {
        SDL_QueryTexture(&texture, nullptr, nullptr, &rect.w, &rect.h);
        rect.x = rect.x - rect.w / 2;
        rect.y = rect.y - rect.h / 2;
    };

    virtual ~Entity() = default;

    SDL_Texture &texture;
    SDL_Rect rect;

    virtual bool update(World &world) = 0;

    void render(SDL_Renderer *sdlRenderer);

    virtual void onKeyDown(const SDL_Keysym &key) {};

    virtual void onKeyUp(const SDL_Keysym &key) {};
};


#endif //SDL2_DEMO_ENTITY_H
