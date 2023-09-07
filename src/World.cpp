//
// Created by Evgenii Shchepotev on 10.08.2023.
//
#include "World.h"
#include "entity/Entity.h"

void World::update() {
    std::list<Entity*> removed;
    auto &myEntities = this->entities;
    for (const auto entity: myEntities) {
        if (entity->update(*this)) {
            removed.push_back(entity);
        }
    }
    for (const auto entity: removed) {
        myEntities.remove(entity);
        delete entity;
    }

}

