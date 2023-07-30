//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#ifndef SDL2_DEMO_GAME_H
#define SDL2_DEMO_GAME_H

#include <SDL_render.h>
#include <SDL_events.h>
#include "window.h"
#include "Player.h"

class Game {
public:
    explicit Game(window::App *app) : app(app),
                                      world(app->width, app->height),
                                      player(app->width / 2, app->height / 2) {
        world.entities.push_back(&player);
    };

    void exit();

    bool run();

private:
    window::App *app;
    World<Entity*> world;
    Player player;

    bool isRunning = true;

    void doInput();

    void update();

    void render();

    void onKeyDown(SDL_KeyboardEvent *event);
};


#endif //SDL2_DEMO_GAME_H
