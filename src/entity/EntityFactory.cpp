//
// Created by Evgenii Shchepotev on 01.08.2023.
//

#include "Player.h"
#include "Fireball.h"
#include "Enemy.h"
#include "EntityFactory.h"

Player *EntityFactory::createPlayer(int x, int y) {
    return new Player(*textures[Texture::PLAYER], x, y);
}

Fireball *EntityFactory::createFireball(int x, int y) {
    return new Fireball(*textures[Texture::FIREBALL], x, y);
}

Enemy *EntityFactory::createEnemy(int x, int y) {
    return new Enemy(*textures[Texture::ENEMY], x, y);
}