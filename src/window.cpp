//
// Created by Evgenii Shchepotev on 23.07.2023.
//

#include "SDL.h"
#include <iostream>
#include "window.h"

window::App *window::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    } else {
        std::cout << "SDL video system is ready to go\n";
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // Create an application window with the following settings:
    SDL_Window *sdlWindow = SDL_CreateWindow(
            title,        // window title
            SDL_WINDOWPOS_UNDEFINED, // initial x position
            SDL_WINDOWPOS_UNDEFINED, // initial y position
            width,                     // width, in pixels
            height,                     // height, in pixels
            SDL_WINDOW_SHOWN         // flags - see below
    );

    // Check that the window was successfully created
    if (!sdlWindow) {
        // In the case that the window could not be made...
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1,
                                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!sdlRenderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    static window::App app = {sdlWindow, sdlRenderer, width, height};

    return &app;
}

void window::cleanup(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
};
