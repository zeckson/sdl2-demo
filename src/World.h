//
// Created by Evgenii Shchepotev on 31.07.2023.
//

#ifndef SDL2_DEMO_WORLD_H
#define SDL2_DEMO_WORLD_H

#include <list>
#include "SDL.h"
#include "entity/EntityFactory.h"
#include "Action.h"

class Entity;

class World: public Subject {
public:
    explicit World(App &app) : factory(*(new EntityFactory(app))), app(app) {
        this->restart();
    };

    Entity* getPlayer() {
        return player;
    };

    const int &width() { return app.width; };
    const int &height() { return app.height; };

    std::list<Entity*> entities{};
    std::list<Entity*> enemies{};
    EntityFactory &factory;

    void update();

    void handleEvent(const SDL_Event &event);

    void render(SDL_Renderer *pRenderer);

    void restart();

    bool isDead();

private:
    Entity* player;
    App& app;
    SDL_Scancode lastKeyDown = SDL_SCANCODE_UNKNOWN;
};

#endif //SDL2_DEMO_WORLD_H
