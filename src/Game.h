//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#ifndef SDL2_DEMO_GAME_H
#define SDL2_DEMO_GAME_H

#include <SDL_render.h>
#include <SDL_events.h>
#include "World.h"

struct FrameRate {
    int frameCount = 0;
    int startTime = SDL_GetTicks();
    double fps;

    void render(const App &app);
};

class Game {
public:
    explicit Game(App &app);

    void exit();

    bool run();

private:
    App &app;
    World world;

    SDL_Scancode lastKeyDown = SDL_SCANCODE_UNKNOWN;

    bool isRunning = true;

    FrameRate frameRate;

    void doInput();

    void update();

    void render();
};

#endif //SDL2_DEMO_GAME_H
