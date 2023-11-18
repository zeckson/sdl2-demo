//
// Created by Evgenii Shchepotev on 10.08.2023.
//

#include "Enemy.h"

bool Enemy::update(World &world) {
    int velocity = yVel;

    rect.y += velocity;

    Entity *player = world.getPlayer();
    if (SDL_HasIntersection(&player->rect, &this->rect)) {
        player->state = State::DEAD;
    }

    return rect.y > world.height();
}

void Enemy::onKeyDown(const SDL_Keysym &key) {
    Entity::onKeyDown(key);
}

void Enemy::onKeyUp(const SDL_Keysym &key) {
    Entity::onKeyUp(key);
}
