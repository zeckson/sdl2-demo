//
// Created by Evgenii Shchepotev on 23.07.2023.
//

#ifndef SDL2_DEMO_WINDOW_H
#define SDL2_DEMO_WINDOW_H

#include "defs.h"

namespace window {
    typedef struct {
        SDL_Window *window;
        SDL_Renderer *renderer;

        int width;
        int height;
    } App;

    App *init(const char *title, int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);

    void cleanup(App *app);
}

#endif //SDL2_DEMO_WINDOW_H
