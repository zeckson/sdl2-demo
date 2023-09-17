//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#include <SDL.h>
#include <SDL_events.h>
#include "Game.h"
#include "entity/Entity.h"

void Game::doInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // Handle each specific event
        if (event.type == SDL_KEYDOWN) {
            SDL_Keysym &keysym = event.key.keysym;

            if (lastKeyDown == keysym.scancode) {
                break;
            }
            lastKeyDown = keysym.scancode;

            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                           "Keydown code: %u", keysym.scancode);
            if (keysym.scancode == SDL_SCANCODE_ESCAPE) {
                isRunning = false;
            }
            for (const auto entity: world.entities) {
                entity->onKeyDown(keysym);
            }
        }
        if (event.type == SDL_KEYUP) {
            lastKeyDown = SDL_SCANCODE_UNKNOWN;

            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                           "Keyup code: %u", event.key.keysym.scancode);
            for (const auto entity: world.entities) {
                entity->onKeyUp(event.key.keysym);
            }
        }
    }
}

void Game::update() {
    world.update();
}

void Game::render() {
    auto *renderer = const_cast<SDL_Renderer *>(&app.renderer);

    SDL_SetRenderDrawColor(renderer, 0, 122, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (const auto entity: world.entities) {
        entity->render(renderer);
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(RENDER_DELAY);
}

bool Game::run() {
    const auto start = std::chrono::steady_clock::now();

    doInput();
    update();
    render();

    const auto end = std::chrono::steady_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds >(end - start);

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE,
                   "Update time %lld ms", duration.count());

    return isRunning;
}

void Game::exit() {
    delete &app;
}

Game::Game(App &app) : app(app), world(app) {
}
