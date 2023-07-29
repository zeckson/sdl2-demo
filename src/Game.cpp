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

    player.update();

    //bounds checking and correction
    auto rect = player.rect;

    if (rect.x < 0) {
        rect.x = 0;
    } else if (rect.x + rect.w - 1 >= app->width) {
        rect.x = app->width - rect.w;
    }
    if (rect.y < 0) {
        rect.y = 0;
    } else if (rect.y + rect.h - 1 >= app->height) {
        rect.y = app->height - rect.h;
    }
}

void Game::render() {
    SDL_Renderer *renderer = app->renderer;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 105, 180, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &player.rect);
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


