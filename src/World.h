//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#ifndef SDL2_DEMO_WORLD_H
#define SDL2_DEMO_WORLD_H

#include <list>
#include "SDL.h"
#include "window.h"

template<class T>
class World {
public:
    World(window::App *app) : width(app->width), height(app->height) {};

    int width;
    int height;

    std::list<T> entities{};
};

#endif //SDL2_DEMO_WORLD_H
