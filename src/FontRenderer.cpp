//
// Created by Evgenii Shchepotev on 20.10.2023.
//

#include "SDL.h"
#include "SDL_ttf.h"
#include "FontRenderer.h"
#include <string>

FontRenderer::FontRenderer(SDL_Renderer& renderer) {
    /* Initialize the TTF library */
    if (TTF_Init() < 0) {
        SDL_Log("Couldn't initialize TTF: %s\n", SDL_GetError());
        SDL_Quit();
        exit(2);
    }

    font = TTF_OpenFont(FONT_PATH, DEFAULT_FONT_SIZE);
    if (font == nullptr) {
        SDL_Log("Couldn't load %d pt font from %s: %s\n",
                DEFAULT_FONT_SIZE, FONT_PATH, SDL_GetError());
        SDL_Quit();
        // Handle font loading error
        exit(2);
    }

    this->renderer = &renderer;
}

FontRenderer::~FontRenderer() {
    TTF_CloseFont(font);
    TTF_Quit();
}

void FontRenderer::renderText(const std::string &text, int x, int y) {
    SDL_Color color = {255, 255, 255}; // White text color
    SDL_Surface* surface = TTF_RenderText_Solid(this->font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = {x, y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
