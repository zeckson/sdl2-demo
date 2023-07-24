//
// Created by Evgenii Shchepotev on 24.07.2023.
//

#include <SDL.h>
#include <SDL_events.h>
#include "Game.h"
#include "window.h"

void Game::init() {
    app = window::init(title, SCREEN_WIDTH, SCREEN_HEIGHT);

    int w = app->width;
    int h = app->height;

    player.w = w / 30;
    player.h = h / 10;
    player.x = w / 2 - player.w / 2;
    player.y = h / 2 - player.h / 2;
}


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

    int numPixelsToMovePerFrame = player.w / 4;

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    //move player
    if (state[SDL_SCANCODE_UP]) {
        player.y -= numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        player.y += numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        player.x -= numPixelsToMovePerFrame;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        player.x += numPixelsToMovePerFrame;
    }

    //bounds checking and correction
    if (player.x < 0) {
        player.x = 0;
    } else if (player.x + player.w - 1 >= app->width) {
        player.x = app->width - player.w;
    }
    if (player.y < 0) {
        player.y = 0;
    } else if (player.y + player.h - 1 >= app->height) {
        player.y = app->height - player.h;
    }
}

void Game::render() {
    SDL_Renderer *renderer = app->renderer;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 105, 180, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &player);
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


