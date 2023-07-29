//
// Created by Evgenii Shchepotev on 25.07.2023.
//

#ifndef SDL2_DEMO_ENTITY_H
#define SDL2_DEMO_ENTITY_H

class Entity {
public:
    Entity(short width, short height, int x, int y) :
            rect{x, y, width, height} {};

    SDL_Rect rect;

    virtual void update() = 0;
};


#endif //SDL2_DEMO_ENTITY_H
