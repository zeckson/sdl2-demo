//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#include <SDL.h>
#include <SDL_events.h>
#include "Game.h"
#include "window.h"

void Game::doInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // Handle each specific event
        if (event.type == SDL_KEYDOWN) {
            SDL_Keysym &keysym = event.key.keysym;

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
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                           "Keyup code: %u", event.key.keysym.scancode);
            for (const auto entity: world.entities) {
                entity->onKeyUp(event.key.keysym);
            }
        }
    }
}

void Game::update() {

    for (const auto entity: world.entities) {
        entity->update(&world);
    }
}

void Game::render() {
    SDL_Renderer *renderer = app->renderer;
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 122, 0, SDL_ALPHA_OPAQUE);

    for (const auto entity: world.entities) {
        entity->render(renderer);
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(RENDER_DELAY);
}

bool Game::run() {
    doInput();
    update();
    render();
    return isRunning;
}

void Game::exit() {
    window::cleanup(app);
}
