//
// Created by Evgenii Shchepotev on 10.08.2023.
//

#include "Enemy.h"

bool Enemy::update(World &world) {
    return false;
}

void Enemy::onKeyDown(const SDL_Keysym &key) {
    Entity::onKeyDown(key);
}

void Enemy::onKeyUp(const SDL_Keysym &key) {
    Entity::onKeyUp(key);
}
