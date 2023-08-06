//
// Created by Evgenii Shchepotev on 01.08.2023.
//

#include "EntityFactory.h"
#include "Player.h"
#include "Fireball.h"

Player *EntityFactory::createPlayer() {
    return new Player(*textures[Texture::PLAYER], app.width/2, app.height/2);
}

Fireball *EntityFactory::createFireball(int x, int y) {
    return new Fireball(*textures[Texture::FIREBALL], x, y);
}
