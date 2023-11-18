//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#include "Entity.h"

void Entity::render(SDL_Renderer *sdlRenderer) {
    SDL_RenderCopy(sdlRenderer, &texture, nullptr, &rect);
}

void Entity::setPosition(int x, int y) {
    rect.x = x - rect.w / 2;
    rect.y = y - rect.h;
}
