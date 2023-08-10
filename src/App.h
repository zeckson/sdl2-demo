//
// Created by Evgenii Shchepotev on 04.08.2023.
//

#ifndef SDL2_DEMO_APP_H
#define SDL2_DEMO_APP_H


#include <SDL_system.h>

class App {
public:
    virtual ~App();

    SDL_Window &window;
    SDL_Renderer &renderer;

    int width;
    int height;

    SDL_Texture &loadTexture(const char *filename);

    static App& init(const char *title, int width, int height);
private:
    explicit App(SDL_Window &window, SDL_Renderer &renderer, int width, int height) :
            window(window), renderer(renderer), width(width), height(height) {};
};


#endif //SDL2_DEMO_APP_H
