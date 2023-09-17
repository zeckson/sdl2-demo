//
// Created by Evgenii Shchepotev on 10.08.2023.
//
#include "World.h"
#include "entity/Entity.h"

void World::update() {
    int rnd = std::rand();
    int maxEnemies = this->width / PLAYER_WIDTH;

    if (this->enemies.size() < maxEnemies && (rnd % 10 == 0)) {

        int x = rnd % maxEnemies * PLAYER_WIDTH + PLAYER_WIDTH / 2;
        int y = PLAYER_HEIGHT / 2;

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                       "Spawning enemy at [%d, %d]", x, y);

        auto *pEnemy = reinterpret_cast<Entity *>(factory.createEnemy(x, y));
        this->entities.push_back(pEnemy);
        this->enemies.push_back(pEnemy);
    }

    std::list<Entity *> removed;
    auto &myEntities = this->entities;
    for (const auto entity: myEntities) {
        if (entity->update(*this)) {
            entity->state = State::DEAD;
        }
    }
    for (const auto entity: myEntities) {
        if (entity->state == State::DEAD) {
            removed.push_back(entity);
        }
    }
    for (const auto entity: removed) {
        this->entities.remove(entity);
        this->enemies.remove(entity);
        delete entity;
    }

}

