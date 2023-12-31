//
// Created by Evgenii Shchepotev on 01.08.2023.
//

#ifndef SDL2_DEMO_ENTITYFACTORY_H
#define SDL2_DEMO_ENTITYFACTORY_H

#include "SDL.h"
#include "../App.h"
#include "../defs.h"

// Forward declaration
class Player;

class Fireball;

class Enemy;

class EntityFactory {
public:
    explicit EntityFactory(App &app) {
        textures[Texture::PLAYER] = &app.loadTexture(PLAYER_TEXTURE_PATH);
        textures[Texture::ENEMY] = &app.loadTexture(ENEMY_TEXTURE_PATH);
        textures[Texture::FIREBALL] = &app.loadTexture(FIREBALL_TEXTURE_PATH);
    };

    Player *createPlayer(int x, int y);

    Fireball *createFireball(int x, int y);

    Enemy *createEnemy(int x, int y);

private:
    SDL_Texture *textures[3]{};

};


#endif //SDL2_DEMO_ENTITYFACTORY_H
