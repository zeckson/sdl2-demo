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

    if (world.getPlayer()->state == State::DEAD) {
        isRunning = false;
    }
}

void Game::render() {
    auto *renderer = const_cast<SDL_Renderer *>(&app.renderer);

    SDL_SetRenderDrawColor(renderer, 0, 122, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (const auto entity: world.entities) {
        entity->render(renderer);
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
    std::string fpsText = "FPS: " + std::to_string(static_cast<int>(fps));
    app.fontRenderer->renderText(fpsText, 10, 10);
}


bool Game::run() {
    const auto start = SDL_GetTicks64();

    doInput();
    update();
    render();

    const auto end = SDL_GetTicks64();

    const auto duration = static_cast<Sint64>(end - start);

    Sint64 delay = RENDER_DELAY - duration;
    delay = delay > 0 ? delay : 1;

    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Update delay: %lldms", delay);

    SDL_Delay(delay);

    return isRunning;
}

void Game::exit() {
    delete &app;
}

Game::Game(App &app) : app(app), world(app) {
}
