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
    Uint32 startTime = SDL_GetTicks();
    double fps = 0.0;

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

    bool isRunning = true;

    FrameRate frameRate;

    void doInput();

    void update();

    void render();
};

#endif //SDL2_DEMO_GAME_H
