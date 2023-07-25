//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#ifndef SDL2_DEMO_GAME_H
#define SDL2_DEMO_GAME_H

#include <SDL_render.h>
#include <SDL_events.h>
#include "window.h"

class Game {
public:
    Game(const char* title): title(title) {};

    void init();
    void exit();

    bool run();
private:
    const char* title;
    window::App *app;
    SDL_Rect player;

    bool isRunning = true;

    void doInput();

    void update();

    void render();

    void onKeyDown(SDL_KeyboardEvent *event);
};


#endif //SDL2_DEMO_GAME_H
