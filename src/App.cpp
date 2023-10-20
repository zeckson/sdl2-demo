//
// Created by Evgenii Shchepotev on 04.08.2023.
//

#include "App.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "defs.h"
#include "FontRenderer.h"


App &App::init(const char *title, const int width, const int height) {
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

    // Loading textures
    // Init img support
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    const auto pApp = new App(*sdlWindow, *sdlRenderer, width, height);

    return *pApp;
}


void cleanup(App &app) {
    SDL_DestroyWindow(&app.window);
    SDL_DestroyRenderer(&app.renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
}

App::~App() {
    cleanup(*this);
}

SDL_Surface *App::loadSurface(const char *filename) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading surface %s", filename);

    SDL_Surface *pSurface = IMG_Load(filename);

    if (!pSurface) {
        printf("Failed to load surface [%s] renderer: %s\n", filename, SDL_GetError());
    }

    return pSurface;
}

SDL_Texture &App::loadTexture(const char *filename) {
    SDL_Surface *pSurface = loadSurface(filename);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(&this->renderer, pSurface);

    SDL_FreeSurface(pSurface); // why surface wasn't allocated?

    if (!texture) {
        printf("Failed to load texture [%s] renderer: %s\n", filename, SDL_GetError());
    }

    return *texture;
}

App::App(SDL_Window &window, SDL_Renderer &renderer, int width, int height) :
        window(window), renderer(renderer), width(width), height(height) {
    fontRenderer = new FontRenderer(renderer);
}

void FrameRate::render(App &app) {
    frameCount++;
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - startTime >= 1000) {
        double fps = frameCount / ((currentTime - startTime) / 1000.0);
        std::string fpsText = "FPS: " + std::to_string(static_cast<int>(fps));

        // Render frame rate on the screen
        app.fontRenderer->renderText(fpsText, 10, 10);

        // Reset frame rate counters
        startTime = currentTime;
        frameCount = 0;
    }
}
