//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#include <SDL.h>
#include <SDL_events.h>
#include "Game.h"
#include "entity/Entity.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void Game::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        if (menu.isActive()) {
            menu.handleEvent(event);
        } else {
            world.handleEvent(event);
        }
    }
}

void Game::update() {
    if (!menu.isActive()) {
        world.update();
    }
}

void Game::render() {
    auto *renderer = const_cast<SDL_Renderer *>(&app.renderer);

    SDL_SetRenderDrawColor(renderer, 0, 122, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    world.render(renderer);
    if (menu.isActive()) {
        menu.render(renderer);
    }

    frameRate.render(app);

    SDL_RenderPresent(renderer);
}

void FrameRate::render(const App &app) {
    frameCount++;
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - startTime >= 1000) {
        fps = frameCount / ((currentTime - startTime) / 1000.0);

        // Reset frame rate counters
        startTime = currentTime;
        frameCount = 0;
    }

    // Render frame rate on the screen
    std::stringstream formatted;
    formatted << "FPS: " << std::fixed << std::setprecision(2) << fps;

    std::string fpsText = formatted.str();
    app.fontRenderer->renderText(fpsText, 10, 10);
}


bool Game::run() {
    const auto start = SDL_GetTicks64();

    input();
    update();
    render();

    const auto end = SDL_GetTicks64();

    const auto duration = static_cast<Sint64>(end - start);

    Sint64 delay = RENDER_DELAY - duration;
    delay = delay > 0 ? delay : 1;

    SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, "Update delay: %lldms", delay);

    // BC! We use vertical sync in render options
    //    SDL_Delay(delay);

    return isRunning;
}

void Game::exit() {
    delete &app;
}

void Game::performAction(Action action) {
    switch (action) {
        case Action::PAUSE:
            menu.setActive(true);
            break;
        case Action::RESUME:
            menu.setActive(false);
            break;
        case Action::QUIT:
            isRunning = false;
            break;
        case Action::RESTART:
//            world.restart();
            break;
        default:
            printf("Unknonw action recieved");
    }
}

Game::Game(App &app) : app(app), world(app), menu(&app) {
    menu.addListener(this);
    world.addListener(this);
}
