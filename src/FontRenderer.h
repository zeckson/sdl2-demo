//
// Created by Evgenii Shchepotev on 20.10.2023.
//

#ifndef SDL2_DEMO_FONTRENDERER_H
#define SDL2_DEMO_FONTRENDERER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include "defs.h"

class FontRenderer {
public:
    explicit FontRenderer(SDL_Renderer& renderer);

    ~FontRenderer();

    void renderText(const std::string& text, int x, int y);

private:
    SDL_Renderer* renderer{};
    TTF_Font* font;
};


#endif //SDL2_DEMO_FONTRENDERER_H
