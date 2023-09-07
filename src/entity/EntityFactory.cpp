//
// Created by Evgenii Shchepotev on 01.08.2023.
//

#include "Player.h"
#include "Fireball.h"
#include "Enemy.h"
#include "EntityFactory.h"

Player *EntityFactory::createPlayer() {
    return new Player(*textures[Texture::PLAYER], app.width/2, app.height/2);
}

Fireball *EntityFactory::createFireball(int x, int y) {
    return new Fireball(*textures[Texture::FIREBALL], x, y);
}

Enemy *EntityFactory::createEnemy(int x, int y) {
    return new Enemy(*textures[Texture::PLAYER], x, y);
}