//
// Created by Evgenii Shchepotev on 04.08.2023.
//

#ifndef SDL2_DEMO_APP_H
#define SDL2_DEMO_APP_H


#include <SDL_system.h>

class App {
public:
    virtual ~App();

    const SDL_Window &window;
    const SDL_Renderer &renderer;

    int width;
    int height;

    SDL_Texture &loadTexture(const char *filename);

    static App& init(const char *title, const int width, const int height);
private:
    App(const SDL_Window &window, const SDL_Renderer &renderer, int width, int height) :
            window(window), renderer(renderer), width(width), height(height) {};
};


#endif //SDL2_DEMO_APP_H
