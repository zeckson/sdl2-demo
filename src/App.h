//
// Created by Evgenii Shchepotev on 04.08.2023.
//

#ifndef SDL2_DEMO_APP_H
#define SDL2_DEMO_APP_H


#include <SDL_system.h>
#include <string>
#include "SDL_ttf.h"
#include "FontRenderer.h"

class App {
public:
    virtual ~App();

    SDL_Window &window;
    SDL_Renderer &renderer;
    FontRenderer *fontRenderer{};

    int width{};
    int height{};

    SDL_Texture &loadTexture(const char *filename);

    static App& init(const char *title, int width, int height);
    static SDL_Surface* loadSurface(const char *filename);
private:
    explicit App(SDL_Window &window, SDL_Renderer &renderer, int width, int height);

};

struct FrameRate {
    int frameCount = 0;
    int startTime = SDL_GetTicks();
    void render(App &app);
};


#endif //SDL2_DEMO_APP_H
