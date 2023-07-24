//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#ifndef SDL2_DEMO_GAME_H
#define SDL2_DEMO_GAME_H

#include <SDL_render.h>
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

    bool upArrowDown = false;
    bool leftArrowDown = false;
    bool downArrowDown = false;
    bool rightArrowDown = false;

    bool isRunning = true;

    void doInput();


    void update();

    void render();
};


#endif //SDL2_DEMO_GAME_H
