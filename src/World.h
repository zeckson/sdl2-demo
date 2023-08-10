//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#ifndef SDL2_DEMO_WORLD_H
#define SDL2_DEMO_WORLD_H

#include <list>
#include "SDL.h"
#include "EntityFactory.h"

template<class T>
class World {
public:
    explicit World(App &app) : width(app.width), height(app.height), factory(*(new EntityFactory(app))) {
        player = factory.createPlayer();
        entities.push_back(player);
    };

    T getPlayer();

    int width;
    int height;

    std::list<T> entities{};
    EntityFactory &factory;
private:
    T player;
};

template<class T>
T World<T>::getPlayer() {
    return player;
}

#endif //SDL2_DEMO_WORLD_H
