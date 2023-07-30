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
            onKeyDown(&event.key);
        }
    }
}

void Game::onKeyDown(SDL_KeyboardEvent *event) {
    if (event->keysym.scancode == SDL_SCANCODE_ESCAPE) {
        isRunning = false;
    }
};

void Game::update() {

    for (const auto entity: world.entities) {
        entity->update(&world);
    }
}

void Game::render() {
    SDL_Renderer *renderer = app->renderer;

    SDL_SetRenderDrawColor(renderer, 0, 122, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (const auto entity: world.entities) {
        entity->render(renderer);
    }

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
