//
// Created by Evgenii Shchepotev on 01.08.2023.
//

#ifndef SDL2_DEMO_ENTITYFACTORY_H
#define SDL2_DEMO_ENTITYFACTORY_H

#include "window.h"
#include "SDL.h"

// Forward declaration
class Player;
class Fireball;

class EntityFactory {
public:
    EntityFactory(window::App *app) : app(app) {
            textures[Texture::PLAYER] = window::loadTexture(app->renderer, PLAYER_TEXTURE_PATH);
            textures[Texture::FIREBALL] = window::loadTexture(app->renderer, FIREBALL_TEXTURE_PATH);
    };

    Player *createPlayer();
    Fireball *createFireball(int x, int y);
private:
    window::App *app;

    SDL_Texture *textures[2];
};


#endif //SDL2_DEMO_ENTITYFACTORY_H
