//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#ifndef SDL2_DEMO_WORLD_H
#define SDL2_DEMO_WORLD_H

#include <list>
#include "SDL.h"
#include "entity/EntityFactory.h"

class Entity;

class World {
public:
    explicit World(App &app) : width(app.width), height(app.height), factory(*(new EntityFactory(app))) {
        player = reinterpret_cast<Entity *>(factory.createPlayer());
        entities.push_back(player);
    };

    Entity* getPlayer() {
        return player;
    };

    int width;
    int height;

    std::list<Entity*> entities{};
    std::list<Entity*> enemies{};
    EntityFactory &factory;

    void update();

private:
    Entity* player;
};

#endif //SDL2_DEMO_WORLD_H
